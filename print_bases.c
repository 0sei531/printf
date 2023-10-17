#include "main.h"

/**
 * print_hex_lower - print lowercase hexa number
 * @l: va_list args
 * @f: struct flags
 * Return: printed char
 */
int print_hex(va_list l, flags_t *f)
{
	int value = 0;
	unsigned int n = va_arg(l, unsigned int);
	char *s = convert(n, 16, 1);
	
	if (f->hash == 1 && str[0] != '0')
		value += _puts("0x");
	value += _puts(s);
	return (value);
}

/**
 * print_hex_upper - print uppercase hexa number
 * @l: va_list args
 * @f: struct flags
 * Return: printed char
 */
int print_hex_big(va_list l, flags_t *f)
{
	int value = 0;
	unsigned int n = va_arg(l, unsigned int);
	char *s = convert(n, 16, 0);
	
	if (f->hash == 1 && str[0] != '0')
		value += _puts("0X");
	value += _puts(s);
	return (value);
}

/**
 * print_binary - print binary number
 * @l: va_list args
 * @f: struct pointer
 * Return: values of printed char
 */
int print_binary(va_list l, flags_t *f)
{
	unsigned int n = va_arg(l, unsigned int);
	char *s = convert(n, 2, 0);

	(void)f;
	return (_puts(s));
}

/**
 * print_octal - prints octal number
 * @l: va_list args
 * @f: pointer structure
 * Return: values of char printed
 */
int print_octal(va_list l, flags_t *f)
{
	int value = 0;
	unsigned int n = va_arg(l, unsigned int);
	char *s = convert(n, 8, 0);
	
	if (f->hash == 1 && str[0] != '0')
		value += _putchar('0');
	value += _puts(s);
	return (value);
}
