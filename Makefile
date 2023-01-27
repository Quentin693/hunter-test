##
## EPITECH PROJECT, 2022
## bsq
## File description:
## Makefile
##

SRC	=	src/my_hunter.c \
		src/init_hunter.c \
		src/set_hunter.c \
		src/action_hunter.c \
		src/other.c

NAME = my_hunter

LDFLAGS += -l csfml-graphics -l csfml-window -l csfml-system -l csfml-audio

all:

	gcc -o $(NAME) $(SRC) $(LDFLAGS)

clean:
	rm -f $(NAME)

fclean: clean

debug:
	gcc -g3 $(SRC) -o $(NAME)

re : fclean all
