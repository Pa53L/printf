#include "../h_HEAD/header.h"

char	*is_width(st_format *spec, char *p)
{
	spec->width = atoi(p);
	while (*p >= '0' && *p <= '9')
		p++;
	return (p);
}