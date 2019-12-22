/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:31:27 by yshawn            #+#    #+#             */
/*   Updated: 2019/12/22 12:57:18 by erodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_HEAD/header.h"

int		main()
{
	int n = 54763;
	
	
	ft_printf("%30x\n", n);
	ft_printf("%30X\n", n);
	ft_printf("%30o\n", n);
	printf("%30x\n", n);
	printf("%30X\n", n);
	printf("%30o\n", n);
	
	//printf("M: %x\n", ft_printf("%023ld|", LLONG_MIN));
	//printf("\n");
	//printf("I: %d\n",    printf("%023ld|", LLONG_MIN));
	//printf("\n");

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
