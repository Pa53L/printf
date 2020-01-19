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

char		*parse_float_flag(st_format *spec, int len_num)
{
	char * str_flag;
	int strlen;
	size_t i;
	i = 0;
	str_flag = NULL;
	strlen = 0;
	if (spec->width)
		(spec->width >= len_num) ? (spec->width -= len_num) : (spec->width = 0);
	// printf("width: %d\n", spec->width);
	if (spec->space)
		if (spec->plus || spec->sign)
			spec->space = 0;
	if (spec->plus)
		if (spec->sign == 1)
			spec->plus = 0;
	if (spec->zero)
		if (spec->minus)
			spec->zero = 0;
	strlen = spec->width - spec->plus - spec->sign - spec->space;
	// printf("strlen: %d\n", strlen);
	if (strlen > 0)
	{
		if(!(str_flag = (char *)malloc(sizeof(char) * (strlen + 1))))
			return (NULL);
	}
	else
		return (NULL);
	str_flag[strlen] = '\0';
	while (i < strlen)
	{
		(spec->zero == 1) ? (str_flag[i] = '0') : (str_flag[i] = ' ');
		i++;
	}
	// printf("LOL:[%s]\n", str_flag);
	return (str_flag);
}