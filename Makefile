# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msybell <msybell@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/01 12:56:52 by hagoodwi          #+#    #+#              #
#    Updated: 2020/02/21 00:02:09 by msybell          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c draw.c reader.c math.c initialization.c press_key.c

LIB = libft/libft.a

MINILIB = -L /usr/local/lib -lmlx

MINILIBKEYS = -framework OpenGL -framework AppKit

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
		make -C libft/
		gcc -o $(NAME) -Wall -Wextra -Werror -g $(OBJ) $(LIB) $(MINILIB) $(MINILIBKEYS)

%.o:	%.c -I
		gcc -o $(NAME) $@ -Wall -Wextra -Werror $<

clean:
		rm -f $(OBJ)
		make -C ./libft clean

fclean: clean
		rm -f $(NAME)
		make -C ./libft fclean

re:		fclean all
