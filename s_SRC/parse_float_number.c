/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_float_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <erodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 23:39:07 by erodd             #+#    #+#             */
/*   Updated: 2020/01/21 03:01:02 by erodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

char *ft_zero_str(int pres, char sharp, char *full_str);

char	*parse_float_number(long double number, int pres, char sharp)
{
	ld_cast d1;
	char *str_right;
	char *str_left;
	char *full_str;

	d1 = (ld_cast){ .ld = number };
	if (pres == -1)
		pres = 0;
	if (d1.parts.exponent == 32767)
		return (ft_is_nan(d1.parts.mantisa));
	if (d1.parts.exponent == 0)
		return (ft_zero_str(pres, sharp, full_str));
	str_right = (char *)malloc(sizeof(char) * 65);
	str_right = parse_mantis(d1.parts.mantisa);
	str_left = (char *)malloc(sizeof(char) * 5000);
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

char *ft_make_f_str(char *full, char *right, char *left)
{
	t_mult m;
	int k;


	k = 0;
	ft_clean_mult(&m);
	full = (char *)malloc(sizeof(char) * 5000);


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
	while (k < (m.len1 + m.len2))
	{
		full[k] = '0';
		k++;
	}
	full = ft_str_multiply(&m, full);
	full[m.len1 + m.len2 - 1] = '\0';
	return (full);
}

char	*ft_zero_str(int pres, char sharp, char *full_str)
{
	if (pres == 0)
	{
		if (sharp) 
		return ("0.");
		return ("0");
	}
	else
	{
		int g = 2;
		if(!(full_str = (char *)malloc(sizeof(char) * (pres + 3))))
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

char	*ft_is_nan(unsigned long mantisa)
{
	uint64_t head = (mantisa >> 62);
	uint64_t tail = (mantisa << 2);

	if (head == 0)
	{
		if (tail == 0)
			return ("inf");
		else
			return ("nan");
	}
	else if ((head == 1) || (head == 3))
		return ("nan");
	else
	{
		if (tail == 0)
			return ("inf");
		else
			return ("nan");
	}
}

char	*make_rounding(char *str, int pres)
{
	char	*tmp;
	int i;
	int j;
	int mem;

	if (!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(str) + pres + 1))))
		return (NULL);
	j = 0;
	i = 0;
	while (str[i] != '.')
		tmp[i++] = str[j++];
	tmp[i++] = '.';
	j = i;
	while (pres-- > -1)
	{
		while (str[j] != '\0' && pres-- >= 0)
			tmp[i++] = str[j++];
		tmp[i++] = '0';
	}
	i--;
	((str[i] >= '5') ? (mem = 1) : (mem = 0));
	tmp[i] = '\0';
	tmp = ft_rounding(tmp, mem);
	return (tmp);
}

char	*ft_rounding(char *str, int mem)
{
	int i;

	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		if (str[i] == '.')
			i--;
		if (mem == 1 && str[i] >= '0' && str[i] < '9')
		{
			str[i] = ((str[i] - '0') + mem) + '0';
			mem = 0;
			break ;
		}
		else if (mem == 1 && str[i] == '9')
		{
			str[i] = '0';
			i--;
		}
		else
			break ;
	}
	if (i == -1 && mem == 1)
		str = ft_strjoin("1", str);
	return (str);
}

char	*make_dot(char *str, unsigned short exponent)
{
	int i;
	int j;
	char *tmp;

	i = 0;
	j = 0;
	if (!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	tmp[ft_strlen(str)] = '\0';
	if (str[i] == '0')
		i++;
	while (i <= ((exponent - 16383) * 0.301 + 1))
		tmp[j++] = str[i++];
	tmp[j] = '.';
	j++;
	while (str[i] != '\0')
		tmp[j++] = str[i++];
	return (tmp);
}

char	*make_dot_zero(char *str, unsigned short exponent)
{
	int i;
	int j;
	char *tmp;

	i = 2;
	j = 2;
	if (!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2))))
		return (NULL);
	tmp[ft_strlen(str)] = '\0';
	tmp[0] = '0';
	tmp[1] = '.';
	while (str[i] != '\0')
	{
		tmp[j] = str[i];
		i++;
		j++;
	}
	return (tmp);
}

char	*parse_exponent(unsigned short exponent)
{
	int		pow;
	char	*str;

	pow = exponent - 16383;
	if (pow > 0)
	{
		str = (char *)malloc(sizeof(char) * (pow * 0.301 + 1));
		str = ft_pow(str, pow);
	}
	else if (pow == 0)
        return ("1");
	else
	{
		pow = pow * -1;
		str = (char *)malloc(sizeof(char) * (pow + 1));
		str = ft_pow5(str, pow);
	}
	return (str);
}

char	*parse_mantis(unsigned long mantisa)
{
	char *str;

	str = (char *)malloc(sizeof(char) * 65);
	str[64] = '\0';
	int j = 0;
	while (j <= 63)
	{
		str[j] = '0';
		j++;
	}
	str = make_mantisa(str, mantisa);
	return (str);
}

char	*make_mantisa(char *str, unsigned long mantisa)
{
	char bin_str[CHAR_BIT * sizeof(unsigned long) + 1];
	int i;
	int j;
	int mem;
	char tmp;

	mem = 0;
	i = 0;
	while (itobs(mantisa, bin_str)[i] != '\0')
	{
		j = 63;
		if (itobs(mantisa, bin_str)[i] == '1')
		{
			while (j >= 0)
			{
				tmp = str[j];
				str[j] = ((str[j] - '0') + (DEG_ARR[i][j] - '0') + mem) % 10 + '0';
				mem = ((tmp - '0') + (DEG_ARR[i][j] - '0') + mem) / 10;
				j--;
			}
		}
		i++;
	}
	return (str);
}

char	*itobs(unsigned long long n, char *ps)
{
	int			i;
	uint64_t	size;

	size = CHAR_BIT * sizeof(uint64_t);
	i = size - 1;
	while (i >= 0)
	{
		ps[i] = (01 & n) + '0';
		i--;
		n >>= 1;
	}
	ps[size] = '\0';
	return (ps);
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
		len = ft_strlen(res);
		while (len-- >= 0)
		{
			dec = res[len] - '0';
			res[len] = (dec * 2 + ret) % 10 + '0';
			ret = (dec * 2 + ret) < 10 ? 0 : 1;
		}
		res[len] = ret + '0';
		pow--;
	}
	return (res);
}

char	*ft_pow5(char *res, int pow)
{
	int len;
	int ret;
	int dec;
	int j;

	len = pow + 1;
	ret = 0;
	res[len] = '\0';
	res[len - 1] = '5';
	j = -1;
	while (j++ < (len - 2))
		res[j] = '0';
	while (pow > 1)
	{
		len = ft_strlen(res);
		while (len-- >= 0)
		{
			dec = res[len] - '0';
			res[len] = (dec * 5 + ret) % 10 + '0';
			ret = (dec * 5 + ret) < 10 ? 0 : ((dec * 5 + ret) / 10);
		}
		res[len] = ret + '0';
		pow--;
	}
	return (res);
}
