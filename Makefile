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

CC = gcc -g

ODIR = o_OBJ
SDIR = s_SRC
HEADER = h_HEAD/header.h
_OBJS = ft_strlen.o ft_numlen.o ft_itoabase.o ft_itoabasex.o \
		ft_clean_struct.o ft_record_struct.o \
		ft_printf.o ft_output.o \
		out_chr.o out_str.o out_per.o out_dipoxu.o \
		is_flag.o is_width.o is_accuracy.o is_size.o is_type.o \
		parse_format.o parse_dipoxu.o \
		ft_cast_size_di.o ft_cast_size_poxu.o \
		ft_strnew_width.o ft_strnew_accuracy.o ft_strnew_num.o\
		ft_strdup.o ft_strjoin.o

OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

$(ODIR)/%.o: $(SDIR)/%.c
	@$(CC) -c -I $(HEADER) -o $@ $< $(CFLAGS)

all: $(NAME)

$(NAME) : $(OBJS)
	@ar rv $(NAME) $^
	@gcc main.c $(NAME)
clean:
	@rm -f $(ODIR)/*.o
fclean: clean
	@rm -f $(NAME)
re: fclean all