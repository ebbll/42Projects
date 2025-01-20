# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eunji <eunji@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/12 16:38:53 by eunlee            #+#    #+#              #
#    Updated: 2021/10/25 15:02:15 by eunji            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES: .c .o

PUSH_NAME = push_swap

PUSH_SRCS = push_swap.c\
			check_input.c\
			ft_p.c\
			ft_r.c\
			ft_rr.c\
			ft_s.c\
			list.c\
			sort.c\
			start_sort.c\
			util.c\
			quicksort.c\
			exit_a.c\
			divide.c\
			err.c

PUSH_OBJS = $(PUSH_SRCS:.c=.o)

CHECK_NAME = checker

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LEAKFLAGS = -g3 -fsanitize=address

RM = rm -f

all:
	make $(PUSH_NAME)

leaks: $(PUSH_OBJS)
	$(CC) $(CFLAGS) $(LEAKFLAGS) -o $(PUSH_NAME) $(PUSH_OBJS)

$(PUSH_NAME): $(PUSH_OBJS)
	$(CC) $(CFLAGS) -o $(PUSH_NAME) $(PUSH_OBJS)

clean:
	$(RM) $(PUSH_OBJS)

fclean:
	$(RM) $(PUSH_NAME) $(PUSH_OBJS)

re:	fclean all

.PHONY: clean fclean all re
