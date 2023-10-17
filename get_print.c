#include "main.h"

/**
 * get_print - get_print function for _printf
 * @s: chars specifier
 * Return: _printf pointer function
 */
int (*get_print(char s))(va_list, flags_t *)
{
	ph func_arr[] = {
		{'i', print_int},
		{'s', print_string},
		{'c', print_char},
		{'d', print_int},
		{'u', print_unsigned},
		{'x', print_hex},
		{'X', print_hex_big},
		{'b', print_binary},
		{'o', print_octal},
		{'R', print_rot13},
		{'r', print_rev},
		{'S', print_bigS},
		{'p', print_address},
		{'%', print_percent}
		};
	int flags = 14;

	register int value;

	for (value = 0; value < flags; value++)
		if (func_arr[value].c == s)
			return (func_arr[value].f);
	return (NULL);
}
