#include "main.h"

/**
 * append_hexa_code ->MUST append an ascci in hexadecimal code to buffer.
 * @buffer:the array containing chars.
 * @pos: the position at which to start appending.
 * @ascii_code: the ASSCI CODE container.
 * Return: must  Always be 3.
 */
int append_hexa_code(char ascii_code, char buffer[], int pos)
{
	char drct_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
	{
		ascii_code *= -1;
	}
	buffer[pos++] = '\\';
	buffer[pos++] = 'x';
	buffer[pos++] = drct_to[ascii_code / 16];
	buffer[pos] = drct_to[ascii_code % 16];

	return (3);
}


/**
 * is_printable ->MUST evaluate if a character is printable or not.
 * @chr: the character to be evaluated.
 * Return: 1 is for if c is printable & 0 if it is otherwise.
 */
int is_printable(char chr)
{
	if (chr >= 32 && chr < 127)
	{
		return (1);
	}
	return (0);
}


/**
 * is_digit ->MUST Verify if a character is a digit or not.
 * @chr: the  character passed to be evaluated.
 * Return: if c is a digit =1 or else is =0.
 */
int is_digit(char chr)
{
	if (chr >= '0' && chr <= '9')
	{
		return (1);
	}

	return (0);
}



/**
 * convert_size_unsgnd ->Must cast a number to the specified size
 * @numbr: the passed number to be casted.
 * @size_type: Number indicating the size of the number to be casted.
 * Return: must be the casted value of numbr.
 */
long int convert_size_unsgnd(unsigned long int numbr, int size_type)
{
	if (size_type == S_LONG)
	{
		return (numbr);
	}
	else if (size_type == S_SHORT)
	{
		return ((unsigned short)numbr);
	}
	return ((unsigned int)numbr);
}

/**
 * convert_size_number ->MUST cast a number to the specified size.
 * @numbr: the passed number to be casted.
 * @size_type: Number indicating the size of the number to be casted.
 * Return: must be the casted value of numbr.
 */
long int convert_size_number(long int numbr, int size_type)
{
	if (size_type == S_LONG)
	{
	return (numbr);
	}
	else if (size_type == S_SHORT)
	{
		return ((short)numbr);
	}
	return ((int)numbr);
}
