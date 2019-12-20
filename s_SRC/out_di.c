/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_di.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 20:39:02 by yshawn            #+#    #+#             */
/*   Updated: 2019/12/21 00:18:19 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

size_t	out_di(st_format_spec *spec, int ival)
{
	size_t len;
	size_t tmp_len;
	
	tmp_len = 0;
	len = ft_numlen(ival, 10);
	/* УСЛОВИЯ, ГДЕ Я ПОДСЧИТЫВАЮ ДЛИНУ И ОБРАБАТЫВАЮ НЕКОТОРЫЕ АСПЕКТЫ */
	if(spec->plus)
	{
		if (ival < 0)
			spec->plus = 0;
		spec->space = 0;
	}
	if (spec->space && ival < 0)
		spec->space = 0;
	if (spec->accuracy)
	{
		if (ival < 0)
			spec->accuracy++;
		spec->accuracy = spec->accuracy - len;
		if (spec->accuracy < 0)
			spec->accuracy = 0;
		spec->zero = 1;
	}
	if (spec->width)
	{
		spec-> width = spec->width - spec->space - spec->plus - spec->accuracy - len;
		if (spec->width < 0)
			spec->width = 0;
	}
	tmp_len = spec->width + spec->space + spec->plus + spec->accuracy;
	/* ВЫВОД В ЗАВИСИМОСТИ ОТ ТОГО, ЕСТЬ МИНУС (-) ИЛИ НЕТУ */
	/* ЕСЛИ МИНУСА (-) НЕТУ */
	if (spec->minus == 0)
	{
		if (spec->space)
			write(1, " ", 1);
		/* если нулями заполняем, то плюс должен быть перед ними */
		if (spec->zero && (spec->plus || ival < 0))
		{
			if(spec->plus && ival >= 0)
				write(1, "+", 1);
			else if (ival < 0)
				write(1, "-", 1);
			spec->plus = 0;
		}
		if (spec->width)
		{
			while (spec->width > 0)
			{
				if (spec->zero)
					write(1, "0", 1);
				else
					write (1, " ", 1);
				spec->width--;
			}
		}
		if (spec->plus)
			write(1, "+", 1);
		while (spec->accuracy > 0)
		{
			write(1, "0", 1);
			spec->accuracy--;
		}
		/*
		 * если нулями заполняем, то плюс должен быть перед ними
		 * поэтому, если это отрицательное и нужно заполнять, в putnbr
		 * нужно передавать неотрицательное число
		*/
		if (spec->zero && ival < 0)
			ft_putnbr((long)ival * (-1));
		else
			ft_putnbr(ival);
	}
	/* ЕСЛИ МИНУС (-) ЕСТЬ */
	else if (spec->minus == 1)
	{
		if (spec->space)
			write(1, " ", 1);
		if (spec->plus)
			write(1, "+", 1);
		if (spec->zero && (spec->plus || ival < 0))
		{
			if(spec->plus && ival >= 0)
				write(1, "+", 1);
			else if (ival < 0)
				write(1, "-", 1);
			spec->plus = 0;
		}
		while (spec->accuracy > 0)
		{
			write(1, "0", 1);
			spec->accuracy--;
		}
		if (spec->zero && ival < 0)
			ft_putnbr((long)ival * (-1));
		else
			ft_putnbr(ival);
		if (spec->width)
		{
			while (spec->width > 0)
			{
				write (1, " ", 1);
				spec->width--;
			}
		}
	}
	return (len + tmp_len);
}
