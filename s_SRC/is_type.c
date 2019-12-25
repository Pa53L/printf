#include "../h_HEAD/header.h"

char	*is_type(st_format *spec, char *p)
{
	int i;

	i = 0;
	while (i < 10)
	{
		if (*p == TYPES[i])
			spec->type = *p;
		i++;
	}
	return (p);
}