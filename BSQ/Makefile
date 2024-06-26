##
## EPITECH PROJECT, 2024
## BSQ
## File description:
## Makefile
##

SRC	=	./main.c				\
\
		./src/utils.c			\
		./src/parse_arguments.c	\
\

CC	=	gcc

RM	=	rm -f

NAME	=	bsq

CFLAGS	=	-Wall	-Wextra

CPPFLAGS	=	-iquote ./include/

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CPPFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

debug:	CFLAGS += -g3
debug:	re

.PHONY:	all clean fclean re debug
