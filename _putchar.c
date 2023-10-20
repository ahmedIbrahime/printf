#include "main.h"

/**
 * _putchar - writes a character in the screen.
 * @c: the selected char
 *
 * Return: 1 on seccess and -1 on error.
 */
int _putchar(int c)
{
static int i;
static char buf[OUTPUT_BUF_SIZE];

if (c == BUF_FLU || i > OUTPUT_BUF_SIZE)
{
write(1, buf, i);
i = 0;
}
if (c != BUF_FLU)
buf[i++] = c;
return (1);
}

/**
 * _puts - writes a string.
 * @str: pointer to the string.
 * Return: number of the chars.
 */
int _puts(char *str)
{
char *a = str;
while (*str)
{
_putchar(*str++);
}
return (str - a);
}
