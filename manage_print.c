#include "main.h"
/**
 * handle_print - argument type.
 * @fmt: Formatted string.
 * @list: List of arguments.
 * @ind: ind.
 * @buffer: Buffer array.
 * @flags: active flags
 * @width: width.
 * @precision: Precision specification
 * @size: Size
 * Return: 1;
 */
int fnt_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', pr_char}, {'s', pr_str}, {'%', pr_percent},
		{'i', print_int}, {'d', print_int}, {'b', pr_bin},
		{'u', pr_unsigned}, {'o', pr_octal}, {'x', pr_hexadex},
		{'X', pr_hex_upper}, {'p', pr_ptr}, {'S', pr_unprintable},
		{'r', pr_rev}, {'R', pr_rot13str}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &fmt[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
