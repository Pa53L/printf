#include "../h_HEAD/header.h"
#include <stdio.h>

char *ft_itoabase(uint64_t value, int base, char *str)
{
	char numbers[] = "0123456789abcdef";
	int i;
	size_t len;
	
	len = ft_numlen(value, base);
	i = len - 1;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	if (value == 0)
	{
		str[0] = '0';
		return (str);
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
