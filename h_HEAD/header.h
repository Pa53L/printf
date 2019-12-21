/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 19:10:31 by yshawn            #+#    #+#             */
/*   Updated: 2019/12/21 22:54:05 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h> //DELETE THIS
#include <limits.h> //DELETE THIS

#define NULL_STRING (char[7]) {'(', 'n', 'u', 'l', 'l', ')', '\0'}

//# define EXAMPLE (char[5][3]) {"l\0\0", "hh\0", "h\0\0", "ll\0", "L\0\0"}

typedef enum
{
	CHAR = 'c',
	STRING = 's',
	POINTER = 'p',
	DECIMAL = 'd',
	DECIMAL_2 = 'i',
	OCTAL = 'o',
	HEX = 'x',
	BIG_HEX = 'X',
	FLOAT = 'f'
} Format_Type;

typedef struct struct_specifer
{
	int minus;
	int plus;
	int space;
	int sharp;
	int zero;
	int width;
	int accur;
	int size;
	char type;
} st_format;

void	ft_putnbr(long long int);
void	ft_uputnbr(unsigned long long);
size_t	ft_strlen(const char *);
long long	ft_numlen(long long int, int);
//
void	ft_clean_struct(st_format *);
char	*ft_record_struct(st_format *, char *);
//
char	*is_flag(st_format *, char *);
char	*is_width(st_format *, char *);
char	*is_accuracy(st_format *, char *);
char	*is_size(st_format *, char *);
char	*is_type(st_format *, char *);
//
size_t	out_str(st_format *,  char *);
size_t	out_chr(st_format *, int);
size_t	out_di(st_format *, va_list);
//
int		ft_printf(const char *, ...);
size_t	ft_output(st_format *, va_list);

#endif
