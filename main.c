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
   printf("|||MINE: %d\n",     ft_printf("%f", 573.924));
   printf("|||ORIGINAL: %d\n",    printf("%f", 573.924));
   // printf("|||ORIGINAL: %d\n",    printf("%-12c", 0, 0, 0, 0));
   // printf("\n");
   
   // printf("|||MINE: %d\n",     ft_printf("%s", buf));
   // printf("|||ORIGINAL: %d\n", printf("%s", buf));
   return 0;
}
