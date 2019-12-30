#include "../h_HEAD/header.h"

void	ft_myitoa(unsigned long long ival, char *str, int base, int len)
{
	while (ival > 0)
	{
		if (ival < base)
		{
			str[len] = ITOA[ival];
			return ;
			//ival = ival - ival;
		}
		else
			str[len] = ITOA[ival % base];
		ival = ival / base;
		len--;
	}
	return ;
}