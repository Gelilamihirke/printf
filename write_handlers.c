#include "main.h"




/**
 * write_number ->MUST Print a string of Numbers.
 * @is_negative: the List of arguments contained.
 * @pos: position at which the number starts on the buffer.
 * @buffer: the buffer array to handle print outs.
 * @flags:  for calculating active flags.
 * @wdth: must get the width.
 * @prcsion: for precision specifications.
 * @size: for Size specifications.
 * Return: the number of characters printed.
 */
int write_number(int is_negative, int pos, char buffer[], int flags, int wdth, int prcsion, int size)
{
	int lngth = BUFF_SIZE - pos - 1;
	char pad = ' ';
	char xtra_chr = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
	{
		pad = '0';
	}
	if (is_negative)
	{
		xtra_chr = '-';
	}
	else if (flags & F_PLUS)
	{
		xtra_chr = '+';
	}
	else if (flags & F_SPACE)
	{
		xtra_chr = ' ';
	}
	return (write_num(pos, buffer, flags, wdth, prcsion, lngth, pad, xtra_chr));
}


/**
 * write_unsgnd ->MUST Write an unsigned number.
 * @is_negative: the number for indicating if the number is negative or not.
 * @pos: position at which the number starts in the buffer.
 * @buffer: Array of chars
 * @flags: Flags specifiers
 * @wdth: must get the Width.
 * @prcsion: for precision specifications.
 * @size: for size specifications
 * Return: the number of written characters.
 */
int write_unsgnd(int is_negative, int pos, char buffer[], int flags, int wdth, int prcsion, int size)
{
	int lngth = BUFF_SIZE - pos - 1, i = 0;
	char pad = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (prcsion == 0 && pos == BUFF_SIZE - 2 && buffer[pos] == '0')
	{
		return (0);
	}
	if (prcsion > 0 && prcsion < lngth)
	{
		pad = ' ';
	}
	while (prcsion > lngth)
	{
		buffer[--pos] = '0';
		lngth++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
	{
		pad = '0';
	}
	if (wdth > lngth)
	{
		for (i = 0; i < wdth - lngth; i++)
		{
			buffer[i] = pad;
		}
		buffer[i] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[pos], lngth) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[pos], lngth));
		}
	}

	return (write(1, &buffer[pos], length));
}

/**
 * write_pointer -> must write a memory address.
 * @buffer: the buffer array to handle print outs.
 * @pos: position at which the number starts in the buffer.
 * @lngth: the length of the number.
 * @wdth: must get the width.
 * @flags:for calculating active flags.
 * @pad: the padding character.
 * @xtra_chr: the character for representing the extra character.
 * @strt_pad: Index at which padding should start
 * Return: the number of written characters.
 */
int write_pointer(char buffer[], int pos, int lngth, int wdth, int flags, char pad, char xtra_chr, int strt_pad)
{
	int x;

	if (wdth > lngth)
	{
		for (x = 3; x < wdth - lngth + 3; x++)
		{
			buffer[x] = pad;
		}
		buffer[x] = '\0';
		if (flags & F_MINUS && pad == ' ')
		{
			buffer[--pos] = 'x';
			buffer[--pos] = '0';
			if (xtra_chr)
			{
				buffer[--pos] = xtra_chr;
			}
			return (write(1, &buffer[pos], lngth) + write(1, &buffer[3], x - 3));
		}
		else if (!(flags & F_MINUS) && pad == ' ')
		{
			buffer[--pos] = 'x';
			buffer[--pos] = '0';
			if (xtra_chr)
			{
				buffer[--pos] = xtra_chr;
			}
			return (write(1, &buffer[3], x - 3) + write(1, &buffer[pos], lngth));
		}
		else if (!(flags & F_MINUS) && pad == '0')
		{
			if (xtra_chr)
			{
				buffer[--strt_pad] = xtra_chr;
			}
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[strt_pad], x - strt_pad) + write(1, &buffer[pos], lngth - (1 - strt_pad) - 2));
		}
	}
	buffer[--pos] = '0';
	buffer[--pos] = 'x';
	if (xtra_chr)
	{
		buffer[--pos] = xtra_chr;
	}
	return (write(1, &buffer[pos], BUFF_SIZE - pos - 1));
}


/**
 * handle_write_char ->MUST Print a string of CHARACTERS.
 * @chr_type: character types.
 * @buffer: Buffer array to handle print
 * @flags:  for calculating  active flags.
 * @width: must get the width.
 * @prcsion: for precision specifications.
 * @size: for Size specifications.
 * Return: the mumber of characters printed.
 */
int handle_write_char(char c, char buffer[], int flags, int width, int prcsion, int size)
{
	int x = 0;
	char pad = ' ';

	UNUSED(prcsion);
	UNUSED(size);

	if (flags & F_ZERO)
	{
		pad = '0';
	}

	buffer[x++] = c;
	buffer[x] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (; x < width - 1; x++)
		{
			buffer[BUFF_SIZE - x - 2] = pad;
		}
		if (flags & F_MINUS)
		{
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - x - 1], width - 1));
		}
		else
		{
			return (write(1, &buffer[BUFF_SIZE - x - 1], width - 1) +
					write(1, &buffer[0], 1));
		}
	}

	return (write(1, &buffer[0], 1));
}


/**
 * write_num ->MUST Write a number using a bufffer.
 * @pos: position at which the number starts on the buffer.
 * @buffer: the buffer array to handle print outs.
 * @flags: for calculating active flags.
 * @wdth: must get the width.
 * @prcsion: for precision specifications.
 * @lngth: the length of the number.
 * @pad: the pading character.
 * @xtra_chr: for reserving an extra character space.
 * Return: the number of printed characters.
 */
int write_num(int pos, char buffer[], int flags, int wdth, int prcsion, int lngth, char pad, char xtra_chr)
{
	int x, strt_pad = 1;

	if (prcsion == 0 && pos == BUFF_SIZE - 2 && buffer[pos] == '0' && wdth == 0)
	{
		return (0);
	}
	if (prcsion == 0 && pos == BUFF_SIZE - 2 && buffer[pos] == '0')
	{
		buffer[pos] = pad = ' ';
	}
	if (prcsion > 0 && prcsion < lngth)
	{
		pad = ' ';
	}
	while (prcsion > lngth)
	{
		buffer[--pos] = '0', lngth++;
	}
	if (xtra_chr != 0)
	{
		lngth++;
	}
	if (wdth > lngth)
	{
		for (x = 1; x < wdth - lngth + 1; x++)
		{
			buffer[x] = pad;
		}
		buffer[x] = '\0';
		if (flags & F_MINUS && pad == ' ')
		{
			if (xtra_chr)
			{
				buffer[--pos] = xtra_chr;
			}
			return (write(1, &buffer[pos], lngth) + write(1, &buffer[1], x - 1));
		}
		else if (!(flags & F_MINUS) && pad == ' ')
		{
			if (xtra_chr)
			{
				buffer[--pos] = xtra_chr;
			}
			return (write(1, &buffer[1], x - 1) + write(1, &buffer[pos], lngth));
		}
		else if (!(flags & F_MINUS) && pad == '0')
		{
			if (xtra_chr)
			{
				buffer[--strt_pad] = xtra_chr;
			}
			return (write(1, &buffer[strt_pad], x - strt_pad) + write(1, &buffer[pos], lngth - (1 - strt_pad)));
		}
	}
	if (xtra_chr)
	{
		buffer[--pos] = xtra_chr;
	}
	return (write(1, &buffer[pos], lngth));
}

