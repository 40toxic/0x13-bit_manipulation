#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_string - Print the string
 * @args: Where the string is
 * @sep: Seperator for strings
 */
void print_string(va_list args, char *sep)
{
	char *string;

	string = va_arg(args, char *);
	if (string == NULL)
		string = "(nil)";
	printf("%s%s", sep, string);
}

/**
 * print_char - Print the char
 * @args: Where the char is
 * @sep: Seperator for strings
 */
void print_char(va_list args, char *sep)
{
	printf("%s%c", sep, va_arg(args, int));
}

/**
 * print_int - Print the int
 * @args: Where the int is
 * @sep: Seperator for strings
 */
void print_int(va_list args, char *sep)
{
	printf("%s%d", sep, va_arg(args, int));
}

/**
 * print_float - Print the float
 * @args: Where the float is
 * @sep: Seperator for strings
 */
void print_float(va_list args, char *sep)
{
	printf("%s%f", sep, va_arg(args, double));
}

/**
 * print_all - Print any type of given argument
 * @format: List of types of arguments being passed
 */
void print_all(const char * const format, ...)
{
	va_list args;
	char *sep;
	print_form_t print_form[] = {
		{"c", print_char},
		{"i", print_int},
		{"f", print_float},
		{"s", print_string}
	};
	int i, j;

	va_start(args, format);
	i = 0;
	sep = "";
	while (format != NULL && format[i] != '\0')
	{
		j = 0;
		while (j < 4)
		{
			if (*print_form[j].c == format[i])
			{
				print_form[j].f(args, sep);
				sep = ", ";
			}
			j++;
		}
		i++;
	}
	printf("\n");
	va_end(args);
}
