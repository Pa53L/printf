/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <erodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 19:10:31 by yshawn            #+#    #+#             */
/*   Updated: 2020/01/23 03:40:53 by erodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <inttypes.h>

/*
** удалить все include после этого комментария
*/
# include <stdio.h>
# include <limits.h>
# include <float.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define TYPES_SIZE 13
# define NAN_INF_SIZE 3
# define TYPES "cs%bfFdiuopxX"
# define IT "0123456789abcdef"
# define ITX "0123456789ABCDEF"
# define NULL_STRING "(null)"
# define NAN_F "nan"
# define NAN_F_UP "NAN"
# define INF_F "inf"
# define INF_F_UP "INF"

/*
** ебучая норма
** # define COLOR_SIZE 8
** # define COLOR_POINT (const int[8]) {3, 5, 4, 6, 6, 4, 4, 3}
** # define COLOR (const char[8][7])\
** {"red\0\0\0\0", "green\0\0", "blue\0\0\0", "yellow\0", "orange\0",\
** "pink\0\0\0", "neon\0\0\0", "eoc\0\0\0\0"}
** # define OUT_COLOR_POINT (const int[8]){11, 10, 10, 11, 11, 11, 11, 4}
** # define OUT_COLOR (const char[8][11]) { \
**				"\e[38;5;196m", \
**				"\e[38;5;48m\0", \
**				"\e[38;5;69m\0", \
**				"\e[38;5;226m", \
**				"\e[38;5;208m", \
**				"\e[38;5;205m", \
**				"\e[38;5;123m", \
**				"\e[0m\0\0\0\0\0\0\0" \
**							}
*/

# define DG (const char[64][65])\
{ \
	"1000000000000000000000000000000000000000000000000000000000000000", \
	"0500000000000000000000000000000000000000000000000000000000000000", \
	"0250000000000000000000000000000000000000000000000000000000000000", \
	"0125000000000000000000000000000000000000000000000000000000000000", \
	"0062500000000000000000000000000000000000000000000000000000000000", \
	"0031250000000000000000000000000000000000000000000000000000000000", \
	"0015625000000000000000000000000000000000000000000000000000000000", \
	"0007812500000000000000000000000000000000000000000000000000000000", \
	"0003906250000000000000000000000000000000000000000000000000000000", \
	"0001953125000000000000000000000000000000000000000000000000000000", \
	"0000976562500000000000000000000000000000000000000000000000000000", \
	"0000488281250000000000000000000000000000000000000000000000000000", \
	"0000244140625000000000000000000000000000000000000000000000000000", \
	"0000122070312500000000000000000000000000000000000000000000000000", \
	"0000061035156250000000000000000000000000000000000000000000000000", \
	"0000030517578125000000000000000000000000000000000000000000000000", \
	"0000015258789062500000000000000000000000000000000000000000000000", \
	"0000007629394531250000000000000000000000000000000000000000000000", \
	"0000003814697265625000000000000000000000000000000000000000000000", \
	"0000001907348632812500000000000000000000000000000000000000000000", \
	"0000000953674316406250000000000000000000000000000000000000000000", \
	"0000000476837158203125000000000000000000000000000000000000000000", \
	"0000000238418579101562500000000000000000000000000000000000000000", \
	"0000000119209289550781250000000000000000000000000000000000000000", \
	"0000000059604644775390625000000000000000000000000000000000000000", \
	"0000000029802322387695312500000000000000000000000000000000000000", \
	"0000000014901161193847656250000000000000000000000000000000000000", \
	"0000000007450580596923828125000000000000000000000000000000000000", \
	"0000000003725290298461914062500000000000000000000000000000000000", \
	"0000000001862645149230957031250000000000000000000000000000000000", \
	"0000000000931322574615478515625000000000000000000000000000000000", \
	"0000000000465661287307739257812500000000000000000000000000000000", \
	"0000000000232830643653869628906250000000000000000000000000000000", \
	"0000000000116415321826934814453125000000000000000000000000000000", \
	"0000000000058207660913467407226562500000000000000000000000000000", \
	"0000000000029103830456733703613281250000000000000000000000000000", \
	"0000000000014551915228366851806640625000000000000000000000000000", \
	"0000000000007275957614183425903320312500000000000000000000000000", \
	"0000000000003637978807091712951660156250000000000000000000000000", \
	"0000000000001818989403545856475830078125000000000000000000000000", \
	"0000000000000909494701772928237915039062500000000000000000000000", \
	"0000000000000454747350886464118957519531250000000000000000000000", \
	"0000000000000227373675443232059478759765625000000000000000000000", \
	"0000000000000113686837721616029739379882812500000000000000000000", \
	"0000000000000056843418860808014869689941406250000000000000000000", \
	"0000000000000028421709430404007434844970703125000000000000000000", \
	"0000000000000014210854715202003717422485351562500000000000000000", \
	"0000000000000007105427357601001858711242675781250000000000000000", \
	"0000000000000003552713678800500929355621337890625000000000000000", \
	"0000000000000001776356839400250464677810668945312500000000000000", \
	"0000000000000000888178419700125232338905334472656250000000000000", \
	"0000000000000000444089209850062616169452667236328125000000000000", \
	"0000000000000000222044604925031308084726333618164062500000000000", \
	"0000000000000000111022302462515654042363166809082031250000000000", \
	"0000000000000000055511151231257827021181583404541015625000000000", \
	"0000000000000000027755575615628913510590791702270507812500000000", \
	"0000000000000000013877787807814456755295395851135253906250000000", \
	"0000000000000000006938893903907228377647697925567626953125000000", \
	"0000000000000000003469446951953614188823848962783813476562500000", \
	"0000000000000000001734723475976807094411924481391906738281250000", \
	"0000000000000000000867361737988403547205962240695953369140625000", \
	"0000000000000000000433680868994201773602981120347976684570312500", \
	"0000000000000000000216840434497100886801490560173988342285156250", \
	"0000000000000000000108420217248550443400745280086994171142578125"  \
}

