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
	int64_t					ival;
	uint64_t				unval;
	long double				fval;
	uint64_t				cnt;

	cnt = 0;
	ival = 0;
	unval = 0;

	/* FOR $ */
	if (spec->dollar > 1)
		parse_bdollar(spec->dollar, vl);

	if (spec->type == 'c')
		cnt = out_chr(spec, vl);
	else if (spec->type == 's')
		cnt = out_str(spec, vl);
	else if (spec->type == '%')
		cnt = out_per(spec);
	else if (spec->type == 'b')
		cnt = out_bits(spec, vl);
	else if (spec->type == 'd' || spec->type == 'i')
	{
		ft_cast_size_di(spec, vl, &ival);
		if (ival < 0)
		{
			unval = ival * (-1);
			spec->sign = 1;
		}
		else
			unval = ival;
		cnt = parse_dipoxu(spec, unval);
	}
	else if (spec->type == 'o' || spec->type == 'x' || spec->type == 'X' ||
			 spec->type == 'u' || spec->type == 'p')
	{
		if (spec->type == 'u')
			spec->numsys = 10;
		else if (spec->type == 'o')
			spec->numsys = 8;
		else
			spec->numsys = 16;

		ft_cast_size_poxu(spec, vl, &unval);
		cnt = parse_dipoxu(spec, unval);
	}
	else if(spec->type =='f')
	{
		//ft_cast_size_f();
		if (spec->size == 5)
			fval = va_arg(vl, long double); //must be in ft_cast_size_f
		else
			fval = (long double)va_arg(vl, double); //must be in ft_cast_size_f
		if (fval == LDBL_MIN || fval == -LDBL_MIN)
		{
			if (fval == -LDBL_MIN)
				spec->sign = 1;
			fval = (long double)0.0;
		}
		if (fval < 0)
		{
			fval = fval * (-1);
			spec->sign = 1;
		}
		cnt = parse_float(spec, fval);
	}

	/* FOR $ */
	(spec->dollar == 0) ? va_copy(fst_vl, vl) : va_copy(vl, fst_vl);
	return (cnt);
}