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
#include <inttypes.h>
#include <stdio.h> //DELETE THIS
#include <limits.h> //DELETE THIS
#include <math.h> //DELETE THIS

#define BUFFSIZE 5000
#define TYPES_SIZE 11
#define TYPES (char[TYPES_SIZE + 1]) {'c', 's', 'd', 'i', 'u', 'o', 'p', 'x', 'X', 'f', 'b', '\0'}
#define ITOA (char[17]) {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', \
						'a', 'b', 'c', 'd', 'e', 'f', '\0'}
#define ITOAX (char[17]) {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', \
						'A', 'B', 'C', 'D', 'E', 'F', '\0'}
#define NULL_STRING (char[7]) {'(', 'n', 'u', 'l', 'l', ')', '\0'}

//#define SIZE (char[5][3]) {"h\0\0", "hh\0", "l\0\0", "ll\0", "L\0\0"}

typedef struct struct_specifer
{
	int width;
	int accur;
	int dollar;
	char sign;
	char numsys;
	char minus;
	char plus;
	char space;
	char sharp;
	char zero;
	char size;
	char type;
} st_format;

typedef union {
    long double ld;
    struct {
        unsigned long mantisa : 64;
        unsigned short exponent : 15;
        unsigned sign : 1;
    } parts;
} ld_cast;

int			ft_atoi(const char *);
size_t		ft_strlen(const char *);
int			ft_numlen(u_int64_t, int);
void		ft_cast_size_di(st_format *, va_list, int64_t *);
void		ft_cast_size_poxu(st_format *, va_list, u_int64_t *);
//
void		ft_clean_struct(st_format *);
//
char		*is_flag(st_format *, char *);
char		*is_width(st_format *, char *, va_list);
char		*is_accuracy(int *, char *, va_list);
char		*is_size(char *, char *);
char		*is_type(char *, char *);
//
size_t		out_per(st_format *);
size_t		out_str(st_format *,  char *);
size_t		out_chr(st_format *, int);
size_t		out_bits(st_format *, unsigned long long);
size_t		out_num(st_format *spec, unsigned long long, int);
//
char		*parse_specifiers(st_format *, char *, va_list);
size_t		parse_output(st_format *, va_list, va_list);
size_t		parse_dipoxu(st_format *, unsigned long long);
//
int			ft_printf(const char *, ...);

// Ф-ции от П
char *itobs(unsigned long long n, char *ps);
char *ft_str_multiply(char *str1, char *str2, int len1, int len2, char *tmp);
char *ft_pow(char *res, int pow);
char *parse_double(double ld, int pres);
char *parse_mantis(unsigned long mantisa);
char *parse_exponent(unsigned short exponent);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strdup(const char *s);
void ft_itoabasex(unsigned long long value, char *str, int base, char type, int len);
char *make_mantisa(char *str, unsigned long mantisa);
char *make_full_mantis(char *str, char *str2[]);
char *ft_pow5(char *res, int pow);
char *make_dot(char *str, unsigned short exponent);
char *make_dot_zero(char *str, unsigned short exponent);
char *make_rounding(char *str, int pres);

#endif