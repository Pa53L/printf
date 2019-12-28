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
	char *str;
	int i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (spec->width + spec->accur + len + 1));
	if (!str)
		return (NULL);
	while (spec->width > 0)
	{
		str[i] = ' ';
		spec->width--;
		i++;
	}
	while (spec->accur > 0)
	{
		str[i] = '0';
		spec->accur--;
		i++;
	}
	i = i + len - 1;
	str[i + 1] = '\0';
	while (ival > 0)
	{
		if (ival < 10)
		{
			str[i] = ITOA[ival];
			ival -= ival;
		}
		else
			str[i] = ITOA[ival % 10];
		ival /= 10;
		i--;
	}
	return (str);
}
