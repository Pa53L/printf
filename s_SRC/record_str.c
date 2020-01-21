/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 23:56:42 by yshawn            #+#    #+#             */
/*   Updated: 2020/01/13 23:57:01 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

char		*record_str(st_format *spec, char *str, int strlen, int tmp_len)
{
	char	*strnew;
	int		i;

	strnew = NULL;
	i = tmp_len - 1;
	if (!(strnew = (char *)malloc(sizeof(char) * (tmp_len))))
		return (NULL);
	strnew[i] = '\0';
	while (strlen >= 0 && spec->minus == 0)
		strnew[i--] = str[strlen--];
	while (spec->width > 0)
	{
		strnew[i--] = ' ';
		spec->width--;
	}
	while (strlen >= 0 && spec->minus == 1)
		strnew[i--] = str[strlen--];
	return (strnew);
}
