
#include "../h_HEAD/header.h"

long long int	ft_numlen(long long int num, int base)
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
