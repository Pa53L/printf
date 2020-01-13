/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:53:31 by yshawn            #+#    #+#             */
/*   Updated: 2020/01/13 23:57:45 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

size_t	parse_output(st_format *spec, va_list ap, va_list first_ap)
{
	unsigned long long		unval;
	long long				ival;
	char					*str;
	size_t					len;
	int dollar;

	len = 0;
	ival = 0;
	unval = 0;
	dollar = 0;
	str = NULL;

	/* FOR $
	if (spec->dollar > 1)
	{
		dollar = spec->dollar;
		while (dollar > 1)
		{
			va_arg(ap, int);
			dollar--;
		}
	}
	*/
	if (spec->type == 'c')
	{
		ival = (int)va_arg(ap, int);
		len = out_chr(&spec[0], ival);
	}
	else if (spec->type == 's')
	{
		str = va_arg(ap, char *);
		len = out_str(&spec[0], str);
	}
	else if (spec->type == 'd' || spec->type == 'i')
	{
		spec->numsys = 10;
		ft_cast_size_di(&spec[0], ap, &ival);
		if (ival < 0)
		{
			unval = ival * (-1);
			spec->sign = 1;
		}
		else
			unval = ival;
		len = parse_dipoxu(&spec[0], unval);
	}
	else if (spec->type == 'o' || spec->type == 'x' || spec->type == 'X' ||
			 spec->type == 'u' || spec->type == 'p')
	{
		if (spec->type == 'o')
			spec->numsys = 8;
		else if (spec->type == 'u')
			spec->numsys = 10;
		else
			spec->numsys = 16;

		ft_cast_size_poxu(&spec[0], ap, &unval);
		len = parse_dipoxu(&spec[0], unval);
	}
	else if (spec->type == 'b')
	{
		unval = va_arg(ap, unsigned long long);
		len = out_bits(&spec[0], unval);
	}
	else if (spec->type == '%')
		len = out_per(&spec[0]);
	else if (spec->type == '\0')
		return (0);

	/* FOR $
	if (spec->dollar == 0)
		va_copy(first_ap, ap);
	else
	va_copy(ap, first_ap);
	*/
	return (len);
}
