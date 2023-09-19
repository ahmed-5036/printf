#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;     /* Declare a variable to handle variable arguments */
    int count = 0;    /* Initialize a counter for characters printed */
    char c;           /* Temporary variable for characters */
    char *str;        /* Temporary variable for strings */

    va_start(args, format); /* Initialize the va_list to work with arguments */

    while (*format) /* Loop through each character in the format string */
    {
        if (*format != '%') /* If it's not a '%', print it and increment the count */
        {
            write(1, format, 1);
            count++;
        }
        else
        {
            format++; /* Move to the next character after '%' */
            switch (*format)
            {
                case 'c':
                    c = va_arg(args, int); /* Extract a character argument */
                    write(1, &c, 1); /* Write the character */
                    count++; /* Increment the count */
                    break;
                case 's':
                    str = va_arg(args, char *); /* Extract a string argument */
                    if (str == NULL)
                        str = "(null)"; /* Handle NULL strings */
                    while (*str)
                    {
                        write(1, str, 1); /* Write each character of the string */
                        str++;
                        count++;
                    }
                    break;
                case '%':
                    write(1, "%", 1); /* Write a '%' character */
                    count++;
                    break;
                default:
                    /* Handle unsupported specifier, write both '%' and the character */
                    write(1, &format[-1], 1);
                    write(1, format, 1);
                    count += 2;
                    break;
            }
        }
        format++; /* Move to the next character in the format string */
    }

    va_end(args); /* Clean up the va_list */
    return (count); /* Return the total count of characters printed */
}
