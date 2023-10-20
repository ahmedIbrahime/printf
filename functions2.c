#include "main.h"

/**
 * pr_hex - prints unsigned hex num lowercase.
 * @args: list of args
 * @params: parameters struct
 *
 * Return: the printed bytes
 */
int pr_hex(va_list args, params_t *params)
{
unsigned long l;
int c = 0;
char *str;

if (params->l_mod)
l = (unsigned long)va_arg(args, unsigned long);
else if (params->h_mod)
l = (unsigned short int)va_arg(args, unsigned int);
else
l = (unsigned int)va_arg(args, unsigned int);

str = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
if (params->hashtag_f && l)
{
*--str = 'x';
*--str = '0';
}
params->unsign = 1;
return (c += print_number(str, params));
}

/**
 * pr_HEX - prints unsigned hex num ppercase
 * @args: list of args
 * @params: parameters struct
 *
 * Return: the printed bytes
 */
int pr_HEX(va_list args, params_t *params)
{
unsigned long l;
int c = 0;
char *str;

if (params->l_mod)
l = (unsigned long)va_arg(args, unsigned long);
else if (params->h_mod)
l = (unsigned short int)va_arg(args, unsigned int);
else
l = (unsigned int)va_arg(args, unsigned int);

str = convert(l, 16, CONVERT_UNSIGNED, params);
if (params->hashtag_f && l)
{
*--str = 'X';
*--str = '0';
}
params->unsign = 1;
return (c += print_number(str, params));
}

/**
 * pr_bi - prints the unsugned binary num
 * @args: list of args.
 * @params: params struct
 *
 * Return: the printed bytes
 */
int pr_bi(va_list args, params_t *params)
{
unsigned int n = va_arg(args, unsigned int);
char *str = convert(n, 2, CONVERT_UNSIGNED, params);
int c = 0;

if (params->hashtag_f && n)
*--str = '0';
params->unsign = 1;
return (c += print_number(str, params));
}

/**
 * pr_oct - prints unsigned octal num.
 * @args: list of args
 * @params: params struct
 *
 * Return: the printed bytes
 */
int pr_oct(va_list args, params_t *params)
{
unsigned long l;
char *str;
int c = 0;

if (params->l_mod)
l = (unsigned long)va_arg(args, unsigned long);
else if (params->h_mod)
l = (unsigned short int)va_arg(args, unsigned int);
else
l = (unsigned int)va_arg(args, unsigned int);
str = convert(l, 8, CONVERT_UNSIGNED, params);

if (params->hashtag_f && l)
*--str = '0';
params->unsign = 1;
return (c += print_number(str, params));
}
