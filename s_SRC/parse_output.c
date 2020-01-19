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

size_t	parse_output(st_format *spec, va_list vl, va_list fst_vl)
{
	uint64_t				cnt;

	cnt = 0;

	/* FOR $ */
	if (spec->dollar > 1)
		parse_bdollar(spec->dollar, vl);

	if (spec->type == 'c')
		cnt = parse_chr(spec, vl);
	else if (spec->type == 's')
		cnt = out_str(spec, vl);
	else if (spec->type == '%')
		cnt = out_per(spec);
	else if (spec->type == 'b')
		cnt = out_bits(spec, vl);
	else if (spec->type == 'f')
		cnt = parse_float(spec, vl);
	else if (spec->type == 'o' || spec->type == 'x' || spec->type == 'X' ||
			 spec->type == 'u' || spec->type == 'p' || spec->type == 'd' ||
			 spec->type == 'i')
		cnt = parse_dipoxu(spec, vl);
	
	/* FOR $ */
	(spec->dollar == 0) ? va_copy(fst_vl, vl) : va_copy(vl, fst_vl);
	return (cnt);
}