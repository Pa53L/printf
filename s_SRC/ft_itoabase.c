#include "../h_HEAD/header.h"
#include <stdio.h>

char *ft_itoabase(uint64_t value, char *str, int len, int base, int bhex)
{
	char numbers[] = "0123456789abcdef";
	char bnumbers[] = "0123456789ABCDEF";
	int i;
	
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
			if (bhex)
				str[i] = bnumbers[value];
			else
				str[i] = numbers[value];
			value -= value;
		}
		else
		{
			if (bhex)
				str[i] = bnumbers[value % base];
			else
				str[i] = numbers[value % base];
		}
		value /= base;
		i--;
	}
	return (str);
}