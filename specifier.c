#include "main.h"
/**
 * get_specifier - find the format function.
 * @s: format string.
 *
 * Return: number of bytes printed.
 */
int (*get_specifier(char *s)) (va_list args, params_t *params)
{
specifier_t specifier[] = {

{"c", pr_char},
{"d", pr_int},
{"i", pr_int},
{"s", pr_string},
{"%", pr_percent},
{"b", pr_bi},
{"o", pr_oct},
{"u", pr_unsigned},
{"x", pr_hex},
{"X", pr_HEX},
{"p", pr_address},
{"S", pr_S},
{"r", pr_reverse},
{"R", pr_rot13},
{NULL, NULL}
};

int i = 0;

while (specifier[i].specifier)
{
if (*s == specifier[i].specifier[0])
{
return (specifier[i].f);
}
i++;
}
return (NULL);
}

/**
 * get_pr_fun - finds the format function.
 * @s: format string.
 * @args: the list of args.
 * @params: the parameter strct
 *
 * Return: number of bytes printed.
 */

int get_pr_fun(char *s, va_list args, params_t *params)
{
int (*f)(va_list, params_t *) = get_specifier(s);
if (f)

return (f(args, params));
return (0);
}

/**
 * get_F - find the flag function.
 * @s: format string.
 * @params: the parameter strct.
 *
 * Return: if valid.
 */
int get_F(char *s, params_t *params)
{
int i = 0;

switch (*s)
{
case '+':
i = params->plus_f = 1;
break;
case ' ':
i = params->space_f = 1;
break;
case '#':
i = params->hashtag_f = 1;
break;
case '-':
i = params->minus_f = 1;
break;
case '0':
i = params->zero_f = 1;
break;
}
return (i);
}

/**
 * get_mod - find the modifier function.
 * @params: fthe parameter strct.
 * @s: format string
 *
 * Return: if valid.
 */

int get_mod(char *s, params_t *params)
{
int i = 0;

switch (*s)
{
case 'h':
i = params->h_mod = 1;
break;
case 'l':
i = params->l_mod = 1;
break;
}
return (i);
}

/**
 * get_width - get the width from the string
 * @params: fthe parameter struct.
 * @s: format string
 * @args: the list of args.
 *
 * Return: if valid.
 */
char *get_width(char *s, params_t *params, va_list args)
{
int d = 0;
if (*s == '*')
{
d = va_arg(args, int);
s++;
}
else
{
while (isdigit(*s))
d = d * 10 + (*s++ - '0');
}
params->width = d;
return (s);
}
