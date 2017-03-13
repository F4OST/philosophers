##
## Makefile for  in /home/cyril/work/technique
##
## Made by Cyril
## Login   <cyril.puccio@epitech.eu>
##
## Started on  Fri Mar  3 20:39:06 2017 Cyril
## Last update Mon Mar 13 15:12:46 2017 Cyril
##

CC	=	gcc

RM	=	rm -rf

NAME	=	philo

CFLAGS	=	-Wall -Werror -Wextra -ansi -I./include

LDFLAG	=	-L. -lriceferee -lpthread

SRC	=	src/main.c

OBJ	=	$(SRC:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(LDFLAG)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
