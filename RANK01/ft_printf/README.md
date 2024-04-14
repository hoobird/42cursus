# ft_printf - Because ft_putnbr() and ft_putstr() aren’t enough

The goal of this project is to recode the `printf()` function in C, offering a versatile alternative to the standard `printf()` found in libc. You will mainly learn about using a variable number of arguments.

## Flags for printf()

| Flag | Description                                  |
|------|----------------------------------------------|
| %c   | Prints a single character.                   |
| %s   | Prints a string (as defined by C convention).|
| %p   | Prints a pointer in hexadecimal format.     |
| %d   | Prints a decimal number.                     |
| %i   | Prints an integer in base 10.                |
| %u   | Prints an unsigned decimal number.           |
| %x   | Prints a number in hexadecimal lowercase.    |
| %X   | Prints a number in hexadecimal uppercase.    |
| %%   | Prints a percent sign.                       |

## Usage

- Clone the repository.
- Compile the library using the provided Makefile.
- Include `libftprintf.h` in your C projects to access the `ft_printf()` function.
