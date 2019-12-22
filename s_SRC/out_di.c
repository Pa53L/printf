/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_di.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 20:39:02 by yshawn            #+#    #+#             */
/*   Updated: 2019/12/22 18:37:16 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

size_t	out_di(st_format *spec, long long ival)
{
	long long int di;
	unsigned long long di_2;
	size_t len;
	size_t tmp_len;
	int is_accur;
	int flag;
	
	tmp_len = 0;
	flag = 0;
	di_2 = 0;
	is_accur = spec->accur;

	len = ft_numlen(ival, 10);
	/* ЛОГИКА И ПОДСЧЕТ ШИРИНЫ, А ТАКЖЕ НЕОБХОДИМОСТЬ ВЫВОДА В ЗАВИСИМОСТИ ОТ ФЛАГОВ */
	/* проверяем на зависимости и несостыковки spec->zero */
	if (spec->zero)
	{
		if (spec->accur >= 0)
			spec->zero = 0;
		if (spec->minus)
			spec->zero = 0;
	}
	/* игнорируем заполнение нулями, если есть флаг минус (-) */
	if (spec->space)
	{
		if (spec->plus)
			spec->space = 0;
		if (ival < 0)
			spec->space = 0;
	}
	/* игнорируем заполнение нулями, если есть флаг минус (-) */
	if (spec->minus)
		spec->zero = 0;
	/* для вывода знака */
	if (ival < 0)
	{
			di = ival;
			di = di * (-1);
	}
	else
		di = ival;
	/* ебемся с точностью */
	if (spec->accur)
	{
		if (spec->accur <= len)
			spec->accur = 0;
		else
		{
			if (ival < 0) /* это нужно для правильного возвращения выведенных символов */
				spec->accur = spec->accur - len + 1; /* т.к. мы знак записываем в другом месте */
			else
				spec->accur = spec->accur - len;
		}
	}
	/* считаем ширину */
	if (spec->width)
	{
		spec->width = spec->width - spec->space - spec->plus - len;
		if (spec->accur > 0)
			spec->width = spec->width - spec->accur;
		if (ival < 0 && spec->plus)
			spec->width = spec->width + 1;
		if (ival == 0 && spec->accur == 0)
			spec->width++;
		if (spec->width < 0)
			spec->width = 0;
	}
	/* подсчет возвращаемого количества выведенных символов */
	tmp_len = spec->width + spec->space + spec->plus;
	if (spec->accur > 0)
		tmp_len = tmp_len + spec->accur;
	if (ival <  0 && spec->plus)
		tmp_len = tmp_len - 1;
	/* ------------------------------------------------------------------------------ */
	/* ВЫВОД В ЗАВИСИМОСТИ ОТ ТОГО, ЕСТЬ МИНУС (-) ИЛИ НЕТУ */
	if (spec->minus == 0)
	{
		/* сначала печатаем ширину */
		while (spec->width > 0 && spec->zero == 0)
		{
			write(1, " ", 1);
			spec->width--;
		}
		/* печатаем знак в зависимости является ли число отр. или стоит флаг + */
		if (spec->plus || ival < 0)
		{
			if (ival < 0 && di != -9223372036854775808)
				write(1, "-", 1);
			else if (di != -9223372036854775808)
				write(1, "+", 1);
		}
		/* смотрим, есть ли spec->space */
		if (spec->space)
			write(1, " ", 1);
		while (spec->width > 0 && spec->zero == 1)
		{
			write(1, "0", 1);  /*если zero, то нули вместо проб. */
			spec->width--;
		}
		/* печатаем точность ебаную */
		while (spec->accur > 0)
		{
			write(1, "0", 1);
			spec->accur--;
		}
		/* непосредственно вывод числа */
		if (ival == 0 && is_accur == 0)
			;
		else
			ft_putnbr(di);
	}
	/* ------------------------------------------------------------------------------ */
	/* ВЫВОД В ЗАВИСИМОСТИ ОТ ТОГО, ЕСТЬ МИНУС (-) ИЛИ НЕТУ */
	else if (spec->minus == 1)
	{
		/* печатаем знак в зависимости является ли число отр. или стоит флаг + */
		if (spec->plus || ival < 0)
		{
			if (ival < 0 && di != -9223372036854775808)
				write(1, "-", 1);
			else if (di != -9223372036854775808)
				write(1, "+", 1);
		}
		/* печатаем точность ебаную */
		if (spec->space && ival == 0 && is_accur > 0)
		{
			write(1, " ", 1);
			flag++;
		}
		while (spec->accur > 0)
		{
			write(1, "0", 1);
			spec->accur--;
		}
		/* смотрим, есть ли spec->space */
		if (spec->space && flag == 0)
			write(1, " ", 1);
		/* непосредственно вывод числа */
		if (ival == 0 && is_accur == 0)
			;
		else
			ft_putnbr(di);
		/* сначала печатаем ширину */
		while(spec->width > 0)
		{
			write(1, " ", 1);
			spec->width--;
		}
	}
	/* ------------------------------------------------------------------------------ */
	if (ival == 0 && is_accur == 0)
		return (len + tmp_len - 1);
	else
		return (len + tmp_len);
}
