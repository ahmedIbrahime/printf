#include "main.h"
/**
 * pr_from_to - prints range of char address.
 * @start: starting address
 * @stop: endning address.
 * @expt: expected adress.
 *
 * Return: the number of bytes printed.
 */

int pr_from_to(char *start, char *stop, char *expt)
{
int char_pr = 0;
while (start <= stop)
{
if (start != expt)
char_pr += _putchar(*start);
start++;
}
return (char_pr);
}

/**
 * pr_reverse - reverse the string and print it .
 * @args: the list of args.
 * @params: the parameter struct
 *
 * Return: number of bytes printed.
 */
int pr_reverse(va_list args, params_t *params)
{
int len, char_pr = 0;
char *str = va_arg(args, char *);
(void)params;

if (str)
{
for (len = 0; *str; str++)
len++;
str--;
for (; len > 0; len--, str++)
char_pr += _putchar(*str);
}
return (char_pr);
}

/**
 * pr_rot13 - print string in rot13.
 * @args: the list of args.
 * @params: the parameter struct
 *
 * Return: number of bytes printed.
 */
int pr_rot13(va_list args, params_t *params)
{
int i, index;
int count = 0;
char arr[] =
"NOPQRSTUVWXYZABCDEFGHIJKLM             nopqrstuvwxyzabcdefghijklm";
char *a = va_arg(args, char *);
(void)params;
i = 0;
index = 0;
while (a[i])
{
if ((a[i] >= 'A' && a[i] <= 'Z')
|| (a[i] >= 'a' && a[i] <= 'z'))
{
index = a[i] - 65;
count += _putchar(arr[index]);
}
else
count += _putchar(a[i]);
i++;
}
return (count);
}
