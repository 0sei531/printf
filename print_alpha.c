#include "main.h"

/**
 * print_string - print string function
 * @l: va_list args
 * @f: pointer structure
 * Return: char printed
 */
int print_string(va_list l, flags_t *f)
{
	char *s = va_arg(l, char *);

	(void)f;

	if (!s)
		s = "(null)";
	return (_puts(s));
}

/**
 * print_char - print character
 * @l: va_list arguments
 * @f: pointer structure
 * Return: char printed
 */
int print_char(va_list l, flags_t *f)
{
	(void)f;
	_putchar(va_arg(l, int));
	return (1);
}
