/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:31:27 by yshawn            #+#    #+#             */
/*   Updated: 2019/12/19 23:57:09 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_HEAD/header.h"

int		main()
{
	printf("%d\n", ft_printf("%d|%-d|%+d|% d|%0d\n", 0, 0, 0, 0, 0));
	printf("%d\n", printf("%d|%-d|%+d|% d|%0d\n", 0, 0, 0, 0, 0));
	ft_printf("---------------------\n");
	/*
	ft_printf("%0i\n", 10);
	ft_printf("%.2i\n", 10);
	ft_printf("%010.5i\n", 10);
	ft_printf("%+010.5i\n", 10);
	ft_printf("%-+10.5i\n", 10);
	ft_printf("---------------------------------------\n");
	printf("%0i\n", 10);
	printf("%.2i\n", 10);
	printf("%010.5i\n", 10);
	printf("%+010.5i\n", 10);
	printf("%-+10.5i\n", 10);
	*/
	return (0);
}
/*
   printf("----------------------\n");
   printf("minus: %d\n", spec[0].minus);
   printf("plus: %d\n", spec[0].plus);
   printf("space: %d\n", spec[0].space);
   printf("sharp: %d\n", spec[0].sharp);
   printf("zero: %d\n", spec[0].zero);
   printf("width: %d\n", spec[0].width);
   printf("accuracy: %d\n", spec[0].accuracy);
   printf("size: %d\n", spec[0].size);
   printf("type: %c\n", spec[0].type);
   printf("----------------------\n");
   */
