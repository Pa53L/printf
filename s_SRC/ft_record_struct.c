/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_record_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:23:20 by yshawn            #+#    #+#             */
/*   Updated: 2019/12/21 15:33:46 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

char	*ft_record_struct(st_format *spec, char *p)
{
	p = is_flag(&spec[0], p);
	if(*p >= '0' && *p <= '9')
		p = is_width(&spec[0], p);
	if(*p == '.' && *(p + 1))
		p = is_accuracy(&spec[0], p);
	p = is_size(&spec[0], p);
	p = is_type(&spec[0], p);
	return (p);
}
