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

void	parse_dipoxu_width(st_format *spec, int len)
{
	spec->width = spec->width - spec->sign - spec->space - spec->plus -
								spec->sharp - len;
	if (spec->accur > 0)
		spec->width = spec->width - spec->accur;
	if (spec->width <= 0)
		spec->width = 0;
	return ;
}

void	parse_dipoxu_accur(st_format *spec, uint64_t unval, int *len)
{
	if (spec->accur == 0 && unval == 0)
		*len = 0;
	if (spec->accur > *len)
		spec->accur = spec->accur - *len;
	else
		spec->accur = 0;
	return ;
}

void	parse_dipoxu_space(st_format *spec, int len)
{
	if (spec->type == 'u')
		spec->space = 0;
	if (spec->plus || spec->sign)
		spec->space = 0;
	if (spec->width > len + spec->accur && spec->accur != -1 &&
		spec->minus == 0 && spec->zero == 0)
		spec->space = 0;
	return ;
}

void	parse_dipoxu_plus(st_format *spec)
{
	if (spec->type == 'u')
		spec->plus = 0;
	if (spec->sign == 1)
		spec->plus = 0;
	return ;
}

void	parse_dipoxu_sharp(st_format *spec, uint64_t unval)
{
	if (spec->type == 'o')
	{
		if (unval == 0 && spec->accur != 0)
			spec->sharp = 0;
		else
			spec->sharp = 1;
	}
	if ((spec->accur == 0 && unval == 0 && spec->type != 'o') ||
		(unval == 0 && spec->type != 'o') ||
		(spec->accur > 0 && spec->type == 'o'))
		spec->sharp = 0;
	if (spec->type == 'p')
		spec->sharp = 2;
	return ;
}
