/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 19:31:23 by yshawn            #+#    #+#             */
/*   Updated: 2019/12/21 18:38:24 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

size_t	out_per(st_format *spec)
{
	unsigned long strlen;
	unsigned long i;
	char *str;

	str = NULL;
	strlen = spec->width;
	if (strlen > 1)
	{
		str = (char *)malloc(sizeof(char) * (strlen));
		if (!str)
			return (0);
	}
	else
	{
		write(1, "%", 1);
		return (1);
	}
	str[strlen - 1] = '\0';
	i = strlen - 1;
	if (spec->minus == 1)
	{
		while (i > 0)
		{
			str[i] = ' ';
			i--;
		}
	}
	str[i] = '%';
	i--;
	if (spec->minus == 0)
	{
		while (i > 0)
		{
			if (spec->zero == 0)
				str[i] = ' ';
			else if (spec->zero == 1)
				str[i] = '0';
			i--;
		}
		if (spec->zero == 0)
			str[i] = ' ';
		else if (spec->zero == 1)
			str[i] = '0';
	}
	write(1, str, strlen);
	free(str);
	return (strlen);
}