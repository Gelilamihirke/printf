#include "main.h"


/**
 * print_hexa ->MUST Print a hexadecimal number in lower or upper format.
 * @types: a list of arguments contained.
 * @map_to: the array of values to map the number to.
 * @buffer:the buffer array for handling the print.
 * @flags:  for calculating active flags.
 * @flag_ch: for calculating active flags.
 * @wdth: must get the width.
 * @prcsion: for precision specifications.
 * @size: for size specifications.
 * @size: for Size specifications.
 * Return: the number of characters to be printed.
 */
int print_hexa(va_list types, char map_to[], char buffer[], int flags, char flag_ch, int wdth, int prcsion, int size)
{
	int x = BUFF_SIZE - 2;
	unsigned long int dgt = va_arg(types, unsigned long int);
	unsigned long int init_dgt = dgt;

	UNUSED(wdth);

	dgt = convert_size_unsgnd(dgt, size);

	if (dgt == 0)
	{
		buffer[x--] = '0';
	}
	buffer[BUFF_SIZE - 1] = '\0';

	while (dgt > 0)
	{
		buffer[x--] = map_to[dgt % 16];
		dgt /= 16;
	}

	if (flags & F_HASH && init_dgt != 0)
	{
		buffer[x--] = flag_ch;
		buffer[x--] = '0';
	}

	x++;

	return (write_unsgnd(0, x, buffer, flags, wdth, prcsion, size));
}

/**
 * print_hexadecimal ->MUST Print an unsigned number in hexadecimal notation.
 * @types: A List  of arguments CONTAINED.
 * @buffer: the buffer array for handling the print.
 * @flags: for  calculating active flags.
 * @wdth: must get the width.
 * @prcsion: for Precision specification.
 * @size: for Size specifications.
 * Return: the number of characterss to be printed.
 */
int print_hexadecimal(va_list types, char buffer[], int flags, int wdth, int prcsion, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer, flags, 'x', wdth, prcsion, size));
}

/**
 * print_unsigned ->MUST print an unsigned number.
 * @types: a list  of arguments.
 * @buffer: the buffer array for handling the print.
 * @flags:  must calculate active flags.
 * @width: must get  the width.
 * @prcsion: for Precision specification.
 * @size: for Size specifications.
 * Return: the number of characters to be printed.
 */
int print_unsigned(va_list types, char buffer[], int flags, int width, int prcsion, int size)
{
	int x = BUFF_SIZE - 2;
	unsigned long int inpt = va_arg(types, unsigned long int);

	inpt = convert_size_unsgnd(inpt, size);

	if (inpt == 0)
	{
		buffer[x--] = '0';
	}
	buffer[BUFF_SIZE - 1] = '\0';

	while (inpt > 0)
	{
		buffer[x--] = (inpt % 10) + '0';
		inpt /= 10;
	}

	x++;

	return (write_unsgnd(0, x, buffer, flags, width, prcsion, size));
}

/**
 * print_octal ->MUST Print an unsigned number in octal notation.
 * @types: a list  of arguments contained.
 * @buffer: the buffer array for handling the print.
 * @flags: for  calculating active flags.
 * @wdth: must get the width.
 * @prcsion: for Precision specification.
 * @size: for Size specifications.
 * Return: the number of characterss to be printed.
 */
int print_octal(va_list types, char buffer[], int flags, int wdth, int prcsion, int size)
{

	int x = BUFF_SIZE - 2;
	unsigned long int dgt = va_arg(types, unsigned long int);
	unsigned long int init_dgt = dgt;

	UNUSED(wdth);

	dgt = convert_size_unsgnd(dgt, size);

	if (dgt == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (dgt > 0)
	{
		buffer[x--] = (dgt % 8) + '0';
		dgt /= 8;
	}

	if (flags & F_HASH && init_dgt != 0)
	{
		buffer[x--] = '0';
	}
	x++;

	return (write_unsgnd(0, x, buffer, flags, wdth, prcsion, size));
}




/**
 * print_hexa_upper ->MUST Print an unsigned number in upper hexadecimal notation.
 * @types: a List  of arguments CONTAINED.
 * @buffer: the buffer array for handling the print.
 * @flags: for  calculating active flags.
 * @wdth: must get the width.
 * @prcsion: for Precision specification.
 * @size: for Size specifications.
 * Return: the number of characterss to be printed.
 */
int print_hexa_upper(va_list types, char buffer[], int flags, int wdth, int prcsion, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer, flags, 'X', wdth, prcsion, size));
}
