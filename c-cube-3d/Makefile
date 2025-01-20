NAME	=	cub3D

INCS	=	-Iinclude -Ilibft -Imlx

SRCS	=	./srcs/main.c					\
			./srcs/get_cub_info.c			\
			./srcs/get_cub_info_util.c		\
			./srcs/check_cub_info.c			\
			./srcs/get_map_info.c			\
			./srcs/get_map_info_util.c		\
			./srcs/check_map_info.c			\
			./srcs/check_map_info_util.c	\
			./srcs/get_next_line.c			\
			./srcs/init.c					\
			./srcs/load_texture.c			\
			./srcs/exit_free.c				\
			./srcs/main_loop.c				\
			./srcs/calc_raycasting.c		\
			./srcs/draw.c					\
			./srcs/key_press.c				\
			./srcs/calc_sprite.c			\
			./srcs/bmp.c					\
			./srcs/ft_putstr.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

LIBS	=	-Lmlx -lmlx -framework OpenGL -framework Appkit -Llibft -lft

CFLAGS	=	-Wall -Werror -Wextra -g3 -fsanitize=address $(INCS)

LIBFT	=	./libft

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(MAKE) bonus -C $(LIBFT)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

clean	:
			rm -f $(OBJS)
			$(MAKE) -C $(LIBFT) clean

fclean	:	clean
			rm -f $(NAME)
			$(MAKE) -C $(LIBFT) fclean

re		:	fclean all

.PHONY	:	all clean fclean re
