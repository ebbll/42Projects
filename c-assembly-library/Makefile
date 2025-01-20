CC		=	gcc
NAME	=	libasm.a
NASM	=	nasm
FLAGS	=	-f macho64
INC		=	libasm.hsd

SRCS	=	srcs/ft_strlen.s\
			srcs/ft_strcpy.s\
			srcs/ft_strcmp.s\
			srcs/ft_write.s\
			srcs/ft_read.s\
			srcs/ft_strdup.s

OBJS	=	$(SRCS:.s=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)

%.o:		%.s
			$(NASM) -I$(INC) $(FLAGS) $< -o $@

test:
			$(CC) main.c libasm.h -L. -lasm
			rm -rf libasm.h.gch
			rm -rf WRITE_TEST

clean:		
			rm -rf $(OBJS)
			rm -rf a.out
			rm -rf WRITE_TEST

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all, clean, fclean, re, test
