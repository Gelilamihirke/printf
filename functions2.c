#include "main.h"


/**
<<<<<<< HEAD
<<<<<<< HEAD
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
=======
=======
>>>>>>> 166ce598484aad0996e8bf83efed77b55d66f86d
 * print_non_printable ->MUST Print an ascii codes in hexadecimal of non printable characters.
 * @types: a list of arguments.
 * @buffer: the buffer array for handling the print.
 * @flags:  for calculating  active flags.
 * @wdth: must get the width.
 * @prcsion: for precision specifications.
 * @size: for size specifications.
 * Return: the number of characters to be printed.
 */
<<<<<<< HEAD
int print_non_printable(va_list types, char buffer[], int flags,
 int wdth, int prcsion, int size)
=======
int print_non_printable(va_list types, char buffer[],int flags, int wdth, int prcsion, int size)
>>>>>>> 166ce598484aad0996e8bf83efed77b55d66f86d
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
<<<<<<< HEAD
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

=======
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
>>>>>>> 166ce598484aad0996e8bf83efed77b55d66f86d
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

<<<<<<< HEAD
int print_reverse(va_list types, char buffer[], int flags,
 int wdth, int prcsion, int size)
=======
int print_reverse(va_list types, char buffer[],int flags, int wdth, int prcsion, int size)
>>>>>>> 166ce598484aad0996e8bf83efed77b55d66f86d
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
<<<<<<< HEAD
		UNUSED(prcsion);

		strng = ")Null(";
	}
	for (x = 0; strng[x]; x++)
	{
		break;
=======
	UNUSED(prcsion);
	strng = ")Null(";
	}
	for (x = 0; strng[x]; x++)
	{
	break;
>>>>>>> 166ce598484aad0996e8bf83efed77b55d66f86d
	}

	for (x = x - 1; x >= 0; x--)
	{
<<<<<<< HEAD
		char z = strng[x];

		write(1, &z, 1);
		cntr++;
=======
	char z = strng[x];
	write(1, &z, 1);
	cntr++;
>>>>>>> 166ce598484aad0996e8bf83efed77b55d66f86d
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
<<<<<<< HEAD
int print_pointer(va_list types, char buffer[], int flags,
 int wdth, int prcsion, int size)
=======
int print_pointer(va_list types, char buffer[],int flags, int wdth, int prcsion, int size)
>>>>>>> 166ce598484aad0996e8bf83efed77b55d66f86d
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
<<<<<<< HEAD
		return (write(1, "(nil)", 5));
=======
	return (write(1, "(nil)", 5));
>>>>>>> 166ce598484aad0996e8bf83efed77b55d66f86d
	}
	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(prcsion);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
<<<<<<< HEAD
		buffer[pos--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		lngth++;
=======
	buffer[pos--] = map_to[num_addrs % 16];
	num_addrs /= 16;
	lngth++;
>>>>>>> 166ce598484aad0996e8bf83efed77b55d66f86d
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
	{
<<<<<<< HEAD
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
=======
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
    	return (write_pointer(buffer, pos, lngth,wdth, flags, pad, extra_chr, padd_start));
>>>>>>> 166ce598484aad0996e8bf83efed77b55d66f86d
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
<<<<<<< HEAD
int print_rot13string(va_list types, char buffer[], int flags,
 int wdth, int prcsion, int size)
=======
int print_rot13string(va_list types, char buffer[], int flags, int wdth, int prcsion, int size)
>>>>>>> 166ce598484aad0996e8bf83efed77b55d66f86d
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
<<<<<<< HEAD
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
>>>>>>> 7b3a334221adc92080cdce29f553359a7b1e980d
=======
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
>>>>>>> 166ce598484aad0996e8bf83efed77b55d66f86d
}
