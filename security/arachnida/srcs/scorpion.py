"""
Scorpion — a CLI tool to read and display metadata from image files.

Displays file information (name, path, size, timestamps), image properties
(format, dimensions, colour mode), and embedded EXIF data for each image.

Usage:
    python scorpion.py <file1> [file2 ...]

Supported formats: .jpg, .jpeg, .png, .gif, .bmp
"""

import sys
import argparse
import os
from dataclasses import dataclass
from datetime import datetime
from enum import Enum, IntEnum

from PIL import Image, UnidentifiedImageError
from PIL.ExifTags import TAGS


TARGET_EXTENSIONS = {'.jpg', '.jpeg', '.png', '.gif', '.bmp'}
TIME_STAMP_FORMAT = "%d-%m-%Y at %H:%M:%S"
LABEL_WIDTH = 16


# =============== Enums

class Color(str, Enum):
    """ANSI foreground color codes for terminal output."""

    def __str__(self) -> str:
        return self.value

    RESET = "\033[0m"
    BOLD = "\033[1m"
    BLACK = "\033[30m"
    RED = "\033[31m"
    GREEN = "\033[32m"
    YELLOW = "\033[33m"
    CYAN = "\033[36m"


class BgColor(str, Enum):
    """ANSI background color codes for terminal output."""

    def __str__(self) -> str:
        return self.value

    RESET = "\033[0m"
    BLACK = "\033[40m"
    RED = "\033[41m"
    GREEN = "\033[42m"
    YELLOW = "\033[43m"
    BLUE = "\033[44m"
    MAGENTA = "\033[45m"
    CYAN = "\033[46m"
    WHITE = "\033[47m"


class ExitCode(IntEnum):
    """Standard exit codes returned by main()."""

    def __int__(self) -> int:
        return self.value

    OK = 0
    RUNTIME_ERROR = 1
    INVALID_ARGS = 2
    FILESYSTEM_ERROR = 3
    SIGINT = 130


# =============== Errors

class ScorpionError(Exception):
    """Base class for all Scorpion errors."""

    def __init__(self, message: str, context: str = None) -> None:
        """Initialise with a human-readable message and an optional context string."""
        self.context = context
        full_message = f"{message} (context: {context})" if context else message
        super().__init__(full_message)


class ValidationError(ScorpionError):
    """Raised when user-supplied input fails validation."""

    def __init__(self, field: str, value, reason: str) -> None:
        """Initialise with the offending field name, its value, and a reason string."""
        self.field = field
        self.value = value
        self.reason = reason
        super().__init__(f"Invalid value for '{field}': {value!r} — {reason}")


class FileSystemError(ScorpionError):
    """Raised when a filesystem operation fails."""

    def __init__(self, message: str, path: str = None) -> None:
        """Initialise with an error message and the filesystem path that caused it."""
        self.path = path
        super().__init__(message, context=path)


class ImageReadError(ScorpionError):
    """Raised when an image file cannot be opened or decoded."""

    def __init__(self, path: str, reason: str) -> None:
        """Initialise with the image path and a description of why it could not be read."""
        self.path = path
        self.reason = reason
        super().__init__(f"Cannot read image '{path}': {reason}")


# =============== Data model

@dataclass(frozen=True)
class ScorpionConfig:
    """Immutable configuration passed to the Scorpion runner."""
    files: frozenset


# =============== Application

