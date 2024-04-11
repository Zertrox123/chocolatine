##
## EPITECH PROJECT, 2023
## delivery
## File description:
## Makefile
##

SRC	=	main.c

CFLAGS = -g3

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

tests_run:
	echo "Ici";

re:	fclean all
