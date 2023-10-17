#include "main.h"


/**
 * print_non_printable ->MUST Print an ascii codes in hexadecimal of non printable characters.
 * @types: a list of arguments.
 * @buffer: the buffer array for handling the print.
 * @flags:  for calculating  active flags.
 * @wdth: must get the width.
 * @prcsion: for precision specifications.
 * @size: for size specifications.
 * Return: the number of characters to be printed.
 */
int print_non_printable(va_list types, char buffer[], int flags,
 int wdth, int prcsion, int size)
{
	int x = 0;
	int offset = 0;
	char *strng = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(wdth);
	UNUSED(prcsion);
	UNUSED(size);

	if (strng == NULL)
	{
		return (write(1, "(null)", 6));
	}
	while (strng[x] != '\0')
	{
		if (is_printable(strng[x]))
		{
			buffer[x + offset] = strng[x];
		}
		else
		{
			offset += append_hexa_code(strng[x], buffer, x + offset);
}
		x++;
	}

	buffer[x + offset] = '\0';

	return (write(1, buffer, x + offset));
}


/**
 * print_reverse ->MUST Print a string in reverse.
 * @types: a list of arguments.
 * @buffer: the buffer array for handling the print.
 * @flags:  for calculating  active flags.
 * @wdth: must get the width.
 * @prcsion: for precision specifications.
 * @size: for size specifications.
 * Return: the number of characters to be printed
 */

int print_reverse(va_list types, char buffer[], int flags,
 int wdth, int prcsion, int size)
{
	char *strng;
	int x;
	int cntr = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(wdth);
	UNUSED(size);

	strng = va_arg(types, char *);

	if (strng == NULL)
	{
		UNUSED(prcsion);

		strng = ")Null(";
	}
	for (x = 0; strng[x]; x++)
	{
		break;
	}

	for (x = x - 1; x >= 0; x--)
	{
		char z = strng[x];

		write(1, &z, 1);
		cntr++;
	}
	return (cntr);
}


/**
 * print_pointer ->MUST Print the value of a pointer variable.
 * @types: a list of arguments.
 * @buffer: the buffer array for handling the print.
 * @flags:  for calculating  active flags.
 * @wdth: must get the width.
 * @prcsion: for precision specifications.
 * @size: for size specifications.
 * Return: the number of characters to be printed.
 */
int print_pointer(va_list types, char buffer[], int flags,
 int wdth, int prcsion, int size)
{
	char extra_chr = 0;
	char pad = ' ';
	int pos = BUFF_SIZE - 2;
	int lngth = 2;
	int padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(wdth);
	UNUSED(size);

	if (addrs == NULL)
	{
		return (write(1, "(nil)", 5));
	}
	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(prcsion);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[pos--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		lngth++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
	{
		pad = '0';
	}
	if (flags & F_PLUS)
	{
		extra_chr = '+', lngth++;
	}
	else if (flags & F_SPACE)
	{
		extra_chr = ' ', lngth++;
	}
	pos++;

	return (write_pointer(buffer, pos, lngth, wdth,	flags, pad, extra_chr, padd_start));
}


/**
 * print_rot13string -> MUST Print a string in rot13 format.
 * @types: a List  of arguments contained
 * @buffer: the buffer array for handling the print.
 * @flags:  for calculating  active flags.
 * @wdth: must get the width.
 * @prcsion: for precision specifications.
 * @size: for size specifications.
 * Return: the number of characters to be printed
 */
int print_rot13string(va_list types, char buffer[], int flags,
 int wdth, int prcsion, int size)
{
	char cntnr;
	char *strng;
	unsigned int x;
	unsigned int y;
	int cntr = 0;
	char inpt[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char outpt[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	strng = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(wdth);
	UNUSED(prcsion);
	UNUSED(size);

	if (strng == NULL)
	{
		strng = "(AHYY)";
	}
	for (x = 0; strng[x]; x++)
	{
		for (y = 0; inpt[y]; y++)
		{
			if (in[y] == strng[x])
			{
				cntnr = outpt[y];
				write(1, &cntnr, 1);
				cntr++;
				break;
			}
		}
		if (!inpt[y])
		{
			cntnr = strng[x];
			write(1, &cntnr, 1);
			cntr++;
		}
	}
	return (cntr);
}
