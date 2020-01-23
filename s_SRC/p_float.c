/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <erodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 23:53:58 by yshawn            #+#    #+#             */
/*   Updated: 2020/01/23 10:00:12 by erodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

void	parse_float_nan_inf(t_format *spec, char str_number)
{
	if (str_number == 'n' || str_number == 'i')
	{
		if (str_number == 'n')
		{
			spec->space = 0;
			spec->plus = 0;
		}
		spec->zero = 0;
	}
	return ;
}

int		p_float(t_format *spec, va_list vl)
{
	long double		fval;
	size_t			len_num;
	size_t			len_flag;
	char			*str_number;
	char			*str_flag;

	str_flag = NULL;
	str_number = NULL;
	fval = 0;
	ft_cast_size_float(spec, vl, &fval);
	if (spec->accur >= 0)
	{
		if (spec->accur == 0)
			(spec->sharp) ? (spec->sharp += 0) : (spec->accur--);
	}
	else
		spec->accur = 6;
	str_number = parse_float_number(fval, spec->accur, spec->sharp);
	len_num = ft_strlen(str_number);
	parse_float_nan_inf(spec, *str_number);
	str_flag = parse_float_flag(spec, len_num);
	len_flag = ft_strlen(str_flag);
	record_float(spec, &str_flag, &str_number);
	return (len_num + len_flag + (spec->sign | spec->plus) + spec->space);
}
