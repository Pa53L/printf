/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <erodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 04:46:08 by erodd             #+#    #+#             */
/*   Updated: 2020/01/23 03:34:02 by erodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

char	*str_nan_inf(char ch)
{
	char *str;

	if (!(str = (char *)malloc(sizeof(char) * 4)))
		return (NULL);
	if (ch == 'i')
	{
		str[0] = 'i';
		str[1] = 'n';
		str[2] = 'f';
		str[3] = '\0';
	}
	else if (ch == 'n')
	{
		str[0] = 'n';
		str[1] = 'a';
		str[2] = 'n';
		str[3] = '\0';
	}
	return (str);
}

char	*ft_is_nan(unsigned long mantisa)
{
	uint64_t head;
	uint64_t tail;

	head = mantisa >> 62;
	tail = mantisa << 2;
	if (head == 0)
	{
		if (tail == 0)
			return (str_nan_inf('i'));
		else
			return (str_nan_inf('n'));
	}
	else if ((head == 1) || (head == 3))
		return (str_nan_inf('n'));
	else
	{
		if (tail == 0)
			return (str_nan_inf('i'));
		else
			return (str_nan_inf('n'));
	}
}

char	*ft_str_multiply(t_mult *m, char *tmp)
{
	int i;
	int j;
	int shift;
	int mem;
	int res;

	shift = 0;
	i = m->len2 + 1;
	while (--i >= 0)
	{
		j = m->len1 + 1;
		mem = 0;
		while (--j >= 0)
		{
			res = (m->str2[j] - '0') * (m->str1[i] - '0') +
			(tmp[j + m->len2 + 1 - shift] - '0') + mem;
			mem = res / 10;
			tmp[j + m->len2 + 1 - shift] = res % 10 + '0';
			if (j == 0)
				tmp[i] = mem + '0';
		}
		shift++;
	}
	tmp[m->len2 + m->len1 - 1] = '\0';
	return (tmp);
}

char	*ft_pow(char *res, int pow)
{
	int len;
	int ret;
	int dec;
	int j;

	len = pow * 0.301 + 1;
	ret = 0;
	res[len] = '\0';
	res[len - 1] = '2';
	j = -1;
	
	
	while (j++ < (len - 2))
		res[j] = '0';
	while (pow > 1)
	{
		if ((len = ft_strlen(res) - 1) < 0)
			len = 1;
		while (len >= 0)
		{
			dec = res[len] - '0';
			// if (pow > 1020)
				// printf("\n\nBEST %c\n\n", res[len]);
			res[len] = (dec * 2 + ret) % 10 + '0';
			ret = (dec * 2 + ret) < 10 ? 0 : 1;
			len--;
		}
		res[len] = ret + '0';
		// printf("\n\nPOW [%d]     [%c]\n\n", pow, res[len]);
		pow--;
	}
	// printf("\n\nPOSLE %s\n\n", res);
	return (res);
}

char	*ft_pow5(char *res, int pow)
{
	int len;
	int ret;
	int dec;
	int j;

	// printf("[%s]\n", res);
	
	len = pow;
	ret = 0;
	// res[len] = '\0';
	res[len - 1] = '5';
	j = 0;
	
	//printf("[%d]\n", pow);
	while (j < (len - 2))
		res[j++] = '0';
	
	while (pow > 1)
	{
		len = ft_strlen(res) - 1;
		//if ((len = ft_strlen(res) - 1) < 0)
		//	len = 1;
		
		while (len > 0)
		{
			//printf("[%s]\n", res);
			dec = res[len] - '0';
			res[len] = (dec * 5 + ret) % 10 + '0';
			ret = (dec * 5 + ret) < 10 ? 0 : ((dec * 5 + ret) / 10);
			len--;
		}
		res[len] = ret + '0';
		pow--;
	}
	res[ft_strlen(res)] = '\0';
	// printf("\n\nPOSLE %s\n\n", res);
	return (res);
}
