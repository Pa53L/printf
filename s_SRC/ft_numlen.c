
#include "../h_HEAD/header.h"

int	ft_numlen(unsigned long long num, int base)
{
	int i;
	
	i = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num /= base;
		i++;
	}
	return (i);
}
