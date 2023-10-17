#include "main.h"

void print_buffer(char buffer[], int *buff_pos);

/**
 * _printf -> the  Printf function.
 * @format: will format the data.
 * Return: will be  Printed characters.
 */
int _printf(const char *format, ...)
{
	int x,flags,wdth,prcsion,size;
	int print = 0,chars_printed = 0,buff_pos = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
	{
		return (-1);
	}
	va_start(list, format);

	for (x = 0; format && format[x] != '\0'; x++)
	{
		if (format[x] != '%')
		{
			buffer[buff_pos++] = format[x];
			
			if(buff_pos == BUFF_SIZE)
			{
				print_buffer(buffer, &buff_pos);
			}
			chars_printed++;
		}
		else
		{
			print_buffer(buffer, &buff_pos);
			flags = get_flags(format, &x);
			wdth = get_width(format, &x, list);
			prcsion = get_precision(format, &x, list);
			size = get_size(format, &x);
			++x;
			
			print = handle_print(format, &x, list, buffer,flags, wdth, prcsion, size);
			
			if (print == -1)
			{
				return (-1);
			}
			chars_printed += print;
		}
	}

	print_buffer(buffer, &buff_pos);

	va_end(list);

	return (chars_printed);
}


/**
 * print_buffer -> must print the contents of the buffer if it exist.
 * @buffer:the array of characters.
 * @buff_pos: the position at which to add the next character.
 */
void print_buffer(char buffer[], int *buff_pos)
{
	if (*buff_pos > 0)
	{
		write(1, &buffer[0], *buff_pos);
	}
	*buff_pos = 0;
}
