# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yshawn <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/10 19:41:13 by yshawn            #+#    #+#              #
#    Updated: 2019/12/20 21:29:19 by yshawn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OUT = libftprintf.a

CC = gcc

ODIR = o_OBJ
SDIR = s_SRC
HEADER = h_HEAD/header.h
_OBJS = ft_putnbr.o ft_strlen.o ft_numlen.o \
		ft_clean_struct.o ft_record_struct.o \
		ft_printf.o ft_output.o \
		is_flag.o is_width.o is_accuracy.o is_size.o is_type.o \
		out_chr.o out_str.o out_di.o \
		#check_format_specification.o

OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

$(ODIR)/%.o: $(SDIR)/%.c
	@$(CC) -c -I $(HEADER) -o $@ $< $(CFLAGS)

@$(OUT) : $(OBJS)
	@ar rv $(OUT) $^
	@gcc main.c $(OUT)

.PHONY: clean

clean:
	@rm -f $(ODIR)/*.o $(OUT)
