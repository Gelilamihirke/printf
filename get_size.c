#include "main.h"

/**
 * get_size ->MUST calculate the size required to cast the arguments.
 * @format:the formatted string in which the arguments must be print.
 * @prntLst:List of arguments to be printed.
 * Return:the Size required.
 */
int get_size(const char *format, int *prntLst)
{
	int cntnr_i = *prntLst + 1;
	int size = 0;

	if (format[cntnr_i] == 'l')
	{
		size = S_LONG;
	}
	else if (format[cntnr_i] == 'h')
	{
		size = S_SHORT;
	}
	if (size == 0)
	{
		*prntLst = cntnr_i - 1;
	}
	else
	{
		*prntLst = cntnr_i;
	}
	return (size);
}
