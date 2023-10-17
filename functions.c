#include "main.h"

/**
 * print_binary ->MUST Print an unsigned number as binary.
 * @types: a list of arguments passed.
 * @buffer:the buffer array for handling the print.
 * @flags:  for calculating active flags.
 * @wdth: get width.
 * @precision: for precision specifications.
 * @size: for Size specifications.
 * Return: the number of characters to be printed.
 */
int print_binary(va_list types, char buffer[],
		int flags, int wdth, int precision,
		int size)
{
	unsigned int c;
	unsigned int b;
	unsigned int x;
	unsigned int sum;
	unsigned int array[32];
	int cntr;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(wdth);
	UNUSED(precision);
	UNUSED(size);

	c = va_arg(types, unsigned int);
	b = 2147483648;
	array[0] = c / b;
	for (x = 1; x < 32; x++)
	{
	b /= 2;
	array[x] = (c / b) % 2;
	}
	for (x = 0, sum = 0, cntr = 0; x < 32; x++)
	{
	sum += array[x];
	if (sum || x == 31)
	{
	char z = '0' + array[x];
	write(1, &z, 1);
	cntr++;
	}
	}
	return (cntr);
}

/**
 * print_string -> MUST Print a string.
 * @types: a list of arguments passed.
 * @buffer: a Buffer array for handling the print.
 * @flags: for calculating active flags.
 * @wdth: gets the width.
 * @prcsion: for precision specification
 * @size: for Size specification.
 * Return: the number of characters to be printed.
 */
int print_string(va_list types,
		char buffer[],
		int flags, int wdth,
		int prcsion, int size)
{
	int lngth = 0;
	int s;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(wdth);
	UNUSED(prcsion);
	UNUSED(size);
	if (str == NULL)
	{
	str = "(null)";
	if (prcsion >= 6)
	{
	str = "    ";
	}
	}
	while (str[lngth] != '\0')
	{
	lngth++;
	}
	if (prcsion >= 0 && prcsion < lngth)
	{
	lngth = prcsion;
	}
	if (wdth > lngth)
	{
	if (flags & F_MINUS)
	{
	write(1, &str[0], lngth);
	for (s = wdth - lngth; s > 0; s--)
	{
	write(1, " ", 1);
	}
	return (wdth);
	}
	else
	{
	for (s = wdth - lngth; s > 0; s--)
	{
	write(1, " ", 1);
	}
	write(1, &str[0], lngth);
	return (wdth);
	}
	}
	return (write(1, str, lngth));
}

/**
 * print_percent ->MUST Print a percent sign(%).
 * @types:a list of arguments.
 * @buffer: the buffer array to handle the print.
 * @flags:  for calculating active flags.
 * @wdth: must get the width.
 * @prcsion:for Precision specifications.
 * @size: for Size specifications.
 * Return: the number of characters to be printed.
 */
int print_percent(va_list types, char buffer[],
		int flags, int wdth, int prcsion,
		int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(wdth);
	UNUSED(prcsion);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * print_char -> MUST Print a single character.
 * @types: a list of arguments passed.
 * @buffer: a Buffer array for handling the print.
 * @flags: for calculating active flags.
 * @wdth: must get the width.
 * @prcsion: for Precision specification.
 * @size: for size specification.
 * Return: the number of characters to be printed.
 */
int print_char(va_list types, char buffer[],
		int flags, int wdth, int prcsion,
		int size)
{
	char chr = va_arg(types, int);

	return (handle_write_char(chr, buffer, flags, wdth, prcsion, size));
}

/**
 * print_int ->MUST Print an integer.
 * @types: a list of arguments passed.
 * @buffer: Buffer array to handle print.
 * @flags:  for calculating active flags.
 * @wdth: must get the width.
 * @prcsion: for Precision specification.
 * @size: for Size specifier
 * Return: the number of chars printed
 */
int print_int(va_list types, char buffer[],
		int flags, int wdth, int prcsion,
		int size)
{
	int x = BUFF_SIZE - 2;
	int if_negative = 0;
	long int c = va_arg(types, long int);
	unsigned long int inpt;

	c = convert_size_number(c, size);

	if (c == 0)
	{
	buffer[x--] = '0';
	}
	buffer[BUFF_SIZE - 1] = '\0';
	inpt = (unsigned long int)c;
	if (c < 0)
	{
	inpt = (unsigned long int)((-1) * c);
	if_negative = 1;
	}
	while (inpt > 0)
	{
	buffer[x--] = (inpt % 10) + '0';
	inpt /= 10;
	}

	x++;

	return (write_number(if_negative, x, buffer,
				flags, wdth, prcsion, size));
}

