#include "main.h"

/**
 * print_string - loop and print char
 * @l: va_list args
 * @f: struct flags
 * Return: char printed
 */
int print_string(va_list l, flags_t *f)
{
	char *str = va_arg(l, char *);

	(void)f;

	if (!str)
		str = "(null)";
	return (_puts(str));
}

/**
 * print_char - print char
 * @l: va_list args
 * @f: struct flags
 * Return: printed char
 */
int print_char(va_list l, flags_t *f)
{
	(void)f;
	_putchar(va_arg(l, int));
	return (1);
}
