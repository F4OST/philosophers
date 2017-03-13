##
## Makefile for  in /home/cyril/work/technique
## 
## Made by Cyril
## Login   <cyril.puccio@epitech.eu>
## 
## Started on  Fri Mar  3 20:39:06 2017 Cyril
## Last update Mon Mar  6 19:28:59 2017 Cyril
##

CC	=	gcc

RM	=	rm -rf

NAME	=	philo

CFLAGS	=	-Wall -Werror -Wextra -ansi -Iinclude -lpthread -g3

SRC	=	philosophe.c

OBJ	=	$(SRC:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) $(SRC) -o $(NAME)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
