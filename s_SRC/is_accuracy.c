#include "../h_HEAD/header.h"

char *is_accuracy(int *accur, char *p)
{
	*accur = 0;
	if (*(p + 1))
		p++;
	*accur += atoi(p);
	while (*p >= '0' && *p <= '9')
		p++;
	return (p);
}