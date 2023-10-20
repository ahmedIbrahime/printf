#include "main.h"

/**
 * init_params - clears struct fields and rest buf.
 * @params: the parameters struct.
 * @args: the arguments pointer
 *
 * Return: void
 */
void init_params(params_t *params, va_list args)
{
	params->unsign = 0;

	params->plus_f = 0;
	params->space_f = 0;
	params->hashtag_f = 0;
	params->zero_f = 0;
	params->minus_f = 0;

	params->width = 0;
	params->precision = UINT_MAX;

	params->h_mod = 0;
	params->l_mod = 0;
	(void)args;
}
