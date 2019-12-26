#include "../h_HEAD/header.h"

char *is_accuracy(st_format *spec, char *p)
{
	spec->accur = 0;
	if (*(p + 1))
		p++;
	spec->accur += atoi(p);
	while (*p >= '0' && *p <= '9')
		p++;
	return (p);
}