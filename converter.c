#include "main.h"

/**
 * convert - convert base and number to string
 * @num: input
 * @base: base
 * @lowercase: lowercase flag in hexa values
 * Return: formated string
 */
char *convert(unsigned long int num, int base, int lowercase)
{
	char *p;
	static char *r;
	static char buffer[50];
	
	r = (lowercase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	p = &buffer[49];
	*p = '\0';
	do {
		*--p = r[num % base];
		num /= base;
	} while (num != 0);

	return (p);
}
