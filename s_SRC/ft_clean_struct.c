/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 19:49:14 by yshawn            #+#    #+#             */
/*   Updated: 2019/12/23 22:43:43 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

void	ft_clean_struct(st_format *spec)
{
	spec->sign = 0;
	spec->numsys = 0;
	spec->minus = 0;
	spec->plus = 0;
	spec->space = 0;
	spec->sharp = 0;
	spec->zero = 0;
	spec->width = 0;
	spec->accur = -1;
	spec->size = 0;
	spec->type = '\0';
	return ;
}
