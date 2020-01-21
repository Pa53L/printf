/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_di.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 20:39:02 by yshawn            #+#    #+#             */
/*   Updated: 2019/12/24 00:05:09 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

void	parse_dipoxu_case(st_format *spec, uint64_t unval, int *len)
{
	if (spec->zero)
		if (spec->accur >= 0)
			spec->zero = 0;
	if (spec->accur >= 0)
		parse_dipoxu_accur(spec, unval, len);
	if (spec->sharp || spec->type == 'p')
		parse_dipoxu_sharp(spec, unval);
	if (spec->plus)
		parse_dipoxu_plus(spec);
	if (spec->space)
		parse_dipoxu_space(spec, *len);
	if (spec->width)
		parse_dipoxu_width(spec, *len);
	return ;
}

int		parse_dipoxu(st_format *spec, va_list vl)
{
	int			len;
	int64_t		ival;
	uint64_t	unval;

	ival = 0;
	unval = 0;
	if (spec->type == 'd' || spec->type == 'i')
	{
		ft_cast_size_di(spec, vl, &ival);
		if (ival < 0)
			(unval = ival * (-1));
		else
			(unval = ival);
	}
	else
		ft_cast_size_poxu(spec, vl, &unval);
	len = ft_numlen(unval, spec->base);
	parse_dipoxu_case(spec, unval, &len);
	return (parse_num(spec, unval, len));
}
