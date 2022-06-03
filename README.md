_This is a **21 School/Ecole 42** Project_

# ft_printf

My custom printf function from libc.

# Rules
1. Don’t implement the buffer management of the original printf().
2. Your function has to handle the following conversions: cspdiuxX%
3. Your function will be compared against the original printf().
4. You must use the command ar to create your library.
    Using the libtool command is forbidden.
5. Your libftprintf.a has to be created at the root of your repository.

## Project goals
You have to implement the following conversions:
1. %c Prints a single character.
2. %s Prints a string (as defined by the common C convention).
3. %p The void * pointer argument has to be printed in hexadecimal format.
4. %d Prints a decimal (base 10) number.
5. %i Prints an integer in base 10.
6. %u Prints an unsigned decimal (base 10) number.
7. %x Prints a number in hexadecimal (base 16) lowercase format.
8. %X Prints a number in hexadecimal (base 16) uppercase format.
9. %% Prints a percent sign.

## How to run
In this directory type:
1. ft_printf:

        make
        then use created libftprintf.a in your projects
 