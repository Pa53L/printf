#include "../h_HEAD/header.h"
#include <stdio.h>

char *ft_itoabase(uint64_t value, int base, char *str)
{
	char numbers[] = "0123456789abcdef";
	int i;
	size_t len;
	
	len = ft_size(value, base);
	i = len - 1;
	if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	if (value < 0)
	{
		if (value == -2147483648)
			return (ft_strdup("-2147483648"));
		str[0] = '-';
		value *= -1;
	}
	while (value > 0)
	{
		
		if (value < base)
		{
			str[i] = numbers[value];
			value -= value;
		}
		else
			str[i] = numbers[value % base];
		value /= base;
		i--;
	}
	return (str);
}
