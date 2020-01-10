#include "../h_HEAD/header.h"

char *is_accuracy(int *accur, va_list ap, char *p)
{
	*accur = 0;
	if (*(p + 1))
		p++;
	*accur += atoi(p);
	if (*p == '*')
	{
		*accur = va_arg(ap, int);
		p++;
	}
	else
		while (*p >= '0' && *p <= '9')
			p++;
	return (p);
}