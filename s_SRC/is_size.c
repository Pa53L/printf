#include "../h_HEAD/header.h"

char	*is_size(int *size, char *p)
{
	if (*p == 'l')
	{
		*size = 1;
		if (*(p + 1) == 'l')
			*size = 2;
	}
	if (*p == 'h')
	{
		*size = 3;
		if (*(p + 1) == 'h')
			*size = 4;
	}
	if (*p == 'L')
		*size = 5;
	while (*p == 'l' || *p == 'L' || *p == 'h')
		p++;
	return (p);
}