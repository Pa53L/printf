/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 19:29:18 by yshawn            #+#    #+#             */
/*   Updated: 2019/12/24 00:11:44 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

void	out_dipoxu(st_format *spec, char *str_width, char *str_accur, char *str_num, uint64_t ival, int numlen)
{
	int flag;

	flag = 0;
	if (spec->minus == 0)
	{
		if (spec->width && !spec->zero)
			write(1, str_width, spec->width);
		if (spec->space)
			write(1, " ", 1);
		if (spec->plus || spec->sign)
		{
			if (spec->sign)
				write(1, "-", 1);
			else
				write(1, "+", 1);
		}
		if (spec->sharp)
		{
				if (spec->type == 8)
					write(1, "0", 1);
				else if  (spec->type == 16)
					write(1, "0x", 2);
		}
		if (spec->width && spec->zero)
			write(1, str_width, spec->width);
		if (spec->accur > 0)
			write(1, str_accur, spec->accur);
		if (spec->accur == -2)
			;
		else
			write(1, str_num, numlen);
	}
	else if (spec->minus == 1)
	{
		if (spec->plus || spec->sign)
		{
			if (spec->sign)
				write(1, "-", 1);
			else
				write(1, "+", 1);
		}
		if (spec->space && spec->accur > 0)
		{
			write(1, " ", 1);
			flag++;
		}
		if (spec->space && flag == 0)
		{
			write(1, " ", 1);
		}
		if (spec->sharp)
		{
				if (spec->type == 8)
					write(1, "0", 1);
				else if  (spec->type == 16)
					write(1, "0x", 2);
		}
		if (spec->accur > 0)
			write(1, str_accur, spec->accur);
		if (spec->accur == -2)
			;
		else
			write(1, str_num, numlen);
		if (spec->width)
			write(1, str_width, spec->width);
	}
}
