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
 * int_to_str - Converts an integer to a string
 * @num: The integer to convert
 *
 * Return: The resulting string
 */
char *int_to_str(int num)
{
	char *str;
	int num_copy = num;
	int num_digits = 0;

	/* Count the number of digits in the integer */
	while (num_copy != 0)
	{
		num_copy /= 10;
		num_digits++;
	}

	/* Allocate memory for the string (including space for '\0') */
	str = malloc(num_digits + 1);
	if (str == NULL)
		return (NULL);

	/* Build the string in reverse order */
	str[num_digits] = '\0';
	while (num != 0)
	{
		num_digits--;
		str[num_digits] = '0' + (num % 10);
		num /= 10;
	}

	return (str);
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
	return (count);
}
