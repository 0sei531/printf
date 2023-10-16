#include "main.h"

/**
 * get_precision - string precision
 * @s: formated string
 * @params: structure parameter
 * @ap: args pointer
 * Return: generated pointer
*/

char *get_precision(char *s, params_t *params, va_list ap)
{
	int deci = 0;

	if (*s != '.')
		return (s);
	s++;
	if (*s == '*')
	{
		deci = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			deci = deci * 10 + (*s++ - '0');
	}
	params->precision = deci;
	return (s);
}

