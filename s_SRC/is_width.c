#include "../h_HEAD/header.h"

char	*is_width(int *width, va_list ap, char *p)
{
	*width = atoi(p);
	if (*p == '*')
	{
		*width = va_arg(ap, int);
		p++;
	}
	else
		while (*p >= '0' && *p <= '9')
			p++;
	return (p);
}