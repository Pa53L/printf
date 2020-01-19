/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_chr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 23:53:58 by yshawn            #+#    #+#             */
/*   Updated: 2020/01/13 23:55:18 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

size_t		parse_float(st_format *spec, va_list vl)
{
	long double				fval;
	size_t len_num;
	size_t len_flag;
	char *str_number;
	char *str_flag;

	fval = 0;
	len_num = 0;
	len_flag = 0;
	str_number = NULL;
	str_flag = NULL;

	ft_cast_size_float(spec, vl, &fval);
	if (spec->accur >= 0)
	{
		if (spec->accur == 0)
		{
			if (spec->sharp)
				;
			else
				spec->accur--;
		}
	}
	else
		spec->accur = 6;
	str_number = parse_float_number(fval, spec->accur, spec->sharp);
	len_num = ft_strlen(str_number);
	if (*str_number == 'n' || *str_number == 'i')
	{
		if (*str_number == 'n')
		{
			spec->space = 0;
			spec->plus = 0;
		}
		spec->zero = 0;
	}
	str_flag = parse_float_flag(spec, len_num);
	len_flag = ft_strlen(str_flag);
	// i = out_float();

	/* это должно быть в out_float */
	if (spec->minus == 0)
	{
		if (spec->space && spec->zero)
			write(1, " ", 1);
		if ((spec->sign || spec->plus) && spec->zero)
			(spec->sign) ? (write(1, "-", 1)) : (write(1, "+", 1));
		if (str_flag)
			write(1, str_flag, len_flag);
		if (spec->space && !spec->zero)
			write(1, " ", 1);
		if ((spec->sign || spec->plus )&& !spec->zero)
			(spec->sign) ? (write(1, "-", 1)) : (write(1, "+", 1));
		if (str_number)
			write(1, str_number, len_num);
	}
	if (spec->minus == 1)
	{
		if (spec->space)
			write(1, " ", 1);
		if (spec->sign || spec->plus)
			(spec->sign) ? (write(1, "-", 1)) : (write(1, "+", 1));
		if (str_number)
			write(1, str_number, len_num);
		if (str_flag)
			write(1, str_flag, len_flag);
	}
	return (len_num + len_flag + (spec->sign | spec->plus) + spec->space);
}