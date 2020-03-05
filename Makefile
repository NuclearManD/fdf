# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbrophy <dbrophy@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/26 10:38:40 by dbrophy           #+#    #+#              #
#    Updated: 2020/02/26 10:41:22 by dbrophy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-I. -c -Ilibft -Iminilibx_macos_sierra
LDFLAGS =  -Llibft -Lminilibx_macos_sierra -lft -lmlx -framework OpenGL -framework Appkit
NAME=fdf
OBJ=$(SRC:.c=.o)
SRC=	fdf.c \
	imgutil.c \
	input.c

$(NAME): 
	gcc $(CFLAGS) $(SRC)
	gcc $(LDFLAGS) *.o -o $(NAME)

all: $(NAME)

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

