"""
Spider — a CLI tool that crawls a web page and downloads images.
 
Usage:
    python spider.py <url> [-r] [-l <depth>] [-p <output_dir>]
 
Options:
    -r              Enable recursive crawling
    -l <depth>      Maximum recursion depth (default: 5)
    -p <output_dir> Directory to save downloaded images (default: ./data)
"""


import argparse
import re
import os
import sys
import requests

from bs4 import BeautifulSoup
from dataclasses import dataclass
from enum import Enum, IntEnum
from urllib.parse import urljoin, urlparse

TARGET_EXTENSIONS = {'.jpg', '.jpeg', '.png', '.gif', '.bmp'}
LAZY_ATTRIBUTES = {"src", "data-src", "data-original", "data-lazy", "data-url"}
REQUEST_TIMEOUT = 10


class Color(str, Enum):
    """ANSI color codes for terminal output"""

    def __str__(self) -> str:
        return self.value

    RESET = "\033[0m"
    RED = "\033[31m"
    GREEN = "\033[32m"
    YELLOW = "\033[33m"
    CYAN = "\033[36m"


class ExitCode(IntEnum):
    """Exit codes for the spider application"""

    def __int__(self) -> int:
        return self.value

    OK = 0
    RUNTIME_ERROR = 1
    INVALID_ARGS = 2
    FILESYSTEM_ERROR = 3
    SIGINT = 130


# =============== Errors

class SpiderError(Exception):
    """Base class for all spider errors"""

    def __init__(self, message: str, context: str = None) -> None:
        self.context = context
        full_message = f"{message} (context: {context})" if context else message
        super().__init__(full_message)


class ValidationError(SpiderError):
    """Raised when input validation fails (bad URL, invalid depth, etc.)"""

    def __init__(self, field: str, value, reason: str) -> None:
        self.field = field
        self.value = value
        self.reason = reason
        super().__init__(f"Invalid value for '{field}': {value!r} — {reason}")


class FileSystemError(SpiderError):
    """Raised when a filesystem operation fails"""

    def __init__(self, message: str, path: str = None) -> None:
        self.path = path
        super().__init__(message, context=path)


class NetworkError(SpiderError):
    """Raised when a network request fails (non-recoverable)"""

    def __init__(self, url: str, reason: str) -> None:
        self.url = url
        self.reason = reason
        super().__init__(f"Network error for '{url}': {reason}")


# Data model

@dataclass(frozen=True)
class Config:
    """Immutable configuration for the spider"""
    url: str
    recursive: bool
    depth_level: int
    output_directory: str


