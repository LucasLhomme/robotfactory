##
## EPITECH PROJECT, 2024
## Makefile Root
## File description:
## MakeFile dans le fichier root
##

NAME = asm
DEBUG = -g
CFLAGS += -g -Wall -Wextra -W -Iinclude -Ilib/include

SRC =	./src/robot_factory.c\
		./src/create_champions.c\
		./src/error_handling.c\
		./src/champion_parsing.c

OBJ  	=	 $(SRC:.c=.o)

all: 	$(NAME)
		$(MAKE) clean

$(NAME): $(OBJ)
		 $(MAKE) -C lib all
		 gcc -o $(NAME) $(CFLAGS) $(OBJ) libmy.a

clean || clear:
		$(MAKE) -C lib clean
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:
		$(MAKE) fclean
		$(MAKE) all
