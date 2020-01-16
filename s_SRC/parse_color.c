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

char	*parse_color(char *str)
{
	int		i;

	i = 0;
	str++;
	while (i < COLOR_SIZE)
	{
		if (*str == COLOR[i][0])
		{
			if (ft_str_sym_cmp(str, COLOR[i], '}') == 1)
			{	
				i = COLOR_POINT[i];
				write(1, OUT_COLOR[i], 11);
			}
			else
				return (--str);
			break ;
		}
		i++;
	}
	return (str + i);
}

// printf("\033[38;5;196m"); //red
// printf("\033[38;5;48m"); //green
// printf("\033[38;5;69m"); //blue
// printf("\033[38;5;226m"); //yellow;
// printf("\033[38;5;172m"); //orange 208
// printf("\033[38;5;205m"); //pink
// printf("\033[1;3;4;95m\033[48;5;123m"); // neon