#include "main.h"

/**
 * _printf - print to the standard output
 * @format: string format
 * Return: bytes printed
 */

int _printf(const char *format, ...)

{
	int total = 0;
	va_list ap;
	char *p, *begin;

	params_t params = PARAMS_INIT;

	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))/* Null check */
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_params(&params, ap);
		if (*p != '%')/*check % specifier*/
		{
			total += _putchar(*p);
			continue;
		}
		begin = p;
		p++;
		while (get_flag(p, &params))
		{
			p++;
		}
		p = get_width(p, &params, ap);
		p = get_precision(p, &params, ap);
		if (get_modifier(p, &params))
			p++;
		if (!get_specifier(p))
			total += print_from_to(start, p,
					params.l_modifier || params.h_modifier ? p - 1 : 0);
		else
			total += get_print_func(p, ap, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(ap);
	return (sum);
}
