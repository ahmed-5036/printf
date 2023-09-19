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
	return (count);
}
