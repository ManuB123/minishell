##
## EPITECH PROJECT, 2019
## minishell1
## File description:
## Makefile
##

SRC     =	$(shell find ./ -name '*.c')	\

OBJ     =       $(SRC:.c=.o)

TEST	=	$(shell find . -name '*.c' ! -name main.c)	\

CC	=	gcc -I./include -g3

NAME    =       mysh

C_FLAGS	=	-W -Wall -Werror -Wextra -pedantic

all:    $(NAME)

test_run:	$(TEST)
	$(CC) -o unit_tests $(TEST) -lcriterion --coverage
	rm -f $(shell find $(SOURCEDIR) -name '.gc*')
	./unit_tests | gcovr
	rm unit_tests


$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -f $(shell find $(SOURCEDIR) -name '*.o')
	rm -f $(shell find $(SOURCEDIR) -name '*~')
	rm -f $(shell find $(SOURCEDIR) -name '*vg*')
	rm -f $(shell find $(SOURCEDIR) -name '*.gc*')


fclean: clean
	rm -f $(NAME)

re:     fclean all

.PHONY: all clean fclean re
