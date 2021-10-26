# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: addzikow <addzikow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 14:10:23 by addzikow          #+#    #+#              #
#    Updated: 2021/10/25 16:05:57 by addzikow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME	= fractol
LIB		= libft
SRCS	= srcs/check_args.c \
		  srcs/main.c \
		  srcs/mandelbrot.c\
		  srcs/julia.c
HEAD	= mlx/libmlx.a libft/libft.a
OBJ		= $(SRCS:.c=.o)
FLAGS	= -Wall -Wextra -Werror
MLX		= cc -framework OpenGL -framework AppKit -o

all: $(NAME)

$(NAME):
	make -C $(LIB)
	make -C mlx
	$(MLX) $(NAME) $(FLAGS) $(SRCS) $(HEAD) -O3

clean:
	make clean -C $(LIB)
	rm -f $(OBJ)

fclean:
	make fclean -C $(LIB)
	make clean -C mlx
	rm -f $(NAME)

re: fclean all