class Scorpion:
    """Reads and displays metadata for a collection of image files.

    For each file the runner prints:
    - File-level info  (name, path, size, timestamps)
    - Image properties (format, dimensions, colour mode)
    - Embedded EXIF data, when present
    """

    def __init__(self, config: ScorpionConfig) -> None:
        """Initialise the runner with the given configuration."""
        self.config = config

    def run(self) -> None:
        """Process every file in the configuration and print its metadata."""
        self._print_intro()
        self._process_files()
        self._print_summary()

    # ---- private helpers ----

    def _print_intro(self) -> None:
        """Print a startup banner listing the files that will be processed."""
        count = len(self.config.files)
        if count:
            print(f"{Color.YELLOW}\nFiles to process:{Color.RESET}")
            for i, file in enumerate(self.config.files, start=1):
                print(f"  - file {i}: {file}")
        else:
            print(f"{Color.YELLOW}\nNo files to process{Color.RESET}")

        print(f"{Color.GREEN}Processing {count} file(s)...{Color.RESET}")

    def _print_summary(self) -> None:
        """Print a completion message with the total number of files processed."""
        count = len(self.config.files)
        print(
            f"{Color.GREEN}\nProcessing complete. {count} file(s) processed.{Color.RESET}\n")

    def _process_files(self) -> None:
        """Iterate over all files, open each image, and print its metadata."""
        for file in self.config.files:
            print(f"{Color.BOLD}{Color.CYAN}\nProcessing file: {file}{Color.RESET}")
            print(f"{Color.CYAN}" + "-" * 60 + f"{Color.RESET}")
            try:
                with Image.open(file) as img:
                    self._print_file_info(img)
                    self._print_image_info(img)
                    self._print_exif_data(img)
            except UnidentifiedImageError as e:
                raise ImageReadError(
                    path=file, reason="unrecognised image format") from e
            except OSError as e:
                raise ImageReadError(path=file, reason=str(e)) from e

    def _print_file_info(self, img: Image.Image) -> None:
        """Print filesystem metadata (name, path, size, created, modified) for an image."""
        path = img.filename
        name = os.path.basename(path)
        size = os.path.getsize(path)
        stat = os.stat(path)
        created = datetime.fromtimestamp(
            stat.st_ctime).strftime(TIME_STAMP_FORMAT)
        modified = datetime.fromtimestamp(
            stat.st_mtime).strftime(TIME_STAMP_FORMAT)

        def _format_size(bytes_size: int) -> str:
            """Convert a byte count to a human-readable string (Mb / Kb / bytes)."""
            for unit, divisor in [("Mb", 1024 * 1024), ("Kb", 1024)]:
                if bytes_size > divisor:
                    return f"{bytes_size / divisor:.2f} {unit}"
            return f"{bytes_size} bytes"

        print(f"{Color.GREEN}File information:{Color.RESET}")
        print(f"  - {'name':<{LABEL_WIDTH}} {name}")
        print(f"  - {'path':<{LABEL_WIDTH}} {path}")
        print(f"  - {'size':<{LABEL_WIDTH}} {_format_size(size)}")
        print(f"  - {'created':<{LABEL_WIDTH}} {created}")
        print(f"  - {'modified':<{LABEL_WIDTH}} {modified}")

    def _print_image_info(self, img: Image.Image) -> None:
        """Print image properties (format, dimensions, colour mode)."""
        print(f"{Color.GREEN}Image information:{Color.RESET}")
        print(f"  - {'format':<{LABEL_WIDTH}} {img.format or 'Unknown'}")
        print(f"  - {'width':<{LABEL_WIDTH}} {img.width} pixels")
        print(f"  - {'height':<{LABEL_WIDTH}} {img.height} pixels")
        print(f"  - {'mode':<{LABEL_WIDTH}} {img.mode}")

    def _print_exif_data(self, img: Image.Image) -> None:
        """Print embedded EXIF tags, or a notice when none are present.

        Individual tags that cannot be encoded for the terminal are shown
        as '[unreadable]' rather than aborting the whole file.
        """
        try:
            exif_data = img.getexif()
        except (AttributeError, ValueError) as e:
            print(f"{Color.YELLOW}Could not read EXIF data: {e}{Color.RESET}")
            return

        if not exif_data:
            print(f"{Color.YELLOW}No EXIF data found{Color.RESET}")
            return

        print(f"{Color.GREEN}EXIF data:{Color.RESET}")
        for tag, value in exif_data.items():
            tag_name = TAGS.get(tag, tag)
            try:
                print(f"  - {tag_name:<{LABEL_WIDTH}} {value}")
            except (ValueError, UnicodeEncodeError):
                print(f"  - {tag_name:<{LABEL_WIDTH}} [unreadable]")


# =============== Validation

def _validate_file(path: str) -> str | None:
    """Validate a single file path and return it, or print an error and return None.

    Checks that the path exists, is a regular file, and has a supported extension.
    Returns the path on success, or None if any check fails.
    """
    if not os.path.exists(path):
        print(f"{Color.RED}  - File not found: {path}{Color.RESET}",
              file=sys.stderr)
        return None
    if not os.path.isfile(path):
        print(f"{Color.RED}  - Not a file: {path}{Color.RESET}", file=sys.stderr)
        return None
    if not any(path.lower().endswith(ext) for ext in TARGET_EXTENSIONS):
        print(
            f"{Color.RED}  - Unsupported file type: {path}{Color.RESET}", file=sys.stderr)
        return None
    return path


# =============== Parsing

def parse_args(argv=None) -> argparse.Namespace:
    """Parse command-line arguments and return the resulting namespace."""
    parser = argparse.ArgumentParser(
        description="Scorpion — image metadata reader")
    parser.add_argument(
        "files",
        nargs="+",
        metavar="FILE",
        help="Image files to process",
    )
    return parser.parse_args(argv)


# =============== Build config

def build_config(args: argparse.Namespace) -> ScorpionConfig:
    """Validate the parsed arguments and return an immutable ScorpionConfig.

    Each supplied path is validated individually; invalid paths are reported and
    skipped. Raises ValidationError if no valid files remain.
    """
    print(f"{Color.YELLOW}Validating input files...{Color.RESET}")

    seen = set()
    valid = set()

    for path in args.files:
        if path in seen:
            print(
                f"{Color.YELLOW}  - Duplicate ignored: {path}{Color.RESET}", file=sys.stderr)
            continue
        seen.add(path)
        result = _validate_file(path)
        if result is not None:
            valid.add(result)

    print(f"{Color.GREEN}Validation complete. {len(valid)} valid file(s) found.{Color.RESET}")

    if not valid:
        raise ValidationError(
            field="files",
            value=args.files,
            reason="no valid image files provided",
        )

    return ScorpionConfig(files=frozenset(valid))


# =============== Entry point

def main() -> int:
    """Entry point: parse arguments, build config, run Scorpion, return an exit code."""
    try:
        args = parse_args()
        config = build_config(args)
        Scorpion(config).run()
        return ExitCode.OK

    except KeyboardInterrupt:
        print(f"\n{Color.YELLOW}Interrupted by SIGINT{Color.RESET}")
        return ExitCode.SIGINT

    except ValidationError as e:
        print(f"{Color.RED}Validation error: {e}{Color.RESET}", file=sys.stderr)
        return ExitCode.INVALID_ARGS

    except (FileSystemError, ImageReadError) as e:
        print(f"{Color.RED}Filesystem error: {e}{Color.RESET}", file=sys.stderr)
        return ExitCode.FILESYSTEM_ERROR

    except Exception as e:  # pylint: disable=broad-exception-caught
        # Last-resort handler: ensures any unhandled third-party exception still
        # produces a clean message and a non-zero exit code.
        print(f"{Color.RED}Unexpected error: {e}{Color.RESET}", file=sys.stderr)
        return ExitCode.RUNTIME_ERROR


if __name__ == "__main__":
    sys.exit(main())
