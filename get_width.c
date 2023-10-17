#include "main.h"

/**
 * get_width ->MUST Calculate the width required for printing.
 * @format: the formatted string in which the arguments must be print.
 * @prntLst: List of arguments to be printed.
 * @list: the list of arguments.
 * Return: the width required.
 */
int get_width(const char *format, int *prntLst, va_list list)
{
	int cntnr_x;
	int wdth = 0;

	for (cntnr_x = *prntLst + 1; format[cntnr_x] != '\0'; cntnr_x++)
	{
		if (is_digit(format[cntnr_x]))
		{
			wdth *= 10;
			wdth += format[cntnr_x] - '0';
		}
		else if (format[cntnr_x] == '*')
		{
			cntnr_x++;
			wdth = va_arg(list, int);
			break;
		}
		else
		{
			break;
		}
	}

	*prntLst = cntnr_x - 1;

	return (wdth);
}
