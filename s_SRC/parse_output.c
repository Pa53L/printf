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
	int						dollar;
	char					*str;
	int64_t					ival;
	u_int64_t				unval;
	u_int64_t				cnt;
	double					fval;

	cnt = 0;
	ival = 0;
	unval = 0;
	dollar = 0;
	str = NULL;

	/* FOR $ */
	if (spec->dollar > 1)
	{
		dollar = spec->dollar;
		while (dollar > 1)
		{
			va_arg(vl, int);
			dollar--;
		}
	}

	if (spec->type == 'c')
	{
		ival = va_arg(vl, int);
		cnt = out_chr(&spec[0], ival);
	}
	else if (spec->type == 's')
	{
		str = va_arg(vl, char *);
		cnt = out_str(&spec[0], str);
	}
	else if (spec->type == 'd' || spec->type == 'i')
	{
		spec->numsys = 10;
		ft_cast_size_di(&spec[0], vl, &ival);
		if (ival < 0)
		{
			unval = ival * (-1);
			spec->sign = 1;
		}
		else
			unval = ival;
		cnt = parse_dipoxu(&spec[0], unval);
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

		ft_cast_size_poxu(&spec[0], vl, &unval);
		cnt = parse_dipoxu(&spec[0], unval);
	}
	else if(spec->type =='f')
	{
		fval = (double)va_arg(vl, double);
		// printf("here: %f\n", fval);
		str = parse_double(fval, 14);
		printf("%s", str);
	}
	else if (spec->type == 'b')
	{
		unval = va_arg(vl, unsigned long long);
		cnt = out_bits(&spec[0], unval);
	}
	else if (spec->type == '%')
		cnt = out_per(&spec[0]);
	else if (spec->type == '\0')
		return (0);

	/* FOR $ */
	if (spec->dollar == 0)
		va_copy(fst_vl, vl);
	else
		va_copy(vl, fst_vl);
	return (cnt);
}