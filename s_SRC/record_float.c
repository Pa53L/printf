/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 23:56:42 by yshawn            #+#    #+#             */
/*   Updated: 2020/01/13 23:57:01 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

void		out_float(st_format *spec, char *str_flag, char *str_number)
{
	int		len_num;
	int		len_flag;

	len_num = ft_strlen(str_number);
	len_flag = ft_strlen(str_flag);
	if (spec->space && spec->zero)
		write(1, " ", 1);
	if ((spec->sign || spec->plus) && spec->zero)
		(spec->sign) ? (write(1, "-", 1)) : (write(1, "+", 1));
	if (str_flag)
		write(1, str_flag, len_flag);
	if (spec->space && !spec->zero)
		write(1, " ", 1);
	if ((spec->sign || spec->plus) && !spec->zero)
		(spec->sign) ? (write(1, "-", 1)) : (write(1, "+", 1));
	if (str_number)
		write(1, str_number, len_num);
	return ;
}

void		out_float_minus(st_format *spec, char *str_flag, char *str_number)
{
	int		len_num;
	int		len_flag;

	len_num = ft_strlen(str_number);
	len_flag = ft_strlen(str_flag);
	if (spec->space)
		write(1, " ", 1);
	if (spec->sign || spec->plus)
		(spec->sign) ? (write(1, "-", 1)) : (write(1, "+", 1));
	if (str_number)
		write(1, str_number, len_num);
	if (str_flag)
		write(1, str_flag, len_flag);
	return ;
}

void		record_float(st_format *spec, char **str_flag, char **str_number)
{
	if (spec->minus == 0)
		out_float(spec, *str_flag, *str_number);
	else
		out_float_minus(spec, *str_flag, *str_number);
	if (*str_flag)
		free(*str_flag);
	if (*str_number)
		free(*str_number);
	return ;
}
