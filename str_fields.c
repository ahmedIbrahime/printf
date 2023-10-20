#include "main.h"

/**
 * get_precision - get the precision from the format string.
 * @params: the parameters struct.
 * @args: the argument pointers.
 * @p: the argument pointer.
 *
 * Return: new pointer.
 */
char *get_precision(char *p, params_t *params, va_list args)
{
int d = 0;
if (*p != '.')
return (p);
p++;

if (*p == '*')
{
d = va_arg(args, int);
p++;
}
else
{
while (isdigit(*p))
d = d * 10 + (*p++ - '0');
}
params->precision = d;
return (p);
}
