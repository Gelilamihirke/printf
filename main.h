#ifndef _MAIN_H_
#define _MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int _putchar(char c);
int _printf(const char *format, ...);
int print_num(va_list n);
int print_string(va_list s);
int _strlen(const char *s);
int (*cmp_func(const char a))(va_list);
int print_char(va_list arr);
void print_bin(unsigned int num);
int print_bin(va_list arr);
int print_unsigned(va_list n);
/**
 * struct types - specifier structure for printf
 * @p: pointer
 * @func: function
 */
typedef struct types
{
	char p;
	int (*func)(va_list);
}
myprintf;

#endif
