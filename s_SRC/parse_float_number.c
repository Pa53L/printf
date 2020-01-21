/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_float_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <erodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 23:39:07 by erodd             #+#    #+#             */
/*   Updated: 2020/01/21 05:39:52 by erodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

char	*parse_float_number(long double number, int pres, char sharp)
{
	ld_cast		d1;
	char		*str_right;
	char		*str_left;
	char		*full_str;

	d1 = (ld_cast){ .ld = number };
	(pres == -1) ? (pres = 0) : (pres += 0);
	if (d1.parts.exponent == 32767)
		return (ft_is_nan(d1.parts.mantisa));
	if (d1.parts.exponent == 0)
		return (ft_zero_str(pres, sharp, full_str));
	str_right = parse_mantis(d1.parts.mantisa);
	str_left = parse_exponent(d1.parts.exponent);
	full_str = ft_make_f_str(full_str, str_right, str_left);
	if (number >= 1 || number <= -1)
		full_str = make_dot(full_str, d1.parts.exponent);
	else
		full_str = make_dot_zero(full_str, d1.parts.exponent);
	full_str = make_rounding(full_str, pres);
	if (full_str[ft_strlen(full_str) - 1] == '.')
		full_str[ft_strlen(full_str) - 1] = '\0';
	if (pres == 0 && sharp)
		full_str = ft_strjoin(full_str, ".");
	return (full_str);
}

char	*ft_make_f_str(char *full, char *right, char *left)
{
	t_mult	m;
	int		k;

	k = -1;
	ft_clean_mult(&m);
	if(!(full = (char *)malloc(sizeof(char) * 5000)))
		return (NULL);
	if (ft_strlen(left) < ft_strlen(right))
	{
		m.str2 = left;
		m.str1 = right;
		m.len1 = ft_strlen(left) - 1;
		m.len2 = ft_strlen(right) - 1;
	}
	else
	{
		m.str2 = right;
		m.str1 = left;
		m.len1 = ft_strlen(right) - 1;
		m.len2 = ft_strlen(left) - 1;
	}
	while (++k < (m.len1 + m.len2))
		full[k] = '0';
	full = ft_str_multiply(&m, full);
	full[m.len1 + m.len2 - 1] = '\0';
	return (full);
}

char	*ft_zero_str(int pres, char sharp, char *full_str)
{
	int g;

	g = 2;
	if (pres == 0)
	{
		if (sharp)
			return ("0.");
		return ("0");
	}
	else
	{
		if (!(full_str = (char *)malloc(sizeof(char) * (pres + 3))))
			return (NULL);
		full_str[0] = '0';
		full_str[1] = '.';
		while (g < (pres + 2))
		{
			full_str[g] = '0';
			g++;
		}
		full_str[g] = '\0';
		return (full_str);
	}
}

char	*parse_exponent(unsigned short exponent)
{
	int		pow;
	char	*str;

	pow = exponent - 16383;
	if (pow > 0)
	{
		if(!(str = (char *)malloc(sizeof(char) * (pow * 0.301 + 1))))
			return (NULL);
		str = ft_pow(str, pow);
	}
	else if (pow == 0)
		return ("1");
	else
	{
		pow = pow * -1;
		if(!(str = (char *)malloc(sizeof(char) * (pow + 1))))
			return (NULL);
		str = ft_pow5(str, pow);
	}
	return (str);
}
