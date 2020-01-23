# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erodd <erodd@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/10 19:41:13 by yshawn            #+#    #+#              #
#    Updated: 2020/01/23 03:43:17 by erodd            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc -pg

ODIR = o_OBJ
SDIR = s_SRC
HEADER = h_HEAD/header.h
_OBJS = ft_strlen.o ft_numlen.o ft_itoabasex.o ft_atoi.o ft_str_sym_cmp.o ft_bzero.o \
		ft_clean_struct.o ft_clean_mult.o \
		ft_printf.o \
		p_chr.o p_str.o p_per.o p_bit.o p_bcolor.o p_bdollar.o p_float.o p_dipoxu.o \
		ld_util.o \
		p_num.o \
		parse_specifiers.o parse_output.o \
		parse_float_number.o parse_float_flag.o \
		parse_num_spec.o parse_dipoxu_spec_cases.o \
		record_chr.o record_str.o record_bit.o record_per.o record_float.o \
		ft_smbu.o long_m_str.o long_math.o \
		is_specifers.o ft_strdel.o \
		ft_cast_size_di.o ft_cast_size_poxu.o ft_cast_size_float.o \
		ft_strdup.o ft_strjoin.o

OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

$(ODIR)/%.o: $(SDIR)/%.c
	@$(CC) -c -I $(HEADER) -o $@ $< $(CFLAGS) -O3

all: $(NAME)

$(NAME) : $(OBJS)
	@ar rv $(NAME) $^
	@gcc main.c $(NAME)
clean:
	@rm -f $(ODIR)/*.o
fclean: clean
	@rm -f $(NAME)
re: fclean all