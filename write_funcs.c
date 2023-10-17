#include "main.h"
#include <unistd.h>

/**
 * _putchar - char to standard output
 * @c: char to print
 * Return: success 1.
 */
int _putchar(char c)
{
	static char buf[1024];
	static int input;

	if (c == -1 || input >= 1024)
	{
		write(1, &buf, input);
		input = 0;
	}
	if (c != -1)
	{
		buf[input] = c;
		input++;
	}
	return (1);
}

/**
 * _puts - string to stdout
 * @str: string pointer
 * Return: numbers of printed strings
 */
int _puts(char *str)
{
	register int input;

	for (input = 0; str[input] != '\0'; input++)
		_putchar(str[input]);
	return (input);
}
