/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_di.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 20:39:02 by yshawn            #+#    #+#             */
/*   Updated: 2019/12/24 00:05:09 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

size_t	parse_dipoxu(st_format *spec, unsigned long long ival)
{
	char *str;
	size_t tmp_len;
	
	tmp_len = 0;
	str = NULL;

	str = parse_format(&spec[0], &ival);
	tmp_len = ft_strlen(str);
	if (str)
		write(1, str, tmp_len);
	if (str)
		free(str);
	return (tmp_len);
}