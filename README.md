*This project has been created as part of the 42 curriculum by
fermonte.*

# ft_printf

## Description

`ft_printf` is a recreation of the standard C `printf()` function,
developed as part of the 42 curriculum.

The goal of this project is to understand variadic functions, format
strings, and how formatted output is handled in C. The implementation
reproduces the basic behavior of `printf()` for the following
conversions:

-   `%c` --- prints a character.
-   `%s` --- prints a string.
-   `%p` --- prints a pointer address in hexadecimal.
-   `%d` --- prints a signed decimal integer.
-   `%i` --- prints a signed integer.
-   `%u` --- prints an unsigned decimal integer.
-   `%x` --- prints an unsigned hexadecimal integer in lowercase.
-   `%X` --- prints an unsigned hexadecimal integer in uppercase.
-   `%%` --- prints a percent sign.

The function returns the number of characters written, following the
behavior expected from `printf()` for the supported conversions.

## Instructions

### Compilation

The project includes a `Makefile` that builds the static library
`libftprintf.a` at the root of the repository.

Run:

``` sh
make
```

Other available rules:

``` sh
make clean
make fclean
make re
```

-   `make` builds the library.
-   `make clean` removes object files.
-   `make fclean` removes object files and the compiled library.
-   `make re` performs a full rebuild.

### Using the library

Include the project header in your source file:

``` c
#include "ft_printf.h"
```

Compile your program together with the library:

``` sh
cc main.c -L. -lftprintf -o program
```

Then call `ft_printf()` as you would call the standard `printf()`
function:

``` c
ft_printf("Hello, %s! Number: %d\n", "world", 42);
```

## Algorithm and implementation

The implementation processes the format string one character at a time.

1.  Ordinary characters are written directly to standard output.
2.  When a `%` character is found, the next character is read as the
    conversion specifier.
3.  The format handler identifies the requested conversion and retrieves
    the corresponding argument from the variadic argument list using
    `va_arg`.
4.  The appropriate output function prints the value.
5.  Each output function returns the number of characters it wrote.
    These values are added to a running counter.
6.  After the format string has been processed, the variadic argument
    list is closed with `va_end`, and the total number of printed
    characters is returned.

### Variadic arguments

The implementation uses the macros and type `va_list`, `va_start`,
`va_arg`, and `va_end` from `<stdarg.h>`.

The arguments are retrieved according to the conversion specifier. For
example, `%s` retrieves a `char *`, while `%d` and `%i` retrieve an
`int`. This is important because variadic functions do not automatically
know the types of the arguments passed to them.

### Data structures and conversion logic

The main data structure is the `va_list`, which provides access to the
arguments passed after the named `format` parameter. The format string
itself determines how each argument should be interpreted.

The conversion logic is separated into small output functions. This
keeps the main function focused on parsing the format string and makes
each conversion easier to test and maintain.

For hexadecimal output, the implementation uses a base containing the
digits `0` to `9` and the letters `a` to `f` or `A` to `F`, depending on
the requested conversion. The number is converted by repeatedly
extracting its remainder when divided by 16.

## Project functions

The project is organized around the following functions:

  -----------------------------------------------------------------------
  Function                            Purpose
  ----------------------------------- -----------------------------------
  `ft_printf`                         Main function. Reads the format
                                      string, manages the variadic
                                      arguments, and returns the number
                                      of characters printed.

  `ft_format`                         Handles the conversion specifier
                                      and calls the corresponding output
                                      function. It is implemented in the
                                      same source file as `ft_printf`.

  `ft_putchar`                        Writes a single character.

  `ft_putstr`                         Writes a string.

  `ft_putdec`                         Handles decimal output.

  `ft_putnbr`                         Writes an integer value.

  `ft_puthex`                         Writes a number in hexadecimal
                                      notation.

  `ft_putprt`                         Handles pointer output, including
                                      the hexadecimal prefix.
  -----------------------------------------------------------------------

Each output function contributes to the character count returned by
`ft_printf`.

## Resources

The following resources were useful for understanding the C language
features involved in this project:

-   `printf(3)` --- the manual page for the standard `printf` function.
-   `stdarg.h` --- documentation about variadic argument handling.
-   The C language reference for integer types, pointers, and type
    conversions.
-   42 subject materials and project requirements.

### AI usage

AI was used as a learning resource to understand the data types involved
in the different format conversions and how variadic arguments are
retrieved. It was also used to assist in drafting and organizing this
README file. The implementation and project functions were developed
independently.

## Author

**fermonte**

42 School Student
