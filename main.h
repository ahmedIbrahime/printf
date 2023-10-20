#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <limits.h>

#define CONVERT_LOWERCASE  1
#define CONVERT_UNSIGNED   2
#define OUTPUT_BUF_SIZE 1024
#define BUF_FLU -1
#define ABS(x) ((x) < 0 ? -(x) : (x))

#define NULL_STR "(null)"

#define PARAMS_INT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

/**
 * struct parameters - parameters.
 * @unsign: unsign.
 * @plus_f: plus_F.
 * @space_f: space_F
 * @hashtag_f: hashtag_F
 * @zero_f: zero_F
 * @minus_f: plus_F
 * @width: width
 * @precision: precision
 * @h_mod: h_mod
 * @l_mod: l_mod
 */
typedef struct parameters
{
unsigned int unsign     : 1;

unsigned int plus_f     : 1;
unsigned int space_f    : 1;
unsigned int hashtag_f  : 1;
unsigned int zero_f     : 1;
unsigned int minus_f    : 1;

unsigned int width;
unsigned int precision;

unsigned int h_mod      : 1;
unsigned int l_mod      : 1;
} params_t;

/**
 * struct specifier - struct token .
 * @specifier: format token.
 * @f: the function associated
 */
typedef struct specifier
{
char *specifier;
int (*f)(va_list, params_t *);
} specifier_t;


/* _printf.c */
int _printf(const char *format, ...);

/* __putchar.c */
int _putchar(int c);
int _puts(char *str);

/* functions.c */
int pr_int(va_list args, params_t *params);
int pr_string(va_list args, params_t *params);
int pr_percent(va_list args, params_t *params);
int pr_char(va_list args, params_t *params);
int pr_S(va_list args, params_t *params);

/* fun_number.c */
char *convert(long int num, int base, int flags, params_t *params);
int pr_unsigned(va_list args, params_t *params);
int pr_address(va_list args, params_t *params);

/* functions2.c */
int pr_hex(va_list args, params_t *params);
int pr_HEX(va_list args, params_t *params);
int pr_bi(va_list args, params_t *params);
int pr_oct(va_list args, params_t *params);

/* functions3.c */
int pr_from_to(char *start, char *stop, char *expt);
int pr_reverse(va_list args, params_t *params);
int pr_rot13(va_list args, params_t *params);

/* specifier.c */
int (*get_specifier(char *s)) (va_list args, params_t *params);
int get_pr_fun(char *s, va_list args, params_t *params);
int get_F(char *s, params_t *params);
int get_mod(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list args);

/* pr_number.c */
int print_number(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);

/* params.c */
void init_params(params_t *params, va_list args);

/* str_fields.c */
char *get_precision(char *p, params_t *params, va_list args);

#endif
