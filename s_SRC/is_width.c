#include "../h_HEAD/header.h"

char	*is_width(int *is_width, char *p)
{
	*is_width = atoi(p);
	while (*p >= '0' && *p <= '9')
		p++;
	return (p);
}