#include "main.h"
/**
 * handle_print ->MUST Print an argument based on its type.
 * @fmt: the formatted string in which the arguments must be print .
 * @list:the list of arguments to be printed.
 * @pos: position tracker.
 * @buffer:the buffer array to handle the printing.
 * @flags: for calculating active flags.
 * @wdth: get width.
 * @prcsion: for precision specifications.
 * @size: for Size specifications.
 * Return:chrctrs_printd either 1 or 2 ;
 */
int handle_print(const char *fmt, int *pos, va_list list,
 char buffer[], int flags, int wdth, int prcsion, int size)
{
	int x;
	int unknwn_lgnth = 0;
	int chrctrs_printd = -1;
	fmt_t fmt_types[] = {
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
	};
	for (x = 0; fmt_types[x].fmt != '\0'; x++)
	{
		if (fmt[*pos] == fmt_types[x].fmt)
	}
			return (fmt_types[x].fn(list, buffer, flags, wdth, prcsion, size));

	if (fmt_types[x].fmt == '\0')
	{
		if (fmt[*pos] == '\0')
		{
			return (-1);
		}
		unknwn_lgnth += write(1, "%%", 1);
		if (fmt[*pos - 1] == ' ')
		{
			unknwn_lgnth += write(1, " ", 1);
		}
		else if (wdth)
		{
			--(*pos);
			while (fmt[*pos] != ' ' && fmt[*pos] != '%')
			{
				--(*pos);
			}
			if (fmt[*pos] == ' ')
			{
				--(*pos);
			}
			return (1);
		}
		unknwn_lgnth += write(1, &fmt[*pos], 1);
		return (unknwn_lgnth);
	}
	return (chrctrs_printd);
}
