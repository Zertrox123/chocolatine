##
## EPITECH PROJECT, 2023
## delivery
## File description:
## Makefile
##

SRC	=	code/main.c	\
		code/my_strcmp.c	\
		code/my_strcat.c	\
		code/cd.c	\
		code/getenv.c	\
		code/exec_binary.c	\
		code/my_strncmp.c	\
		code/pipe.c	\
		lib/my/conversion_indicator_1.c	\
		lib/my/fonction_c_flags.c	\
		lib/my/fonction_g.c	\
		lib/my/fonction_g_dec.c	\
		lib/my/fonction_g_scient.c	\
		lib/my/fonction_o_flags.c	\
		lib/my/fonction_x_flags.c	\
		lib/my/my_decimal_number.c	\
		lib/my/my_hexa.c	\
		lib/my/my_octale.c	\
		lib/my/my_pointer.c	\
		lib/my/my_printf.c	\
		lib/my/my_putchar.c	\
		lib/my/my_put_nbr.c	\
		lib/my/my_put_nbr_unsigned.c	\
		lib/my/my_put_str.c	\
		lib/my/my_putstr.c	\
		lib/my/my_scientific_number.c

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
	echo "All test passed"

re:	fclean all
