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

int		parse_str(st_format *spec, va_list vl)
{
	int		tmp_len;
	int		strlen;
	char	*strnew;
	char	*str;

	if (!(str = va_arg(vl, char *)))
		str = NULL_STRING;
	strlen = ft_strlen(str);
	if (spec->accur >= 0 && spec->accur < strlen)
		strlen = spec->accur;
	if (spec->width > strlen)
		spec->width = spec->width - strlen;
	else
		spec->width = 0;
	tmp_len = spec->width + strlen;
	strnew = record_str(spec, str, --strlen, tmp_len);
	write(1, strnew, tmp_len);
	free(strnew);
	return (tmp_len);
}
