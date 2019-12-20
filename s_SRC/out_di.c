/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_di.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 20:39:02 by yshawn            #+#    #+#             */
/*   Updated: 2019/12/20 22:05:49 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

size_t	out_di(st_format_spec *spec, int ival)
{
	size_t len;
	size_t tmp_len;

	tmp_len = 0;
	len = ft_numlen(ival, 10);

	/* какие-то условия */
	if (spec->minus)
		spec->zero = 0;
	if (spec->plus)
		spec->space = 0;

	/* условия потяжелее */
	if (spec->accuracy)
	{
		if (spec->accuracy > len)
			spec->accuracy = spec->accuracy - len;
		else
			spec->accuracy = 0;
		if (spec->accuracy == 0)
			spec->space = 0;
		if (spec->accuracy > 0)
			spec->zero = 0;
	}
	if(spec->width)
	{
		if (spec->plus)
			len++;
		if(spec->width > len + spec->accuracy)
			spec->width = spec->width - spec->accuracy - len;
		else
			spec->width = 0;
		if (spec->space)
			spec->width--;
	}
	tmp_len = spec->width + spec->accuracy + spec->space;

	printf("\n");
	printf("tmp is + len is: %lu\n", tmp_len + len);
	printf("\n");
	/* непосредственно, вывод */
	
	if (spec->minus == 0)
	{
		while (spec->width > 0)
		{
			spec->zero ? write(1, "0", 1) : write(1, " ", 1);
			spec->width--;
		}
		if (spec->plus && ival >= 0)
			write(1, "+", 1);
		if (spec->space && ival >= 0)
			write(1, " ", 1);
		while (spec->accuracy > 0)
		{
			write(1, "0", 1);
			spec->accuracy--;
		}
		ft_putnbr(ival);
	}
	if (spec->minus == 1)
	{
		if (spec->plus && ival >= 0)
		{
			tmp_len++;
			write(1, "+", 1);
		}
		if (spec->space && ival >= 0)
			write(1, " ", 1);
		while (spec->accuracy > 0)
		{
			write(1, "0", 1);
			spec->accuracy--;
		}
		ft_putnbr(ival);
		while (spec->width > 0)
		{
			(spec->zero == 1) ? write(1, "0", 1) : write(1, " ", 1);
			spec->width--;
		}
	}
	return (len + tmp_len);
}
