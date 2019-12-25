/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_zerospace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 18:23:46 by yshawn            #+#    #+#             */
/*   Updated: 2019/12/23 23:59:42 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

char	*ft_strnew_width(st_format *spec)
{
	char *str;
	int i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (spec->width + 1));
	if (!str)
		return (NULL);
	if (spec->zero && !spec->minus)
	{
		while (i < spec->width)
		{
			str[i] = '0';
			i++;
		}
		str[i] = '\0';
	}
	else
	{
		while (i < spec->width)
		{
			str[i] = ' ';
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
