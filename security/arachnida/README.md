# Spider & Scorpion

Two CLI tools for web image harvesting and image metadata inspection.



## Project structure

```
./
├── Makefile
├── requirements.txt
├── README.md
└── srcs/
    ├── spider.py
    └── scorpion.py
```



## Requirements

- Python 3.10+
- pip



## Installation

```bash
# Install Python dependencies
make install

# Create executable shell scripts at the project root
make
```

---

## Spider

Crawls a web page and downloads all images found on it.
Optionally recurses into links on the same domain up to a configurable depth.

### Supported formats

`.jpg` `.jpeg` `.png` `.gif` `.bmp`

### Usage

```bash
./spider <url> [options]
```

### Options

| Flag | Description                                    | Default   |
|------|------------------------------------------------|-----------|
| `-r` | Enable recursive crawling                      | disabled  |
| `-l` | Maximum recursion depth (requires `-r`)        | `5`       |
| `-p` | Directory to save downloaded images            | `./data`  |

### Examples

```bash
# Download images from a single page
./spider https://example.com

# Crawl recursively up to depth 3, save to ./images
./spider https://example.com -r -l 3 -p ./images
```

### What Spider extracts

Spider looks for images in:
- `<img>` tags — including lazy-load attributes (`data-src`, `data-original`, `data-lazy`, `data-url`)
- `srcset` and `data-srcset` attributes
- `<source>` elements (responsive images)
- `<video poster>` thumbnails
- `<link rel="icon">` and `<link rel="apple-touch-icon">` site icons
- `og:image` and `twitter:image` meta tags
- SVG `<image>` elements
- Inline CSS `background-image: url(...)` styles
- Direct `<a href>` links to image files

### Exit codes

| Code | Meaning              |
|------|----------------------|
| `0`  | Success              |
| `1`  | Unexpected error     |
| `2`  | Invalid arguments    |
| `3`  | Filesystem error     |
| `130`| Interrupted (SIGINT) |

---

## Scorpion

Reads and displays metadata from image files: filesystem info, image properties,
and embedded EXIF data.

### Supported formats

`.jpg` `.jpeg` `.png` `.gif` `.bmp`

### Usage

```bash
./scorpion <file1> [file2 ...]
```

### Examples

```bash
# Inspect a single image
./scorpion photo.jpg

# Inspect multiple images at once
./scorpion photo.jpg scan.png diagram.gif
```

### What Scorpion displays

**File information**
- Name, full path
- Size (bytes / Kb / Mb)
- Created and modified timestamps

**Image properties**
- Format, width, height
- Colour mode (RGB, RGBA, L, …)

**EXIF data** (when present)
- All readable tags (camera model, exposure, GPS coordinates, …)
- Tags that cannot be encoded for the terminal are shown as `[unreadable]`

### Exit codes

| Code | Meaning              |
|------|----------------------|
| `0`  | Success              |
| `1`  | Unexpected error     |
| `2`  | Invalid arguments    |
| `3`  | Filesystem / image read error |
| `130`| Interrupted (SIGINT) |

---

## Makefile targets

| Target    | Description                                          |
|-----------|------------------------------------------------------|
| `all`     | Create `./spider` and `./scorpion` shell scripts     |
| `install` | Install Python dependencies from `requirements.txt`  |
| `clean`   | Remove `__pycache__` and `.pyc` files                |
| `fclean`  | `clean` + remove the shell scripts                   |
| `re`      | `fclean` + `all`                                     |