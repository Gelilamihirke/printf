#include "main.h"

/**
 * get_flags ->MUST Calculate active flags.
 * @format: will format the string in which the arguments must be print.
 * @inpt: input parameter.
 * Return: the flags.
 */
int get_flags(const char *format, int *inpt)
{

	int x;
	int cntnr_i;
	int flags = 0;
	const char FLAGS_CHR[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (cntnr_i = *inpt + 1; format[cntnr_i] != '\0'; cntnr_i++)
	{
		for (x = 0; FLAGS_CHR[x] != '\0'; x++)
			if (format[cntnr_i] == FLAGS_CHR[x])
			{
				flags |= FLAGS_ARR[x];
				break;
			}

		if (FLAGS_CHR[x] == 0)
			break;
	}

	*inpt = cntnr_i - 1;

	return (flags);
}