class Spider:
    """Spider class to crawl web pages and download images based on the given configuration"""

    def __init__(self, config: Config) -> None:
        """Initialize the spider with the given configuration"""
        self.config = config
        self.visited = set()
        self.downloaded = set()

    def run(self: 'Spider') -> None:
        """Run the spider with the given configuration"""
        self._print_config()
        self._crawl(self.config.url)
        self._print_summary()

    def _print_config(self) -> None:
        """Print the spider configuration"""
        print(f"\n{Color.CYAN}" + "*" * 50)
        print("Running spider with the following configuration:")
        print(f"  - target url: {self.config.url}")
        print(f"  - recursive: {self.config.recursive}")
        if self.config.recursive:
            print(f"  - depth level: {self.config.depth_level}")
        print(f"  - output directory: {self.config.output_directory}")
        print("*" * 50 + f"\n{Color.RESET}")

    def _print_summary(self) -> None:
        """Print the crawling summary"""
        print(f"\n{Color.CYAN}" + "=" * 50)
        print("Mission completed!")
        print("Summary:")
        print(f"  - visited urls: {len(self.visited)}")
        print(f"  - downloaded images: {len(self.downloaded)}")
        print(f"  - check '{self.config.output_directory}' for results")
        print("=" * 50 + f"\n{Color.RESET}")

    def _crawl(self, base_url, depth=0) -> None:
        """Crawl the given URL, extract images, and optionally recurse into links"""
        if depth > self.config.depth_level or base_url in self.visited:
            return

        self.visited.add(base_url)
        print(f"Crawling: {base_url} (depth: {depth})")

        try:
            response = requests.get(base_url, timeout=REQUEST_TIMEOUT)
            response.raise_for_status()
            html = response.text

            image_urls = self._extract_image_urls(html, base_url)

            print(f"Found {len(image_urls)} image(s) at {base_url}")
            if image_urls:
                print("List of image URLs:")
                for img_url in image_urls:
                    print(f"\t- {img_url}")

            for img_url in image_urls:
                self._download_image(img_url)

            if self.config.recursive and depth < self.config.depth_level:
                links_to_crawl = self._extract_links(html, base_url)
                print(
                    f"Found {len(links_to_crawl)} link(s) to crawl at {base_url}")
                if links_to_crawl:
                    print("List of links to crawl:")
                    for link in links_to_crawl:
                        print(f"\t- {link}")
                for link in links_to_crawl:
                    self._crawl(link, depth + 1)

        except requests.exceptions.RequestException as e:
            print(
                f"{Color.RED}Failed to fetch '{base_url}': {e}{Color.RESET}",
                file=sys.stderr,
            )

        except (ValueError, TypeError) as e:
            print(
                f"{Color.RED}Failed to parse '{base_url}': {e}{Color.RESET}",
                file=sys.stderr,
            )

    def _extract_image_urls(self, html, base_url) -> set:
        """Extract image URLs from HTML content"""
        soup = BeautifulSoup(html, 'html.parser')
        image_urls = set()

        def _is_valid_image_url(url):
            path = urlparse(url).path.lower()
            return any(path.endswith(ext) for ext in TARGET_EXTENSIONS)

        def _add_image_url(url):
            if not url:
                return
            full_url = urljoin(base_url, url)
            if _is_valid_image_url(full_url):
                image_urls.add(full_url)

        def _extract_srcset_urls(srcset_attr):
            if srcset_attr:
                for src_item in srcset_attr.split(','):
                    parts = src_item.strip().split()
                    if parts:
                        _add_image_url(parts[0])

        # Standard images
        for img in soup.find_all('img'):
            for attr in LAZY_ATTRIBUTES:
                _add_image_url(img.get(attr))
            _extract_srcset_urls(img.get('srcset') or img.get('data-srcset'))

        # Responsive images
        for source in soup.find_all('source'):
            _extract_srcset_urls(source.get('srcset')
                                 or source.get('data-srcset'))

        # Video thumbnails
        for video in soup.find_all('video'):
            _add_image_url(video.get('poster'))

        # Site icons
        for link in soup.find_all('link'):
            rel = link.get('rel')
            if rel and any(r in ['icon', 'apple-touch-icon'] for r in rel):
                _add_image_url(link.get('href'))

        # Social media images
        for meta in soup.find_all('meta'):
            if meta.get('property') in ['og:image', 'twitter:image']:
                _add_image_url(meta.get('content'))

        # SVG images
        for svg_img in soup.find_all('image'):
            _add_image_url(svg_img.get('href') or svg_img.get('xlink:href'))

        # Background images in inline styles
        for tag in soup.find_all(style=True):
            matches = re.findall(r'url\((.*?)\)', tag.get('style'))
            for match in matches:
                _add_image_url(match.strip('\'"'))

        # Direct image links
        for a in soup.find_all('a'):
            _add_image_url(a.get('href'))

        return image_urls

    def _download_image(self, img_url) -> None:
        """Download image from URL and save to output directory"""
        if img_url in self.downloaded:
            print(
                f"{Color.YELLOW}Download: '{img_url}' -> already downloaded{Color.RESET}")
            return

        try:
            response = requests.get(
                img_url, stream=True, timeout=REQUEST_TIMEOUT)
            response.raise_for_status()

            filename = os.path.basename(urlparse(img_url).path)
            if not filename:
                # URL has no path component — derive a safe name from the URL
                filename = re.sub(r'[^\w]', '_', img_url)[-64:]

            output_path = os.path.join(self.config.output_directory, filename)
            index = 1
            while os.path.exists(output_path):
                name, ext = os.path.splitext(filename)
                output_path = os.path.join(
                    self.config.output_directory, f"{name}_{index}{ext}"
                )
                index += 1

            with open(output_path, 'wb') as f:
                f.write(response.content)

            self.downloaded.add(img_url)
            print(f"{Color.GREEN}Download: '{img_url}' -> {output_path}{Color.RESET}")

        except requests.exceptions.HTTPError as e:
            print(
                f"{Color.RED}Download: '{img_url}' -> HTTP {e.response.status_code}{Color.RESET}",
                file=sys.stderr,
            )

        except requests.exceptions.ConnectionError:
            print(
                f"{Color.RED}Download: '{img_url}' -> connection error{Color.RESET}",
                file=sys.stderr,
            )

        except requests.exceptions.Timeout:
            print(
                f"{Color.RED}Download: '{img_url}' -> timed out{Color.RESET}",
                file=sys.stderr,
            )

        except requests.exceptions.RequestException as e:
            print(
                f"{Color.RED}Download: '{img_url}' -> request failed: {e}{Color.RESET}",
                file=sys.stderr,
            )

        except OSError as e:
            print(
                f"{Color.RED}Download: '{img_url}' -> could not write file: {e}{Color.RESET}",
                file=sys.stderr,
            )

    def _extract_links(self, html, base_url) -> set:
        """Extract valid same-domain links from HTML content"""
        soup = BeautifulSoup(html, 'html.parser')
        base_domain = urlparse(base_url).netloc
        links = set()

        for a in soup.find_all('a', href=True):
            href = a['href']
            if href.startswith(('javascript:', '#', 'mailto:')):
                continue
            absolute_url = urljoin(base_url, href)
            parsed_url = urlparse(absolute_url)
            if parsed_url.netloc == base_domain:
                clean_url = parsed_url._replace(fragment='').geturl()
                links.add(clean_url)

        return links


