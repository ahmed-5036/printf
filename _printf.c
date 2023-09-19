#include "main.h"

/**
 * _write_char - Write a single character to stdout
 * @c: The character to be written
 * @count: Pointer to the count of characters printed
 */
void _write_char(char c, int *count)
{
    write(1, &c, 1);
    (*count)++;
}

/**
 * _write_str - Write a string to stdout
 * @str: The string to be written
 * @count: Pointer to the count of characters printed
 */
void _write_str(char *str, int *count)
{
    if (str == NULL)
        str = "(null)";

    while (*str)
    {
        _write_char(*str, count);
        str++;
    }
}

/**
 * _write_int - Write an integer to stdout
 * @n: The integer to be written
 * @count: Pointer to the count of characters printed
 */
void _write_int(int n, int *count)
{
    char buffer[20]; // Assuming a maximum of 20 digits for an int
    snprintf(buffer, sizeof(buffer), "%d", n);
    _write_str(buffer, count);
}

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format != '%')
            _write_char(*format, &count);
        else
        {
            format++;
            switch (*format)
            {
            case 'c':
                _write_char(va_arg(args, int), &count);
                break;
            case 's':
                _write_str(va_arg(args, char *), &count);
                break;
            case 'd':
            case 'i':
                _write_int(va_arg(args, int), &count);
                break;
            case '%':
                _write_char('%', &count);
                break;
            default:
                _write_char('%', &count);
                _write_char(*format, &count);
                break;
            }
        }
        format++;
    }

    va_end(args);
    return count;
}
