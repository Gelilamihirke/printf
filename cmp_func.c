#include "main.h"
/**
 * cmp_func - return a function pointer to a matching function
 * @a: character input
 * Return: function pointer to a matching function
 */
int (*cmp_func(const char a))(va_list)
{
	myprintf printf[] = {
		{'c', print_char},
		{'s', peint_string},
		{'d', print_num},
		{'i', print_num},
		{'u', print_unsigned},
		{'b', print_bin},
		{'\0', NULL}
	};
	
	int j;

	for (j = 0; printf[j].p != '\0'; j++)
	{
		if (printf[j].p == a)
		{
			return (printf[j].func);
		}
	}
	return (0);
}
