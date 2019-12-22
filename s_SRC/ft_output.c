/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:53:31 by yshawn            #+#    #+#             */
/*   Updated: 2019/12/22 18:43:59 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

size_t	ft_output(st_format *spec, va_list ap)
{
	size_t		len;
	char		*str; /* для STRING */
	long long	ival; /* для CHAR и ЧИСЕЛ */
	unsigned long long unval;

	len = 0;
	ival = 0;
	unval = 0;
	if (spec->type == 's')
	{
		str = va_arg(ap, char *);
		len = out_str(&spec[0], str);
	}
	else if (spec->type == 'c')
	{
		ival = (int)va_arg(ap, int);
		len = out_chr(&spec[0], ival);
	}
	else if (spec->type == 'd' || spec->type == 'i')
	{
		ft_cast_size(&spec[0], ap, &ival);
		len = out_di(&spec[0], ival);
	}
	else if (spec->type == 'p' || spec->type == 'x' || spec->type == 'X' || spec->type == 'o')
	{
		unval = va_arg(ap, uint64_t);
		len = ft_address(&spec[0], unval);
	}
	return (len);
}
