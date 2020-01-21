/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <erodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:31:27 by yshawn            #+#    #+#             */
/*   Updated: 2020/01/17 20:18:51 by erodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_HEAD/header.h"

int main(int ac, char **av)
{
   printf("|||MINE: %d\n",     ft_printf("%f|%-f|%+f|% f|%#f|%0f", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX));
   printf("|||ORIGINAL: %d\n",    printf("%f|%-f|%+f|% f|%#f|%0f", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX));
   printf("|||MINE: %d\n",     ft_printf("this %f float", 1.5));
   printf("|||ORIGINAL: %d\n",    printf("this %f float", 1.5));
   // ft_printf("|||MINE: %d\n",     ft_printf("%.20Lf", 10.5));
   // printf("|||ORIGINAL: %d\n",    printf("%.20Lf", 10.5));
   // printf("|||ORIGINAL: %d\n",    printf("%-12c", 0, 0, 0, 0));
   // printf("\n");
   
   // printf("|||MINE: %d\n",     ft_printf("%s", buf));
   // printf("|||ORIGINAL: %d\n", printf("%s", buf));
   return 0;
}

// "%LLf", 42.5