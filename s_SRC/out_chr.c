
#include "../h_HEAD/header.h"

size_t	out_chr(st_format *spec, int ival)
{
	size_t len;

	char *str_width;

	str_width = NULL;
	if (spec->width > 0)
		spec->width--;
	if (spec->width)
		str_width = ft_strnew_width(&spec[0]);
	len = spec->width + 1;
	if (spec->width && spec->minus == 0)
		write(1, str_width, spec->width);
	write(1, &ival, 1);
	if (spec->width && spec->minus == 1)
		write(1, str_width, spec->width);
	if (str_width)
		free(str_width);
	return (len);
}