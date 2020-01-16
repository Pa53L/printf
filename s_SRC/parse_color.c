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
	if (*str == 'r')
	{
		if (ft_str_sym_cmp(str, COLORS[0], '}') == 1)
		{	
			i = COLORS_POINT[0];
			write(1, "\e[38;5;196m", 11);
		}
		else
			return (str);
	}
	else if (*str == 'g')
	{
		if (ft_str_sym_cmp(str, COLORS[1], '}') == 1)
		{
			i = COLORS_POINT[1];
			write(1, "\e[38;5;48m", 10);
		}
	}
	else if (*str == 'b')
	{
		if (ft_str_sym_cmp(str, COLORS[2], '}') == 1)
		{
			i = COLORS_POINT[2];
			write(1, "\e[38;5;69m", 10);
		}
	}
	else if (*str == 'y')
	{
		if (ft_str_sym_cmp(str, COLORS[3], '}') == 1)
		{
			i = COLORS_POINT[3];
			write(1, "\e[38;5;226m", 11);
		}
	}
	else if (*str == 'o')
	{
		if (ft_str_sym_cmp(str, COLORS[4], '}') == 1)
			write(1, "\e[38;5;172m", 11);
	}
	else if (*str == 'p')
	{
		if (ft_str_sym_cmp(str, COLORS[5], '}') == 1)
			write(1, "\e[38;5;205m", 11);
	}
	else if (*str == 'n')
	{
		if (ft_str_sym_cmp(str, COLORS[6], '}') == 1)
			write(1, "\e[1;3;4;95m\e[48;5;123m", 22);
	}
	else if (*str == 'e')
	{
		if (ft_str_sym_cmp(str, COLORS[7], '}') == 1)
		{
			i = COLORS_POINT[7];
			write(1, "\e[0m", 4);
		}
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