/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:53:31 by yshawn            #+#    #+#             */
/*   Updated: 2019/12/24 00:23:13 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

size_t	ft_output(st_format *spec, va_list ap)
{
	size_t					len;
	char					*str;
	long long				ival;
	unsigned long long		unval;

	len = 0;
	ival = 0;
	unval = 0;
	str = NULL;
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
	// НЕ ЗАБЫТЬ ПРО ЭТУ ХУЙНЮ
	/*
	else if (spec->type == '%')
		len = out_per(&spec[0]);
	*/
	return (len);
}