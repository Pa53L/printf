/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 23:51:21 by yshawn            #+#    #+#             */
/*   Updated: 2020/01/13 23:52:59 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

int		ft_numlen(unsigned long long num, int base)
{
	int i;

	i = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num /= base;
		i++;
	}
	return (i);
}
