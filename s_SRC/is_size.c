#include "../h_HEAD/header.h"

char	*is_size(st_format *spec, char *p)
{
	if(*p == 'l' || *p == 'L' || *p == 'h')
	{
		if (*p == 'l')
		{
			spec->size = 1;
			if (*(p + 1) == 'l')
				spec->size = 2;
		}
		if (*p == 'h')
		{
			spec->size = 3;
			if (*(p + 1) == 'h')
				spec->size = 4;
		}
		if (*p == 'L')
			spec->size = 5;
		while (*p == 'l' || *p == 'L' || *p == 'h')
			p++;
	}
	return (p);
}