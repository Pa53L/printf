
#include "../h_HEAD/header.h"

size_t	out_chr(st_format *spec, int ival)
{
	size_t len;

	if (spec->width)
		spec->width--;
	if (spec->minus == 0)
	{
		len = spec->width + 1;
		while (spec->width--)
			write(1, " ", 1);
		write(1, &ival, 1);
	}
	else if (spec->minus == 1)
	{
		len = spec->width + 1;
		write(1, &ival, 1);
		while (spec->width--)
			write(1, " ", 1);
	}
	return (len);
}