typedef struct		s_format
{
	int				width;
	int				accur;
	int				dollar;
	char			sign;
	char			base;
	char			minus;
	char			plus;
	char			space;
	char			sharp;
	char			zero;
	char			size;
	char			type;
}					t_format;

typedef union		u_cast
{
	long double		ld;
	struct			s_parts
	{
		uint64_t	mantisa : 64;
		uint16_t	exponent : 15;
		unsigned	sign : 1;
	}				t_parts;
}					t_cast;

typedef struct		s_mult
{
	int				len1;
	int				len2;
	char			*str1;
	char			*str2;
}					t_mult;

/*
** ебучая норма, гореть тебе в аду, пиздец
** ebuchie bagety
** array of pointers to functions
**
** # define BLYAT_SIZE 5
** typedef int	(*t_fun)(t_format *s, va_list vl);
** # define BLYAT (const t_fun[6]) {p_chr, p_str, p_per, p_bit, p_float,\
**									p_dipoxu}
*/

/*
** standart functions
*/
void				ft_bzero(void *str, size_t n);
int					ft_atoi(const char *str);
size_t				ft_strlen(const char *str);
int					ft_numlen(uint64_t num, int base);
int					ft_str_sym_cmp(char *str_dad, char *str_son, char ch);
void				ft_strdel(char **str);
void				ft_itoabasex(t_format *s, uint64_t un, char *str, int len);
char				*itobs(uint64_t num, char *str);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strdup(const char *str);
/*
** printf main functions
*/
int					ft_printf(const char *format, ...);
int					print_b(t_format *s, char *str, va_list vl, va_list f_vl);
void				printf_printf(char *str, int *cnt);
/*
** clean structs before using
*/
void				ft_clean_struct(t_format *s);
void				ft_clean_mult(t_mult *m);
/*
** casting right sizes into value
*/
void				ft_cast_size_di(t_format *s, va_list vl, int64_t *ival);
void				ft_cast_size_poxu(t_format *s, va_list vl, uint64_t *un);
void				ft_cast_size_float(t_format *s, va_list v, long double *n);
/*
** parse specifers
*/
char				*is_flag(t_format *s, char *str);
char				*is_width(t_format *s, char *str, va_list vl);
char				*is_accuracy(int *accur, char *str, va_list vl);
char				*is_size(char *size, char *str);
char				*is_type(char *type, char *str);
char				*parse_specifiers(t_format *s, char *str, va_list vl);
/*
** parsers for every types
*/
int					parse_chr(t_format *s, va_list vl);
int					parse_bit(t_format *s, va_list vl);
int					parse_per(t_format *s, va_list vl);
int					parse_str(t_format *s, va_list vl);
int					parse_num(t_format *s, uint64_t un, int len);
/*
** recording values into str, also some logic is here
** also there is output in record_float
** other outputs in parsers
*/
char				*record_chr(t_format *s, char *str, char ch);
char				*record_str(t_format *s, char *str, int s_len, int t_len);
char				*record_bit(t_format *s, char *str, int s_len, uint64_t n);
char				*record_per(t_format *s, int str_len);
/*
** FILE NAME: parse_num_s,
** this is for d, i, p, o, x, X, u
** mini parsers sifers for number strings
*/
void				record_sharp(t_format *s, char *str, int *sm_vl_i_dnt_rmb);
void				record_sign(t_format *s, char *str, int *sm_vl_i_dnt_rmb);
int					pcomic_i_num(t_format *s, char *str, uint64_t n, int len);
void				record_num(t_format *s, char *str, uint64_t n, int len);
void				record_minus_num(t_format *s, char *str, uint64_t n, int l);
/*
** bonuses
*/
void				parse_bdollar(int dollar, va_list vl);
char				*parse_bcolor(char *str);
/*
** main parser for everything
** from this function we're going to the parsers
*/
int					parse_output(t_format *s, va_list vl, va_list fst_vl);
/*
** parse numbers d, i, p, o, x, X, u
*/
int					parse_dipoxu(t_format *s, va_list vl);
void				parse_dipoxu_sharp(t_format *s, uint64_t un);
void				parse_dipoxu_space(t_format *s, int n_l);
void				parse_dipoxu_accur(t_format *s, uint64_t un, int *n_l);
void				parse_dipoxu_width(t_format *s, int n_l);
void				parse_dipoxu_plus(t_format *s);
void				parse_dipoxu_case(t_format *s, uint64_t un, int *n_l);
/*
** parse floats
*/
int					parse_float(t_format *s, va_list vl);
char				*parse_float_number(long double num, t_format *s);
char				*parse_float_flag(t_format *s, int n_l);
int					parse_float_flag_2(t_format *s, int n_l);
void				parse_float_nan_inf(t_format *s, char s_n);
void				record_float(t_format *s, char **s_f, char **s_n);
void				out_float(t_format *s, char **s_f, char **s_n);
void				out_float_minus(t_format *s, char **s_f, char **s_n);
/*
** creating float string
*/
char				*ft_make_full_str(char *full_str, int pres, char sharp);
char				*parse_mantis(unsigned long mantisa);
char				*parse_exponent(int pow);
char				*ft_make_new_str(char *new_str, char *str);
char				*ft_str_multiply(t_mult *m, char *tmp);
char				*ft_pow(char *res, int pow);
char				*make_mantisa(char *str, unsigned long mantisa);
char				*make_full_mantis(char *str, char *str2[]);
char				*ft_pow5(char *res, int pow);
char				*make_dot(char **str, unsigned short exponent);
char				*make_dot_zero(char **str);
char				*make_rounding(char **str, int pres);
char				*ft_rounding(char *str, int mem);
char				*ft_is_nan(unsigned long mantisa, char s_type);
char				*str_nan_inf(char ch, char s_type);
char				*ft_make_f_str(char *full, char **right, char **left);
char				*ft_zero_str(int pres, char sharp, char *full_str);
void				fill_rigth_left(t_mult *m, char **str_1, char **str_2);
char				*str_no_prec(char sharp);
char				*ft_fill_str(char *str, char *tmp, int pres);

#endif
