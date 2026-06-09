# Inception – Dockerized Infrastructure

A system administration project focused on containerization with Docker Compose. The goal is to build and configure a complete infrastructure inside a virtual machine by writing your own Dockerfiles.

# Features:

- NGINX container with TLSv1.2/1.3 as the single entry point
- WordPress container running with php-fpm (no NGINX inside)
- MariaDB container with persistent storage
- Volumes for WordPress files and database
- Custom Docker network for inter-container communication
- Environment variables and secrets for secure configuration

Run:
`make`

# Bonus options:
- Redis cache for WordPress
- FTP server
- Adminer or other useful services
- Custom static website
