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

int			parse_float_flag_2(st_format *spec, int len_num)
{
	if (spec->width)
		(spec->width >= len_num) ? (spec->width -= len_num) : (spec->width = 0);
	if (spec->space)
		if (spec->plus || spec->sign)
			spec->space = 0;
	if (spec->plus)
		if (spec->sign == 1)
			spec->plus = 0;
	if (spec->zero)
		if (spec->minus)
			spec->zero = 0;
	return (spec->width - spec->plus - spec->sign - spec->space);
}

char		*parse_float_flag(st_format *spec, int len_num)
{
	uint64_t	i;
	int			strlen;
	char		*str_flag;

	i = 0;
	str_flag = NULL;
	strlen = parse_float_flag_2(spec, len_num);
	if (strlen > 0)
	{
		if (!(str_flag = (char *)malloc(sizeof(char) * (strlen + 1))))
			return (NULL);
	}
	else
		return (NULL);
	str_flag[strlen] = '\0';
	while (i < strlen)
		if (spec->zero == 1)
			str_flag[i++] = '0';
		else
			(str_flag[i++] = ' ');
	return (str_flag);
}
