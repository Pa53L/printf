
#include "../h_HEAD/header.h"

size_t	out_di(st_format_spec *spec, int ival)
{
	size_t len;
	size_t tmp_len;

	tmp_len = 0;
	len = ft_numlen(ival, 10);
	if (spec->minus)
		spec->zero = 0;
	if (spec->accuracy)
	{
		if (spec->accuracy > len)
			spec->accuracy = spec->accuracy - len;
		else
			spec->accuracy = 0;
	}
	if(spec->width)
	{
		if(spec->width > len + spec->accuracy)
			spec->width = spec->width - spec->accuracy - len;
		else
			spec->width = 0;
		if (spec->width > 1)
			spec->space = 0;
	}
	if (spec->plus)
	{
		spec->space = 0;
		if (spec->width > 0)
			spec->width--;
	}
	tmp_len = spec->width + spec->accuracy;

	/* непосредственно, вывод */

	if (spec->minus == 0)
	{
		while (spec->width > 0)
		{
			write(1, " ", 1);
			spec->width--;
		}
		if (spec->plus)
		{
			tmp_len++;
			write(1, "+", 1);
		}
		while (spec->accuracy)
		{
			write(1, "0", 1);
			spec->accuracy--;
		}
		if (spec->space)
		{
			write(1, " ", 1);
			tmp_len++;
		}
		ft_putnbr(ival);
	}
	if (spec->minus == 1)
	{
		if (spec->plus)
		{
			tmp_len++;
			write(1, "+", 1);
		}
		while (spec->accuracy)
		{
			write(1, "0", 1);
			spec->accuracy--;
		}
		if (spec->space && spec->width <= 0)
		{
			write(1, " ", 1);
			tmp_len++;
		}
		ft_putnbr(ival);
		while (spec->width > 0)
		{
			write(1, " ", 1);
			spec->width--;
		}
	}
	return (len + tmp_len);
}
