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

char	*ft_strnew_accuracy(st_format *spec)
{
	char *str;
	int i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (spec->accur + 1));
	if (!str)
		return (NULL);
	while (i < spec->accur + 1)
	{
		str[i] = '0';
		i++;
	}
	str[i] = '\0';
	return (str);
}
