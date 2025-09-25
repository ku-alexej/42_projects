# Libft – Your First C Library
Libft is a project where you reimplement standard C library functions and create your own general-purpose library. This foundational project helps you understand how common C functions work and prepares you for future assignments.

# Key Objectives:
1. **Reimplement standard libc functions (prefix ft_):**
  - Character checks: isalpha, isdigit, isalnum, isascii, isprint
  - String and memory: strlen, memset, bzero, memcpy, memmove, strlcpy, strlcat
  - Case conversion: toupper, tolower
  - String search/compare: strchr, strrchr, strncmp, memchr, memcmp, strnstr
  - Conversion: atoi
  - Dynamic memory: calloc, strdup
2. **Additional utility functions:**
  - String manipulation: ft_substr, ft_strjoin, ft_strtrim, ft_split, ft_itoa
  - String iteration: ft_strmapi, ft_striteri
  - File descriptor output: ft_putchar_fd, ft_putstr_fd, ft_putendl_fd, ft_putnbr_fd
3. **Bonus – Linked list functions:**
  - ft_lstnew, ft_lstadd_front, ft_lstsize, ft_lstlast, ft_lstadd_back
  - ft_lstdelone, ft_lstclear, ft_lstiter, ft_lstmap

# Technical Requirements:
- No global variables
- Helper functions should be static
- All files at repository root
- Compile with -Wall -Wextra -Werror
- Use ar to create libft.a (libtool forbidden)
- Bonus functions included only if mandatory part is perfect

# Learning Outcomes:
- Deep understanding of C standard library functions
- Memory management (malloc/free)
- Linked list implementation and manipulation
- Foundational library for future C projects