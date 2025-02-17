##
## EPITECH PROJECT, 2024
## Makefile lib
## File description:
## MakeFile dans le fichier lib
##

NAME = libmy.a

LIB =	./my_compute_power_rec.c\
	./my_getnbr.c\
	./my_isneg.c\
	./my_put_nbr.c\
	./my_putchar.c\
	./my_putstr.c\
	./my_revstr.c\
	./my_strdup.c\
	./my_strncmp.c\
	./my_strcpy.c\
	./my_strlen.c\
	./my_strncpy.c\
	./my_swap.c\
	./my_sort_params.c\
	./my_revstr.c\
	./my_str_to_word_array.c\
	./flag_c.c\
	./flag_d.c\
	./flag_i.c\
	./flag_o.c\
	./flag_percent.c\
	./flag_s.c\
	./flag_x.c\
	./flag_x2.c\
	./my_printf.c\
	./my_strcmp.c\
	./my_strnmajcmp.c\
	./my_strcat.c\
	./my_show_word_in_array.c\
	./my_getenv.c


OBJ_LIB  	=	 $(LIB:.c=.o)

CFLAGS += -Wall -Werror -Wextra -W -Iinclude

NAME	=	libmy.a

all: 	$(NAME)

$(NAME):	$(OBJ_LIB)
		ar rcs $(NAME) $(OBJ_LIB)
		mv $(NAME) ../../

clean:
		rm -f $(OBJ_LIB)

fclean: clean
		rm -f $(NAME)

re:
		$(MAKE) fclean
		$(MAKE) all
