#include "main.h"

/**
 * _isdigit - check if input is digit
 * @c: character to check
 *
 * Return: 1 if digit, 0 !digit
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - string len
 * @s: input string to check
 *
 * Return: int string lenght
 */
int _strlen(char *s)
{
	int input = 0;

	while (*s++)
		input++;
	return (input);
}

/**
 * print_number - print a number
 * @str: string base number
 * @params: struct params
 *
 * Return: printed characters
 */
int print_number(char *str, params_t *params)
{
	unsigned int input = _strlen(str);
	int n = (!params->unsign && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (n)
	{
		str++;
		input--;
	}
	if (params->precision != UINT_MAX)
		while (input++ < params->precision)
			*--str = '0';
	if (n)
		*--str = '-';

	if (!params->minus_flag)
		return (print_number_right_shift(str, params));
	else
		return (print_number_left_shift(str, params));
}

/**
 * print_number_right_shift - print number selection
 * @str: string base number
 * @params: structure params
 *
 * Return: printed characters
 */
int print_number_right_shift(char *str, params_t *params)
{
	unsigned int num = 0, ne, ne2, input = _strlen(str);
	char p_ch = ' ';

	if (params->zero_flag && !params->minus_flag)
		p_ch = '0';
	ne = ne2 = (!params->unsign && *str == '-');
	if (ne && i < params->width && p_ch == '0' && !params->minus_flag)
		str++;
	else
		ne = 0;
	if ((params->plus_flag && !ne2) ||
		(!params->plus_flag && params->space_flag && !ne2))
		input++;
	if (ne && p_ch == '0')
		num += _putchar('-');
	if (params->plus_flag && !ne2 && p_ch == '0' && !params->unsign)
		num += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !ne2 &&
		!params->unsign && params->zero_flag)
		num += _putchar(' ');
	while (input++ < params->width)
		num += _putchar(p_ch);
	if (ne && p_ch == ' ')
		num += _putchar('-');
	if (params->plus_flag && !ne2 && p_ch == ' ' && !params->unsign)
		num += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !ne2 &&
		!params->unsign && !params->zero_flag)
		num += _putchar(' ');
	num += _puts(str);
	return (num);
}

/**
 * print_number_left_shift - print number selection
 * @str: string base number
 * @params: structure params
 *
 * Return: printed characters
 */
int print_number_left_shift(char *str, params_t *params)
{
	unsigned int num = 0, ne, ne2, input = _strlen(str);
	char p_ch = ' ';

	if (params->zero_flag && !params->minus_flag)
		p_ch = '0';
	ne = ne2 = (!params->unsign && *str == '-');
	if (ne && i < params->width && p_ch == '0' && !params->minus_flag)
		str++;
	else
		ne = 0;

	if (params->plus_flag && !ne2 && !params->unsign)
		num += _putchar('+'), input++;
	else if (params->space_flag && !ne2 && !params->unsign)
		num += _putchar(' '), input++;
	num += _puts(str);
	while (input++ < params->width)
		num += _putchar(p_ch);
	return (num);
}
