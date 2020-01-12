/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:31:27 by yshawn            #+#    #+#             */
/*   Updated: 2019/12/24 07:09:24 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_HEAD/header.h"

int		main()
{
   // ft_printf("hello, my name is Jessie Pinkman, bitch!\n%d\n", 10);
	printf("|||MINE: %d\n",     ft_printf("%-9b", 15));
   // printf("%1$d:%2$.*3$d:%4$.*3$d\n", "hour", "min", "precision", "sec");
   // printf("%'d\n", 1000000);
   /*
	printf("|||MINE: %d\n",     ft_printf("% 4.5i", 42));
	printf("|||ORIGINAL: %d\n",    printf("% 4.5i", 42));
	printf("\n");
	printf("|||MINE: %d\n",     ft_printf("% 5d", 52625));
	printf("|||ORIGINAL: %d\n",    printf("% 5d", 52625));
   */
   return (0);
}
/*
Соответственно, побитовое произведение чисел 31 и 17 даст 17, так как 31 это 00011111 , а 17 это 00010001

00011111
00010001
↓↓↓↓↓↓↓↓
00010001
*/


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
/*
char *itobs(unsigned long long n, char *ps)
{
   int i;
   const static unsigned long long size = CHAR_BIT * sizeof(unsigned long long);
   for (i = size - 1; i >= 0; i--, n >>= 1)
      ps[i] = (01 & n) + '0';
   ps[size] = '\0';
   return (ps);
}
*/
