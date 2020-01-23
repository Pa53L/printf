/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <erodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:31:27 by yshawn            #+#    #+#             */
/*   Updated: 2020/01/23 02:58:10 by erodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_HEAD/header.h"

int main(int ac, char **av)
{
   ft_printf("{blue}%s{green}%s{red}%s{yellow}%s{orange}%s{pink}%s", "hello", "hello", "hello", "hello", "hello", "hello");
   // printf("|||MINE: %d\n",     ft_printf("%f", -875.000001));
   // printf("|||ORIGINAL: %d\n",    printf("%f", -875.000001));
   // printf("|||MINE: %d\n",     ft_printf("%400d|%-400d|%+d", 10, 10, 10));
   // printf("|||ORIGINAL: %d\n",    printf("%400d|%-400d|%+d", 10, 10, 10));
   //printf("|||MINE: %d\n",     ft_printf("this %f %f %f %f %f %f %f %f %f %ffloat", 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5));
   //printf("|||ORIGINAL: %d\n",    printf("this %f float", 1.5));
   // ft_printf("|||MINE: %d\n",     ft_printf("%.20Lf", 10.5));
   // printf("|||ORIGINAL: %d\n",    printf("%.20Lf", 10.5));
   // printf("|||ORIGINAL: %d\n",    printf("%-12c", 0, 0, 0, 0));
   // printf("\n");
   
   // printf("|||MINE: %d\n",     ft_printf("%s", buf));
   // printf("|||ORIGINAL: %d\n", printf("%s", buf));
   return 0;
}

// "%LLf", 42.5