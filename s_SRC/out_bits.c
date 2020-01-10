
#include "../h_HEAD/header.h"

size_t	out_bits(st_format *spec, unsigned long long unval)
{
	int strlen;
	int bit;
	int i;
	char *str;

	printf("%lld\n", unval);
	if (unval <= 255)
		strlen = 8;
	else if (unval > 255 && unval <= 65535)
		strlen = 16;
	else if (unval < 4294967296)
	//4294967280
		strlen = 32;
	else
		strlen = 64;
	str = (char *)malloc(sizeof(char) * (strlen + 1));
	if (!str)
		return (0);
	str[strlen] = '\0';
	bit = strlen - 1;
	i = 0;
	while (bit >= 0)
	{
		if (unval & 1 << bit)
			str[i] = '1';
		else
			str[i] = '0';
		bit--;
		i++;
	}
	printf("%s", str);
	free(str);
	return (0);
}