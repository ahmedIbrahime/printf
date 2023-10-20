#include "main.h"
/**
 * _printf - prints characters based on a formatted string.
 * @format: the formatted string containing characters and specifiers.
 * Return: the number of characters printed.
 */
int _printf(const char *format, ...)
{
int char_pr = 0;
va_list args;
char *p, *start;
params_t params = PARAMS_INT;
va_start(args, format);
if (!format || (format[0] == '%' && !format[1]))
return (-1);
if (format[0] == '%' && format[1] == ' ' && !format[2])
return (-1);
for (p = (char *)format; *p; p++)
{
init_params(&params, args);
if (*p != '%')
{
char_pr += _putchar(*p);
continue;
}
start = p;
p++;
while (get_F(p, &params))
{
p++;
}
p = get_width(p, &params, args);
p = get_precision(p, &params, args);
if (get_mod(p, &params))
p++;
if (!get_specifier(p))
char_pr += pr_from_to(start, p, params.l_mod || params.h_mod ? p - 1 : 0);
else
{
if (*p == 'd' || *p == 'i' || *p == 'p' || *p == 'u'
|| *p == 'o' || *p == 'x' || *p == 'X')
params.plus_f = 1;
char_pr += get_pr_fun(p, args, &params);
}
}
_putchar(BUF_FLU);
va_end(args);
return (char_pr);
}
