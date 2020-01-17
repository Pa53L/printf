# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erodd <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/10 19:41:13 by yshawn            #+#    #+#              #
#    Updated: 2019/12/24 00:20:25 by yshawn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc -pg

ODIR = o_OBJ
SDIR = s_SRC
HEADER = h_HEAD/header.h
_OBJS = ft_strlen.o ft_numlen.o ft_itoabasex.o ft_atoi.o ft_str_sym_cmp.o \
		ft_clean_struct.o \
		ft_printf.o \
		out_chr.o out_str.o out_per.o out_num.o out_float.o out_bits.o \
		parse_specifiers.o parse_output.o parse_dipoxu.o \
		parse_float.o parse_float_number.o parse_float_flag.o \
		parse_bcolor.o parse_bdollar.o \
		ft_cast_size_di.o ft_cast_size_poxu.o \
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