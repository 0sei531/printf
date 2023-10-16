#include "main.h"

/**
 * print_hex - lowercase unsigned hex numbers
 * @ap: args pointer
 * @params: struct parameters
 *
 * Return: bytes printed
 */
int print_hex(va_list ap, params_t *params)
{
	unsigned long l;
	int count = 0;
	char *str;

	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	if (params->hashtag_flag && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	params->unsign = 1;
	return (count += print_number(str, params));
}

/**
 * print_HEX - uppercase unsigned hex numbers
 * @ap: args pointer
 * @params: struct parameters
 *
 * Return: bytes printed
 */
int print_HEX(va_list ap, params_t *params)
{
	unsigned long l;
	int count = 0;
	char *str;

	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED, params);
	if (params->hashtag_flag && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	params->unsign = 1;
	return (count += print_number(str, params));
}
/**
 * print_binary - unsigned binary num
 * @ap: args pointer
 * @params: struct params
 *
 * Return: printed bytes
 */
int print_binary(va_list ap, params_t *params)
{
	unsigned int num = va_arg(ap, unsigned int);
	char *str = convert(num, 2, CONVERT_UNSIGNED, params);
	int count = 0;

	if (params->hashtag_flag && num)
		*--str = '0';
	params->unsign = 1;
	return (count += print_number(str, params));
}

/**
 * print_octal - unsigned octal numbers
 * @ap: args pointer
 * @params: struct params
 *
 * Return: printed bytes
 */
int print_octal(va_list ap, params_t *params)
{
	unsigned long l;
	char *str;
	int count = 0;

	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	str = convert(l, 8, CONVERT_UNSIGNED, params);

	if (params->hashtag_flag && l)
		*--str = '0';
	params->unsign = 1;
	return (count += print_number(str, params));
}
