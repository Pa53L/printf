#include "../h_HEAD/header.h"

char	*ft_itoabase(unsigned long long value, char *str, int base)
{
	int i;
	int len;
	
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
			str[i] = ITOA[value];
			value -= value;
		}
		else
			str[i] = ITOA[value % base];
		value /= base;
		i--;
	}
	return (str);
}