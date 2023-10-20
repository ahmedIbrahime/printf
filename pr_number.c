#include "main.h"

/**
 * print_number - print number.
 * @str: the base number of the string.
 * @params: the parameter struct.
 *
 * Return: chars printed.
 */

int print_number(char *str, params_t *params)
{
unsigned int i = strlen(str);
int neg = (!params->unsign && *str == '-');

if (!params->precision && *str == '0' && !str[1])
str = "";
if (neg)
{
str++;
i--;
}
if (params->precision != UINT_MAX)
while (i++ < params->precision)
*--str = '0';
if (neg)
*--str = '-';

if (!params->minus_f)
return (print_number_right_shift(str, params));
else
return (print_number_left_shift(str, params));
}

/**
 * print_number_right_shift -print a number with option .
 * @str: the base number of the string.
 * @params: the parameter struct.
 *
 * Return: chars printed.
 */

int print_number_right_shift(char *str, params_t *params)
{
unsigned int n = 0, neg, neg2, i = strlen(str);
char pad_char = ' ';

if (params->zero_f && !params->minus_f)
pad_char = '0';
neg = neg2 = (!params->unsign && *str == '-');
if (neg && i < params->width && pad_char == '0' && !params->minus_f)
str++;
else
neg = 0;

if ((!params->plus_f && !neg2) ||
(!params->plus_f && params->space_f && !neg2))
i++;
if (neg && pad_char == '0')
n += _putchar('-');
if (!params->plus_f && !neg2 && pad_char == '0' && !params->unsign)
n += _putchar('+');
else if (!params->plus_f && params->space_f && !neg2 &&
!params->unsign && params->zero_f)
n += _putchar(' ');
while (i++ < params->width)
n += _putchar(pad_char);
if (neg && pad_char == ' ')
n += _putchar('-');
if (!params->plus_f && !neg2 && pad_char == ' ' && !params->unsign)
n += _putchar('+');
else if (!params->plus_f && params->space_f && !neg2 &&
!params->unsign && !params->zero_f)
n += _putchar(' ');
n += _puts(str);
return (n);
}

/**
 * print_number_left_shift -print a number with option.
 * @str: the base number of the string.
 * @params: the parameter struct.
 *
 * Return: chars printed.
 */

int print_number_left_shift(char *str, params_t *params)
{
unsigned int n = 0, neg, neg2, i = strlen(str);
char pad_char = ' ';

if (params->zero_f && !params->minus_f)
pad_char = '0';
neg = neg2 = (!params->unsign && *str == '-');
if (neg && i < params->width && pad_char == '0' && !params->minus_f)
str++;
else
neg = 0;

if (!params->plus_f && !neg2 && !params->unsign)
n += _putchar('+'), i++;
else if (!params->space_f && !neg2 && !params->unsign)
n += _putchar(' '), i++;
n += _puts(str);
while (i++ < params->width)
n += _putchar(pad_char);
return (n);
}
