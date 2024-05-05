SRCS	=	application/crpytogphy.c	\
			application/functions.c		\
			application/application.c	\
			application/any_functions.c	\

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror
MFLAGS	=	-g -L./mlx -lmlx -framework AppKit -framework OpenGL
RM		=	rm -rf
NAME	=	encrypted_notepad
MINI	=	./mlx/libmlx.a

all: $(NAME)

# $(MINI):
# 	@make -C ./mlx &> /dev/null

$(NAME): $(OBJS)
	@gcc $(CFLAGS) $(OBJS) -o $(NAME)
	@make clean

%.o: %.c
	${CC} -c $^ -o $@ -Wall -Werror -Wextra -g

clean:
	@rm -rf $(OBJS)
	@rm -rf $(BOBJS)
	@make clean -C mlx/

fclean: clean
	@rm -rf ${NAME}
	@rm -rf $(B_NAME)
	@make clean -C mlx/

re: fclean all

.PHONY: all clean fclean re
