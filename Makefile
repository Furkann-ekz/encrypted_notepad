SRCS	=	crpytogphy.c	\
		functions.c	\

APP_C	=	application.c

OBJS	=	$(SRCS:.c=.o)

APP_S	=	$(APP_C:.c=.o) $(OBJS)

CC		=	gcc

RM		=	rm -rf

NAME	=	encrypted_notepad

all: $(NAME)

$(NAME): $(APP_S)
	gcc $(APP_S) -o $(NAME)
	rm -rf $(APP_S)

clean:
	$(RM) $(OBJS) $(APP_S)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
