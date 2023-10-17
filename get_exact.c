#include "main.h"

/**
 * get_exact - precision to printing
 * @format: Formatted string 
 * @i: arguments to be printed.
 * @list: list of arguments.
 *
 * Return: exact.
 */
int get_abs(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int exact = -1;

	if (format[curr_i] != '.')
		return (exact);

	exact = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			exact *= 10;
			exact += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			exact = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (exact);
}
