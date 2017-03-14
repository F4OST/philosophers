##
## Makefile for  in /home/cyril/work/technique
##
## Made by Cyril
## Login   <cyril.puccio@epitech.eu>
##
## Started on  Fri Mar  3 20:39:06 2017 Cyril
## Last update Tue Mar 14 22:39:09 2017 Cyril
##

CC	=	gcc -D _BSD_SOURCE

RM	=	rm -rf

NAME	=	philo

CFLAGS	=	-Wall  -Wextra -ansi -I./include

LDFLAG	=	-L. -lriceferee -lpthread

SRC	=	src/main.c	\
		src/thread.c

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
