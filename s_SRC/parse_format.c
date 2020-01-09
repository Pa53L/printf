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

char 	*parse_format(st_format *spec, unsigned long long *ival)
{
	int len;
	char *str;

	len = ft_numlen(*ival, spec->numsys);
	/* ZERO */
	if (spec->zero)
	{
		if (spec->accur >= 0)
			spec->zero = 0;
	}
	/* ACCUR */
	if (spec->accur >= 0)
	{
		if (spec->accur == 0 && *ival == 0)
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
			if (*ival == 0 && spec->accur != 0)
				spec->sharp = 0;
			else
				spec->sharp = 1;
		}
		if ((spec->accur == 0 && *ival == 0 && spec->type != 'o') || *ival == 0 && spec->type != 'o' || (spec->accur > 0 && spec->type == 'o'))// || spec->accur == -1)
			spec->sharp = 0;
		if (spec->type == 'p')
			spec->sharp = 2;
	}
	/* PLUS */
	if (spec->plus)
	{
		if (spec->sign == 1)
			spec->plus = 0;
	}
	/* SPACE */
	if (spec->space)
	{	
		if (spec->plus || spec->sign)
			spec->space = 0;
		if (spec->width > len && spec->minus != 1 && spec->zero != 1)
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
	// printf("----------------------\n");
	// printf("width: %d\n", spec[0].width);
	// printf("len is: %d\n", len);
	// printf("sign: %d\n", spec[0].sign);
	// printf("minus: %d\n", spec[0].minus);
	//printf("accuracy: %d\n", spec[0].accur);
	// printf("plus: %d\n", spec[0].plus);
	// printf("space: %d\n", spec[0].space);
	// printf("sharp: %d\n", spec[0].sharp);
	// printf("zero: %d\n", spec[0].zero);
	// printf("size: %d\n", spec[0].size);
	// printf("type: %c\n", spec[0].type);
	// printf("----------------------\n");
	str = ft_strnew_num(&spec[0], *ival, len);
	return (str);
}