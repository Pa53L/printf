
#include "../h_HEAD/header.h"

size_t	ft_numlen(long long num, int base)
{
	size_t i;
	
	i = 0;

	if (num == 0)
		return (1);
	if (num < 0)
	{
		num *= -1;
		i++;
	}
	while (num)
	{
		num /= base;
		i++;
	}
	return (i);
}
