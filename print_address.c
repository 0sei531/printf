#include "main.h"

/**
 * print_address - print hexa address
 * @l: va_list args
 * @f: struct flags
 * Return: printed char
 */
int print_address(va_list l, flags_t *f)
{
	char *s;
	unsigned long int pt = va_arg(l, unsigned long int);

	register int value = 0;

	(void)f;

	if (!pt)
		return (_puts("(nil)"));
	s = convert(pt, 16, 1);
	value += _puts("0x");
	value += _puts(s);
	return (value);
}
