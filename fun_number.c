#include "main.h"
/**
 * convert - converter function.
 * @num: number.
 * @base: base.
 * @flags: arg flags.
 * @params: parameter struct.
 * Return: string.
 */
char *convert(long int num, int base, int flags, params_t *params)
{
static char *array;
static char buffer[50];
char sign = 0;
char *ptr;
unsigned long n = num;
(void)params;

if (!(flags & CONVERT_UNSIGNED) && num < 0)
{
n = num;
sign = '-';
}
array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
ptr = &buffer[49];
*ptr = '\0';

do {
*--ptr = array[n % base];
n /= base;
} while (n != 0);

if (sign)
*++ptr = sign;
return (ptr);
}

/**
 * pr_unsigned - prints unsigned integer num.
 * @args: argument function.
 * @params: the parameter struct.
 * Return: bytes printed.
 */

int pr_unsigned(va_list args, params_t *params)
{
unsigned long l;
if (params->l_mod)
l = (unsigned long)va_arg(args, unsigned long);
else if (params->h_mod)
l = (unsigned short int)va_arg(args, unsigned int);
else
l = (unsigned int)va_arg(args, unsigned int);
params->unsign = l;
return (print_number(convert(l, 10, CONVERT_UNSIGNED, params), params));
}

/**
 * pr_address - prints address.
 * @args: argument function.
 * @params: the parameter struct.
 *
 * Return: bytes printed.
 */
int pr_address(va_list args, params_t *params)
{
unsigned long int n = va_arg(args, unsigned long int);
char *str;

if (!n)
return (_puts("(nil)"));

str = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
*--str = 'x';
*--str = '0';
return (print_number(str, params));
}
