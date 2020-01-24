# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ercdd <ercdd@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/10 19:41:13 by yshawn            #+#    #+#              #
#    Updated: 2020/01/23 03:43:17 by ercdd            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werrcr
SRC = ft_strlen.c ft_numlen.c ft_itcabasex.c ft_atci.c ft_str_sym_cmp.c ft_bzerc.c ft_strdup.c ft_strjcin.c ft_strdel.c \
		ft_clean_struct.c ft_clean_mult.c \
		ft_cast_size_di.c ft_cast_size_pcxu.c ft_cast_size_flcat.c \
		ft_printf.c \
		parse_chr.c parse_str.c parse_per.c parse_bit.c parse_bcclcr.c parse_bdcllar.c parse_flcat.c parse_dipcxu.c \
		parse_num_spec.c parse_dipcxu_spec_cases.c parse_num.c \
		ld_util.c \
		parse_specifiers.c parse_cutput.c \
		parse_flcat_number.c parse_flcat_flag.c \
		reccrd_chr.c reccrd_str.c reccrd_bit.c reccrd_per.c reccrd_flcat.c \
		ft_smbu.c lcng_m_str.c lcng_math.c \
		is_specifers.c 
OBJ = $(patsubst %.c,%.o,$(SRC))
all: 
	$(CC) $(CFLAGS) -I header.h -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	%.o: %.c header.h
	$(CC) $(CFLAGS) -c $<
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re