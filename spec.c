#include "main.h"

/**
 * get_specifier - specifier function
 * @s: formated string
 * Return: bytes printed
 */

int (*get_specifier(char *s))(va_list ap, params_t *params)

{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};

	int input = 0;

	while (specifiers[input].specifier)
	{
		if (*s == specifiers[input].specifier[0])
		{
			return (specifiers[input].f);
		}
		input++;
	}
	return (NULL);
}

/**
 * get_print_func - formated function
 * @s: formated string
 * @ap: arg pointer
 * @params: structure parameters
 * Return: bytes printed
 */

int get_print_func(char *s, va_list ap, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(s);

	if (f)
		return (f(ap, params));
	return (0);
}

/**
 * get_flag - flag functions
 * @s: formated string
 * @params: structure parameters
 * Return: flag
 */

int get_flag(char *s, params_t *params)

{
	int value = 0;

	switch (*s)
	{
		case '+':
			value = params->plus_flag = 1;
			break;
		case ' ':
			value = params->space_flag = 1;
			break;
		case '#':
			value = params->hashtag_flag = 1;
			break;
		case '-':
			value = params->minus_flag = 1;
			break;
		case '0':
			value = params->zero_flag = 1;
			break;
	}
	return (value);
}

/**
 * get_modifier - modifier function
 * @s: formated string
 * @params: structure parameter
 * Return: modifier
 */

int get_modifier(char *s, params_t *params)
{
	int value = 0;

	switch (*s)
	{
		case 'h':
			value = params->h_modifier = 1;
			break;
		case 'l':
			value = params->l_modifier = 1;
			break;
	}
	return (i);
}

/**
 * get_width - formated string width
 * @s: formated string
 * @params: params struct
 * @ap: args pointer
 * Return: pointer
 */

char *get_width(char *s, params_t *params, va_list ap)

	/* should this function use char **s and modify the pointer? */
{
	int deci = 0;

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
	params->width = deci;
	return (s);
}
