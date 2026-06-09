# Get Next Line – Read a file line by line in C
A C project focused on creating a function get_next_line() that reads a line from a file descriptor. This project teaches static variables, memory management, and efficient I/O handling.

# Features (Mandatory):
- Implement char *get_next_line(int fd) to read a file descriptor line by line
- Each call returns the next line, including the newline character (\n) if present
- Returns NULL on end-of-file or error
- Efficient reading: reads only as much as necessary each time
- Handles any file descriptor, including standard input
- Fully compliant with the Norm, memory-leak-free, and robust error handling
- Compile with a customizable BUFFER_SIZE via -D BUFFER_SIZE=n

# Bonus Features:
- Support multiple file descriptors simultaneously using a single static variable
- Implement a _bonus version with separate source files for bonus functionality

# Objective:
Learn how to efficiently manage buffers, handle I/O operations, and work with static variables in C. After completion, get_next_line() can be added to your libft for future use.
