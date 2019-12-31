
#include "../h_HEAD/header.h"

size_t	out_chr(st_format *spec, int ival)
{
	unsigned long strlen;
	unsigned long i;
	char *str;

	strlen = spec->width;
	if (strlen > 1)
	{
		str = (char*)malloc(sizeof(char) * (strlen));
		if (!str)
			return (0);
	}
	else
	{
		write(1, &ival, 1);
		return (1);
	}
	str[strlen - 1] = '\0';
	i = strlen - 1;
	if (spec->minus == 1)
	{
		while (i > 0)
		{
			str[i] = ' ';
			i--;
		}
	}
	str[i] = ival;
	i--;
	if (spec->minus == 0)
	{
		while (i > 0)
		{
			str[i] = ' ';
			i--;
		}
		str[i] = ' ';
	}
	write(1, str, strlen);
	free(str);
	return (strlen);
}