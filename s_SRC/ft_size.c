#include "../h_HEAD/header.h"

int		ft_size(long long n, int base)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (12);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n = n / base;
		len++;
	}
	return (len);
}