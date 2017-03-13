##
## Makefile for  in /home/cyril/work/technique
##
## Made by Cyril
## Login   <cyril.puccio@epitech.eu>
##
## Started on  Fri Mar  3 20:39:06 2017 Cyril
## Last update Mon Mar 13 14:47:49 2017 Matthias Prost
##

CC	=	gcc

RM	=	rm -rf

NAME	=	philo

CFLAGS	=	-Wall -Werror -Wextra -ansi -I./include -lpthread

SRC	=	src/main.c

OBJ	=	$(SRC:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
