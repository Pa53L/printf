#include "../h_HEAD/header.h"

char	*is_width(st_format *spec, va_list ap, char *p)
{
	spec->width = atoi(p);
	if (*p == '*')
	{
		spec->width = va_arg(ap, int);
		p++;
	}
	else
		while (*p >= '0' && *p <= '9')
			p++;
	if (*p == '$')
	{
		spec->dollar = spec->width;
		spec->width = 0;
		p++;
	}
	return (p);
}