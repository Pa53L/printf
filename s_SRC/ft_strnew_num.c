/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_accuracy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 19:56:50 by yshawn            #+#    #+#             */
/*   Updated: 2019/12/23 20:57:00 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

char	*ft_strnew_num(st_format *spec, unsigned long long ival, int len)
{
	unsigned long strlen;
	unsigned long i;
	char *str;

	strlen = spec->width + spec->space + spec->plus + spec->sign + len;
	if (spec->accur > 0)
		strlen = strlen + spec->accur;
	// printf("for malloc : %d\n", strlen + 1);
	str = (char *)malloc(sizeof(char) * (strlen + 1));
	if (!str)
		return (NULL);
	i = strlen - 1;
	str[strlen] = '\0';
	/* MINUS == 0 */
	if (spec->minus == 0)
	{	
		
		if (ival == 0 && len > 0)
		{
			str[i] = '0';
			i--;
		}
		else if (ival > 0)
		{
			ft_myitoa(ival, &(*str), spec->numsys, i);
			i = i - len;
		}

		while (spec->accur > 0)
		{
			str[i] = '0';
			spec->accur--;
			i--;
		}

		if (spec->zero == 0 && (spec->plus || spec->sign))
		{
			if (spec->sign)
				str[i] = '-';
			else
				str[i] = '+';
			i--;
		}

		while (spec->width > 0)
		{
			if (spec->zero == 0)
				str[i] = ' ';
			else
				str[i] = '0';
			spec->width--;
			i--;
		}

		if (spec->space)
		{
			str[i] = ' ';
			i--;
		}

		if (spec->zero == 1 && (spec->plus || spec->sign))
		{
			if (spec->sign)
				str[i] = '-';
			else
				str[i] = '+';
			i--;
		}
	}
	/* MINUS == 1 */
	if (spec->minus == 1)
	{
		while (spec->width > 0)
		{
			str[i] = ' ';
			spec->width--;
			i--;
		}

		if (ival == 0 && len > 0)
		{
			str[i] = '0';
			i--;
		}
		else if (ival > 0)
		{
			ft_myitoa(ival, &(*str), spec->numsys, i);
			i = i - len;
		}

		while (spec->accur > 0)
		{
			str[i] = '0';
			spec->accur--;
			i--;
		}

		if (spec->plus || spec->sign)
		{
			if (spec->sign)
				str[i] = '-';
			else
				str[i] = '+';
			i--;
		}

		if (spec->space)
		{
			str[i] = ' ';
			i--;
		}
	}
	return (str);
}