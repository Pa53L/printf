/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 20:18:41 by yshawn            #+#    #+#             */
/*   Updated: 2019/12/11 19:32:33 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

char	*parse_bcolor(char *str)
{
	int	i;

	i = 0;
	str++;
	while (i < COLOR_SIZE)
	{
		if (*str == COLOR[i][0])
		{
			if (ft_str_sym_cmp(str, COLOR[i], '}'))
			{
				write(1, OUT_COLOR[i], OUT_COLOR_POINT[i]);
				i = COLOR_POINT[i];
				return (str + i);
			}
			else
				break ;
		}
		i++;
	}
	return (--str);
}
