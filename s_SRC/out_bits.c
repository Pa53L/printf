
#include "../h_HEAD/header.h"

size_t	out_bits(st_format *spec, unsigned long long unval)
{
	int strlen;
	int bit;
	int i;
	char *str;

	i = 0;
	if (unval <= 0xFF)
	{
		strlen = 8;
		bit = 7;
	}
	else if (unval > 0xFF && unval <= 0xFFFF)
	{
		strlen = 16;
		bit = 15;
	}
	else if (unval > 0xFFFF)
	{
		strlen = 32;
		bit = 31;
	}
	if (spec->width - strlen > 0)
	{
		spec->width = spec->width - strlen;
		strlen = strlen + spec->width;
	}
	else
		spec->width = 0;
	if (!(str = (char *)malloc(sizeof(char) * (strlen + spec->width + 1))))
		return (0);
	str[strlen] = '\0';
	if (spec->minus == 0 && spec->width)
	{
		while (spec->width)
		{
			str[i] = ' ';
			i++;
			spec->width--;
		}
	}
	while (bit >= 0)
	{
		if (unval & 1 << bit)
			str[i] = '1';
		else
			str[i] = '0';
		bit--;
		i++;
	}
	if (spec->minus == 1 && spec->width)
	{
		while (spec->width)
		{
			str[i] = ' ';
			i++;
			spec->width--;
		}
	}
	write(1, str, strlen);
	free(str);
	return (strlen);
}