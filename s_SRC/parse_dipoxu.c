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

size_t	parse_dipoxu(st_format *spec, va_list vl)
{
	int len;
	int64_t					ival;
	uint64_t				unval;
	size_t tmp_len;

	tmp_len = 0;
	ival = 0;
	unval = 0;

	if (spec->type == 'd' || spec->type == 'i')
	{
		ft_cast_size_di(spec, vl, &ival);
		(ival < 0) ? (unval = ival * (-1)) : (unval = ival);
	}
	else
		ft_cast_size_poxu(spec, vl, &unval);

	/* start of parse format */
	len = ft_numlen(unval, spec->numsys);
	/* ZERO */
	if (spec->zero)
	{
		if (spec->accur >= 0)
			spec->zero = 0;
	}
	/* ACCUR */
	if (spec->accur >= 0)
	{
		if (spec->accur == 0 && unval == 0)
			len = 0;
		if (spec->accur > len)
			spec->accur = spec->accur - len;
		else
			spec->accur = 0;
	}
	/* SHARP EBANYI */
	if (spec->sharp || spec->type == 'p')
	{
		if (spec->type == 'o')
		{
			if (unval == 0 && spec->accur != 0)
				spec->sharp = 0;
			else
				spec->sharp = 1;
		}
		if ((spec->accur == 0 && unval == 0 && spec->type != 'o') || (unval == 0 && spec->type != 'o') || (spec->accur > 0 && spec->type == 'o'))
			spec->sharp = 0;
		if (spec->type == 'p')
			spec->sharp = 2;
	}
	/* PLUS */
	if (spec->plus)
	{
		if (spec->type == 'u')
			spec->plus = 0;
		if (spec->sign == 1)
			spec->plus = 0;
	}
	/* SPACE */
	if (spec->space)
	{
		if (spec->type == 'u')
			spec->space = 0;
		if (spec->plus || spec->sign)
			spec->space = 0;
		if (spec->width > len + spec->accur && spec->accur != -1 && spec->minus == 0 && spec->zero == 0)
			spec->space = 0;
	}
	/* WIDTH */
	if (spec->width)
	{
		spec->width = spec->width - spec->sign - spec->space - spec->plus - spec->sharp - len;
		if (spec->accur > 0)
			spec->width = spec->width - spec->accur;
		if (spec->width <= 0)
			spec->width = 0;
	}
	/* end of parse format */

	tmp_len = out_num(&spec[0], unval, len);
	return (tmp_len);
}