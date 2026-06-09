# ft_printf – Reimplementing printf in C
A C project that involves recreating the functionality of the standard printf() function. This project focuses on handling variadic functions, proper formatting, and argument parsing, providing a deeper understanding of C internals and formatted output.

# Features (Mandatory):
- Implement ft_printf() with support for the following conversions:
  - %c – character
  - %s – string
  - %p – pointer in hexadecimal
  - %d / %i – signed integers
  - %u – unsigned integers
  - %x / %X – hexadecimal numbers (lowercase / uppercase)
  - %% – literal percent sign
- Use only malloc, free, write, and variadic macros (va_start, va_arg, va_copy, va_end)
- Norm-compliant, memory-leak-free, and robust error handling
- Produce a static library libftprintf.a using ar

# Bonus Features:
- Implement formatting flags (-, 0, ., field width, #, +, and space) for all conversions
- Fully extensible and modular code design

# Objective:
Learn how to manipulate variadic arguments, handle multiple data types, and produce formatted output in C. After completion, ft_printf() can be added to your libft for use in future projects.
