#include "main.h"

/**
 * get_precision -MUST calculate the precision required for printing.
 * @format: the formatted string in which the arguments must be print.
 * @prntLst: List of arguments to be printed.
 * @list: the list of arguments.
 * Return: the Precision required.
 */
int get_precision(const char *format, int *prntLst, va_list list)
{
	int cntnr_i = *prntLst + 1;
	int prcsion = -1;

	if (format[cntnr_i] != '.')
	{
		return (prcsion);
	}
	prcsion = 0;

	for (cntnr_i += 1; format[cntnr_i] != '\0'; cntnr_i++)
	{
		if (is_digit(format[cntnr_i]))
		{
			prcsion *= 10;
			prcsion += format[cntnr_i] - '0';
		}
		else if (format[cntnr_i] == '*')
		{
			cntnr_i++;
			prcsion = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*prntLst = cntnr_i - 1;

	return (prcsion);
}
