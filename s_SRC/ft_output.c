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
	size_t		len;
	char		*str; /* для STRING */
	long long	ival; /* для CHAR и ЧИСЕЛ */
	unsigned long long		unval;

	len = 0;
	ival = 0;
	unval = 0;
	str = NULL;
	if (spec->type == 1)
	{
		ival = (int)va_arg(ap, int);
		len = out_chr(&spec[0], ival);
	}
	else if (spec->type == 2)
	{
		str = va_arg(ap, char *);
		len = out_str(&spec[0], str);
	}
	else if (spec->type == 8 || spec->type == 10 || spec->type == 16)
	{
		if (spec->type == 10)
		{
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
		else
		{
			ft_cast_size_poxu(&spec[0], ap, &unval);
			len = parse_dipoxu(&spec[0], unval);
		}
		
	}
	return (len);
}
