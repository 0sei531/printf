#include "main.h"

/**
 * get_flag - flag modifier for formated string
 * @s: char flag
 * @f: struct pointer flag
 * Return: 1 if valid flag, else (0)
 */
int get_flag(char s, flags_t *f)
{
	int value = 0;

	switch (s)
	{
		case '+':
			f->plus = 1;
			value = 1;
			break;
		case ' ':
			f->space = 1;
			value = 1;
			break;
		case '#':
			f->hash = 1;
			value = 1;
			break;
	}

	return (value);
}