# =============== Validation

def valid_url(url: str) -> str:
    """Validate that the URL is well-formed and uses http or https scheme"""
    parsed = urlparse(url)
    if parsed.scheme not in ("http", "https") or not parsed.netloc:
        raise ValidationError(
            field="url",
            value=url,
            reason="must be http(s) with a valid domain",
        )
    return url


def valid_depth_level(level) -> int:
    """Validate that the depth level is a non-negative integer"""
    try:
        value = int(level)
    except (ValueError, TypeError) as exc:
        raise ValidationError(
            field="depth_level",
            value=level,
            reason="must be an integer",
        ) from exc

    if value < 0:
        raise ValidationError(
            field="depth_level",
            value=level,
            reason="must be >= 0",
        )

    return value


def valid_path(path: str) -> str:
    """Validate that the path is writable (or can be created under a writable parent)"""
    abs_path = os.path.abspath(path)
    current = abs_path

    # Walk up until we find an existing ancestor
    while current and not os.path.exists(current):
        parent = os.path.dirname(current)
        if parent == current:
            # Reached filesystem root without finding an existing dir
            raise FileSystemError(
                "Cannot determine a writable parent directory", path=abs_path
            )
        current = parent

    if not os.access(current, os.W_OK):
        raise FileSystemError(f"'{current}' is not writable.", path=current)

    return path


# =============== Parsing

def parse_args(argv=None) -> argparse.Namespace:
    """Parse command-line arguments"""
    parser = argparse.ArgumentParser(description="Spider")
    parser.add_argument("url", help="URL to download images from")
    parser.add_argument(
        "-r", dest="recursive", action="store_true", help="Enable recursion"
    )
    parser.add_argument(
        "-l", dest="depth_level", default=5, help="Recursion level depth"
    )
    parser.add_argument(
        "-p", dest="output_directory", default="./data", help="Output directory"
    )
    return parser.parse_args(argv)


# =============== Build config

def build_config(args) -> Config:
    """Validate arguments and build configuration object"""
    url = valid_url(args.url)
    recursive = args.recursive
    depth_level = valid_depth_level(args.depth_level)
    output_directory = valid_path(args.output_directory)

    if not recursive:
        depth_level = 0
    elif depth_level == 0:
        recursive = False

    return Config(
        url=url,
        recursive=recursive,
        depth_level=depth_level,
        output_directory=output_directory,
    )


# =============== Execution

def ensure_output_directory(path: str) -> None:
    """Ensure that the output directory exists and is writable"""
    if os.path.exists(path) and not os.path.isdir(path):
        raise FileSystemError(
            f"'{path}' exists but is not a directory.", path=path)

    try:
        os.makedirs(path, exist_ok=True)
    except OSError as e:
        raise FileSystemError(str(e), path=path) from e


def main() -> int:
    """Entry point: parse args, build config, run the spider, return an exit code."""
    try:
        args = parse_args()
        config = build_config(args)
        ensure_output_directory(config.output_directory)
        Spider(config).run()
        return ExitCode.OK

    except KeyboardInterrupt:
        print(f"\n{Color.YELLOW}Interrupted by SIGINT{Color.RESET}")
        return ExitCode.SIGINT

    except ValidationError as e:
        print(f"{Color.RED}Validation error: {e}{Color.RESET}", file=sys.stderr)
        return ExitCode.INVALID_ARGS

    except FileSystemError as e:
        print(f"{Color.RED}Filesystem error: {e}{Color.RESET}", file=sys.stderr)
        return ExitCode.FILESYSTEM_ERROR

    except Exception as e:  # pylint: disable=broad-exception-caught
        # Last-resort catch: any unhandled runtime error (e.g. third-party library
        # raising an undocumented exception) must still produce a clean error message
        # and a non-zero exit code rather than an unformatted traceback.
        print(f"{Color.RED}Unexpected error: {e}{Color.RESET}", file=sys.stderr)
        return ExitCode.RUNTIME_ERROR


if __name__ == "__main__":
    sys.exit(main())
