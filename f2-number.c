#include "main.h"

/**
 * print_from_to - print range of char addr
 * @start: first addr
 * @stop: last addr
 * @except: excepted addr
 *
 * Return: bytes printed
 */
int print_from_to(char *start, char *stop, char *except)
{
	int total = 0;

	while (start <= stop)
	{
		if (start != except)
			total += _putchar(*start);
		start++;
	}
	return (total);
}

/**
 * print_rev - reverse string
 * @ap: strings to be printed
 * @params: struct parameters
 *
 * Return: bytes printed
 */
int print_rev(va_list ap, params_t *params)
{
	int len, total = 0;
	char *str = va_arg(ap, char *);
	(void)params;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			total += _putchar(*str);
	}
	return (total);
}

/**
 * print_rot13 - rot13 strings
 * @ap: strings
 * @params: struct parameters
 *
 * Return: bytes printed
 */
int print_rot13(va_list ap, params_t *params)
{
	int in, ind;
	int count = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ap, char *);
	(void)params;

	in = 0;
	ind = 0;
	while (a[in])
	{
		if ((a[in] >= 'A' && a[in] <= 'Z')
		    || (a[in] >= 'a' && a[in] <= 'z'))
		{
			ind = a[in] - 65;
			count += _putchar(arr[ind]);
		}
		else
			count += _putchar(a[in]);
		in++;
	}
	return (count);
}
