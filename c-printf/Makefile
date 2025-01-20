# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/08 18:59:06 by eunlee            #+#    #+#              #
#    Updated: 2020/12/13 10:46:52 by eunlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS =	ft_printf.c \
		ft_printf_utils.c \
		utils.c \
		c_print.c\
		s_print.c\
		num_print.c\
		p_print.c \
		percent_print.c

OBJS = $(SRCS:.c=.o)

RM	 = rm -f

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
