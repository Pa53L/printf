/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_di.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 20:39:02 by yshawn            #+#    #+#             */
/*   Updated: 2019/12/24 00:05:09 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

size_t	parse_dipoxu(st_format *spec, unsigned long long ival)
{
	char *str;
	size_t tmp_len;
	
	tmp_len = 0;
	str = NULL;

	str = parse_format(&spec[0], &ival);
	printf("%s", str);
	/*
	if (is_width >= (len + spec->sign))
		str_width = ft_strnew_width(&spec[0]);
	if (is_accur >= (len + spec->sign))
		str_accur = ft_strnew_accuracy(&spec[0]);
	if (spec->type != 'X')
		str_num = ft_itoabase(ival, str_num, spec->numsys);
	else
		str_num = ft_itoabasex(ival, str_num, spec->numsys);
	out_dipoxu(&spec[0], str_width, str_accur, str_num, ival, len); //ВЫВОД В КОНСОЛЬ

	if (str_num)
		free(str_num);
	if (str_width)
		free(str_width);
	if (str_accur)
		free(str_accur);

	tmp_len = spec->width + spec->space + spec->plus +spec->sign;
	if (spec->accur > 0)
		tmp_len = tmp_len + spec->accur;
	if (spec->sign && spec->plus)
		tmp_len = tmp_len - 1;
	if (ival == 0 && spec->accur == -2)
		tmp_len = tmp_len - 1;
	if (spec->sharp && spec->numsys == 8)
		tmp_len = tmp_len + 1;
	if (spec->sharp && spec->numsys == 16)
		tmp_len = tmp_len + 2;
	*/
	if (str)
		free(str);
	return (tmp_len);
}
