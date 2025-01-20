CC							=		c++
CFLAGS						=		-Wall -Wextra -Werror
LEAKFLAG					=		-g3 -fsanitize=address
RM							=		rm -r

NAME						=		megaphone
SRCS_DIR					=		./
HEADER_DIR					=		./

SRCS						=		megaphone.cpp
SRC							=		$(addprefix $(SRCS_DIR), $(SRCS))
OBJS						=		$(SRC:.cpp=.o)

%.o							:		%.cpp
		$(CC) $(CFLAGS) -I $(HEADER_DIR) -c $< -o $@

$(NAME)						:		$(OBJS)
		$(CC) $(CFLAGS) -I $(HEADER_DIR) $(OBJS) -o $(NAME)

.PHONY						:		all
all							:		$(NAME)

.PHONY						:		leaks
leaks 						:		$(OBJS)
		$(CC) $(CFLAGS) $(LEAKFLAG) -I $(HEADER_DIR) $(OBJS) -o $(NAME)

.PHONY						:		clean
clean						:
		$(RM) $(OBJS)

.PHONY						:		fclean
fclean						:		clean
		$(RM) $(NAME)

.PHONY						:		re
re							:		fclean all
