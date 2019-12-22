/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_di.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 20:39:02 by yshawn            #+#    #+#             */
/*   Updated: 2019/12/22 22:57:07 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

char	*strnew(st_format *spec)
{
	char *str;
	int i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (spec->width + 1));
	if (!str)
		return (NULL);
	if (spec->zero && !spec->minus && spec->accur != 0)
	{
		while (i < spec->width + 1)
		{
			str[i] = '0';
			i++;
		}
		str[i] = '\0';
	}
	else
	{
		while (i < spec->width + 1)
		{
			str[i] = ' ';
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}

void		logic_out_di(st_format *spec, long long *ival, size_t len)
{
	if (spec->zero)
	{
		if (spec->accur >= 0)
			spec->zero = 0;
		if (spec->minus)
			spec->zero = 0;
	}
	if (spec->space)
	{
		if (spec->plus)
			spec->space = 0;
		if (*ival < 0)
			spec->space = 0;
	}
	if (spec->minus)
		spec->zero = 0;
	if (spec->accur)
	{
		if (spec->accur <= len)
			spec->accur = 0;
		else
		{
			if (*ival < 0) /* это нужно для правильного возвращения выведенных символов */
				spec->accur = spec->accur - len + 1;
			else
				spec->accur = spec->accur - len;
		}
	}
	if (spec->width)
	{
		spec->width = spec->width - spec->space - spec->plus - len;
		if (spec->accur > 0)
			spec->width = spec->width - spec->accur;
		if (*ival < 0 && spec->plus)
			spec->width = spec->width + 1;
		if (*ival == 0 && spec->accur == 0)
			spec->width++;
		if (spec->width < 0)
			spec->width = 0;
	}
	if (*ival < 0)
		*ival = *ival * (-1);
}

size_t	out_di(st_format *spec, long long ival)
{
	int flag;
	int is_accur;
	int is_width;
	int sign;
	size_t len;
	size_t tmp_len;
	char *str_zerospace;
	
	flag = 0;
	sign = 0;
	tmp_len = 0;
	is_accur = spec->accur;
	is_width = spec->width;

	len = ft_numlen(ival, 10);

	if(ival < 0)
		sign = 1;

	logic_out_di(&spec[0], &ival, len);

	str_zerospace = NULL;

	if(is_width >= len)
		str_zerospace = strnew(&spec[0]);

	/* подсчет возвращаемого количества выведенных символов */
	tmp_len = spec->width + spec->space + spec->plus;
	if (spec->accur > 0)
		tmp_len = tmp_len + spec->accur;
	if (sign && spec->plus)
		tmp_len = tmp_len - 1;
	/* ------------------------------------------------------------------------------ */
	/* ВЫВОД В ЗАВИСИМОСТИ ОТ ТОГО, ЕСТЬ МИНУС (-) ИЛИ НЕТУ */
	if (spec->minus == 0)
	{
		if (spec->width && !spec->zero)
			write(1, str_zerospace, spec->width);

		if (spec->plus || sign)
		{
			if (sign)
				write(1, "-", 1);
			else if (ival != -9223372036854775808)
				write(1, "+", 1);
		}

		if (spec->space)
			write(1, " ", 1);

		if (spec->width && spec->zero)
			write(1, str_zerospace, spec->width);

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
			ft_putnbr(ival);
	}
	/* ------------------------------------------------------------------------------ */
	/* ВЫВОД В ЗАВИСИМОСТИ ОТ ТОГО, ЕСТЬ МИНУС (-) ИЛИ НЕТУ */
	else if (spec->minus == 1)
	{
		/* печатаем знак в зависимости является ли число отр. или стоит флаг + */
		if (spec->plus || sign)
		{
			if (sign)
				write(1, "-", 1);
			else if (ival != -9223372036854775808)
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
			ft_putnbr(ival);

		if (spec->width)
			write(1, str_zerospace, spec->width);
	}
	/* ------------------------------------------------------------------------------ */
	/* фришим всякую хуйню */
	if(str_zerospace)
		free(str_zerospace);
	/* ------------------------------------------------------------------------------ */
	if (ival == 0 && is_accur == 0)
		return (len + tmp_len - 1);
	else
		return (len + tmp_len);
}
