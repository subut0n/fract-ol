# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: addzikow <addzikow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 14:10:23 by addzikow          #+#    #+#              #
#    Updated: 2021/10/27 12:49:46 by addzikow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME	= fractol
LIB		= libft
SRCS	= srcs/check_args.c \
		  srcs/choose.c \
		  srcs/color.c \
		  srcs/error.c \
		  srcs/julia.c \
		  srcs/main.c \
		  srcs/mandelbrot.c\
		  srcs/motion.c \
		  srcs/move.c \
		  srcs/pixel_img.c \
		  srcs/zoom.c
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