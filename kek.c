/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:31:27 by yshawn            #+#    #+#             */
/*   Updated: 2019/12/23 19:21:43 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

typedef struct struct_specifer
{
	short size;
	short type;
} st_format;

void		ft_kek(short *spec)
{	
	*spec = 4;
}

int		main()
{
	st_format spec;
	st_format *p;

	ft_kek(&spec.size);
	printf("%d\n", spec.size);
	printf("%d\n", spec.type);
	return (0);
}
