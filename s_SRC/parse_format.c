/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format_di.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 18:46:23 by yshawn            #+#    #+#             */
/*   Updated: 2019/12/24 00:09:00 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

void	parse_format(st_format *spec, size_t len, unsigned long long *ival)
{
	if (spec->type == 'u')
	{
		spec->space = 0;
		spec->plus = 0;
	}
	if (spec->space)
	{	
		if (spec->plus || spec->sign)
			spec->space = 0;
		if (spec->width > len && spec->minus != 1 && spec->zero != 1)
			spec->space = 0;
	}
	if (spec->accur == 0 && *ival == 0)
		spec->accur = -2;
	if (spec->accur > 0)
	{
		if (spec->accur <= len)
			spec->accur = 0;
		else
			spec->accur = spec->accur - len;
	}
	if (spec->sharp)
	{
		if (spec->numsys == 10 || spec->numsys == 8)
			if (spec->accur > 0 || (*ival == 0 && spec->accur != -2))
				spec->sharp = 0;
		if (spec->numsys == 16)
			if (spec->accur == -2 || (*ival == 0 && spec->accur != -2))
				spec->sharp = 0;
		if (spec->numsys == 10)
			spec->sharp = 0;
	}
	if (spec->zero)
		if (spec->accur >= 0 || spec->accur == -2 || spec->minus == 1)
			spec->zero = 0;
	if (spec->type == 'p')
		spec->sharp = 1;
	if (spec->width)
	{
		spec->width = spec->width - spec->plus - spec->sign - spec->space - len;
		if (spec->accur > 0)
			spec->width = spec->width - spec->accur;
		if (spec->sign && spec->plus)
			spec->width = spec->width + 1;
		if (*ival == 0 && spec->accur == -2)
			spec->width = spec->width + 1;
		if (spec->sharp)
		{
		 	if (spec->numsys == 8)
				spec->width = spec->width - 1;
		 	else if (spec->numsys == 16)
				spec->width = spec->width - 2;
		}
		if (spec->width < 0)
			spec->width = 0;
	}
}