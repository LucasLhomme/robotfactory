##
## EPITECH PROJECT, 2024
## Makefile Root
## File description:
## MakeFile dans le fichier root
##

NAME = asm
DEBUG = -g
CFLAGS += -g -Wall -Wextra -W -Iinclude -Isrc/lib/include

SRC =	./src/robot_factory.c

OBJ  	=	 $(SRC:.c=.o)

all: 	$(NAME)
		$(MAKE) clean

$(NAME): $(OBJ)
		 $(MAKE) -C src/lib all
		 gcc -o $(NAME) $(CFLAGS) $(OBJ) libmy.a

clean || clear:
		$(MAKE) -C src/lib clean
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:
		$(MAKE) fclean
		$(MAKE) all

