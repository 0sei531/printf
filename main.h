#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int fnt_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int pr_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int pr_str(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int pr_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int pr_bin(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int pr_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int pr_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int pr_hexadex(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int pr_hex_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int pr_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int pr_unprintable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funcion to print memory address */
int pr_ptr(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int pr_size(const char *format, int *i);
int pr_exact(const char *format, int *i, va_list list);
int activ_flag.c(const char *format, int *i);

/*Function to print string in reverse*/
int pr_rev(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int pr_rot13str(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
int wr_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int wr_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int wr_ptr(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int wr_unsignd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/****************** UTILS ******************/
int printable(char);
int app_hexa(char, char[], int);
int pr_digit(char);

long int pr_size_num(long int num, int size);
long int pr_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */

