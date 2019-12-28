/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 19:10:31 by yshawn            #+#    #+#             */
/*   Updated: 2019/12/24 00:20:52 by yshawn           ###   ########.fr       */
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
#define TYPES (char[11]) {'c', 's', 'd', 'i', 'u', 'o', 'p', 'x', 'X', 'f', '\0'}
#define ITOA (char[17]) {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', \
						'a', 'b', 'c', 'd', 'e', 'f', '\0'}
#define ITOAX (char[17]) {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', \
						'A', 'B', 'C', 'D', 'E', 'F', '\0'}

//#define SIZE (char[5][3]) {"h\0\0", "hh\0", "l\0\0", "ll\0", "L\0\0"}

typedef struct struct_specifer
{
	int width;
	int accur;
	short sign;
	short numsys;
	short minus;
	short plus;
	short space;
	short sharp;
	short zero;
	short size;
	char type;
} st_format;

size_t		ft_strlen(const char *);
int			ft_numlen(unsigned long long, int);
char		*ft_strnew_width(st_format *);
char		*ft_strnew_accuracy(st_format *);
char		*ft_strnew_num(st_format *spec, unsigned long long, int);
void		ft_cast_size_di(st_format *, va_list, long long *);
void		ft_cast_size_poxu(st_format *, va_list, unsigned long long *);
//
void		ft_clean_struct(st_format *);
char		*ft_record_struct(st_format *, char *);
//
char		*is_flag(st_format *, char *);
char		*is_width(int *, char *);
char		*is_accuracy(int *, char *);
char		*is_size(short *, char *);
char		*is_type(char *, char *);
//
size_t		out_per(st_format *);
size_t		out_str(st_format *,  char *);
size_t		out_chr(st_format *, int);
size_t		parse_dipoxu(st_format *, unsigned long long);
void		out_dipoxu(st_format *, char *, char *, char *, unsigned long long, int numlen);
//
char 		*parse_format(st_format *, unsigned long long *);
//
int			ft_printf(const char *, ...);
size_t		ft_output(st_format *, va_list);

// Ф-ции от П
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s);
char		*ft_itoabase(unsigned long long value, char *str, int base);
char		*ft_itoabasex(unsigned long long value, char *str, int base);

#endif