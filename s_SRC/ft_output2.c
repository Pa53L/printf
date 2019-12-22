#include "../h_HEAD/header.h"

size_t	ft_output2(st_format *spec, va_list ap)
{
	char *str; /* для STRING */
	int ival; /* для CHAR и INT */
	uint64_t lval;
	size_t length;
	size_t temp_length;

	temp_length = 0;
	length = 0;
	if (spec->type == 'p' || spec->type == 'x' || spec->type == 'X' || spec->type == 'o')
	{
		lval = va_arg(ap, uint64_t);
		length = ft_address(&spec[0], lval);
	}

	return (length + temp_length);
}