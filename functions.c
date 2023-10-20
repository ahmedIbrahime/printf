#include "main.h"

/**
 * pr_char - prints a char
 * @args: list of arguments.
 * @params: params struct
 *
 * Return: the printed number of characters
 */
int pr_char(va_list args, params_t *params)
{
char pad_char = ' ';
unsigned int pad = 1, char_pr = 0, ch = va_arg(args, int);

if (params->minus_f)
char_pr += _putchar(ch);
if (isprint(ch) || ch == '\n' || ch == '\t')
{
while (pad++ < params->width)
char_pr += _putchar(pad_char);
if (!params->minus_f)
char_pr += _putchar(ch);
}
else
{
char_pr += _putchar('\\');
char_pr += _putchar('x');
char_pr += _putchar((ch / 16) < 10 ? (ch / 16) + '0' : (ch / 16) - 10 + 'A');
char_pr += _putchar((ch % 16) < 10 ? (ch % 16) + '0' : (ch % 16) - 10 + 'A');
}

return char_pr;
}

/**
 * pr_int - prints a int
 * @args: list of arguments.
 * @params: params struct
 *
 * Return: the printed number of chars
 */
int pr_int(va_list args, params_t *params)
{
long long ll;

if (params->l_mod)
ll = va_arg(args, long);
else if (params->h_mod)
ll = (short int)va_arg(args, int);
else
ll = (int)va_arg(args, int);
return (print_number(convert(ll, 10, 0, params), params));
}

/**
 * pr_string - prints the string
 * @args: list of arguments.
 * @params: params struct
 *
 * Return: the printed number of chars
 */
int pr_string(va_list args, params_t *params)
{
char *str = va_arg(args, char *), pad_char = ' ';
unsigned int pad = 0, char_pr = 0, i = 0, j;

(void)params;
switch ((int)!str)
case 1:
str = NULL_STR;

j = pad = strlen(str);
if (params->precision < pad)
j = pad = params->precision;

if (params->minus_f)
{
if (params->precision != UINT_MAX)
for (i = 0; i < pad; i++)
char_pr += _putchar(*str++);
else
char_pr += _puts(str);
}
while (j++ < params->width)
char_pr += _putchar(pad_char);
if (!params->minus_f)
{
if (params->precision != UINT_MAX)
for (i = 0; i < pad; i++)
char_pr += _putchar(*str++);
else
char_pr += _puts(str);
}
return (char_pr);
}

/**
 * pr_percent - prints the string
 * @args: list of arguments.
 * @params: params struct
 *
 * Return: the printed number of chars
 */
int pr_percent(va_list args, params_t *params)
{
(void)args;
(void)params;
return (_putchar('%'));
}

/**
 * print_S - custom format specifier
 * @params: params struct
 * @args: list of arguments.
 *
 * Return: the printed number of chars
 */
int pr_S(va_list args, params_t *params)
{
char *str = va_arg(args, char *);
char *hex;
int char_pr = 0;

if ((int)(!str))
return (_puts(NULL_STR));
for (; *str; str++)
{
if ((*str > 0 && *str < 32) || *str >= 127)
{
char_pr += _putchar('\\');
char_pr += _putchar('x');
hex = convert(*str, 16, 0, params);
if (!hex[1])
char_pr += _putchar('0');
char_pr += _puts(hex);
}
else
{
char_pr += _putchar(*str);
}
}
return (char_pr);
}
