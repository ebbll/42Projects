CC							=		c++
OPTION						=		-std=c++98
CFLAGS						=		-Wall -Wextra -Werror
LEAKFLAG					=		-g3 -fsanitize=address
RM							=		rm -r

NAME						=		a.out
SRCS_DIR					=		./
HEADER_DIR					=		./

SRCS						=		Fixed.cpp \
									main.cpp
SRC							=		$(addprefix $(SRCS_DIR), $(SRCS))
OBJS						=		$(SRC:.cpp=.o)

%.o							:		%.cpp
		$(CC) $(OPTION) $(CFLAGS) -I $(HEADER_DIR) -c $< -o $@

$(NAME)						:		$(OBJS)
		$(CC) $(OPTION) $(CFLAGS) -I $(HEADER_DIR) $(OBJS) -o $(NAME)

.PHONY						:		all
all							:		$(NAME)

.PHONY						:		leaks
leaks 						:		$(OBJS)
		$(CC) $(OPTION) $(CFLAGS) $(LEAKFLAG) -I $(HEADER_DIR) $(OBJS) -o $(NAME)

.PHONY						:		clean
clean						:
		$(RM) $(OBJS)

.PHONY						:		fclean
fclean						:		clean
		$(RM) $(NAME)

.PHONY						:		re
re							:		fclean all
