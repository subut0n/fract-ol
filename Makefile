SRC_DIR	:= srcs/
OBJ_DIR	:= obj/
OBJ_DIRS = $(addprefix $(OBJ_DIR), srcs)
PRE_SRCS = 	main check_args hooks
SRCS = $(addsuffix .c, $(addprefix $(SRC_DIR), $(PRE_SRCS)))
OBJS = $(addsuffix .o, $(addprefix $(OBJ_DIR), $(PRE_SRCS)))
NAME = fractol
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror 
THFLAGS = -lpthread -D_REENTRANT
INC =	-I./inc
.PHONY: all clean fclean re all
all: libft	$(NAME)
libft:
	@$(MAKE) -C ./libft
$(NAME): $(OBJ_DIRS) $(OBJS) ./libft/libft.a
	@$(CC) $(CFLAGS) $(THFLAGS)  $(OBJS) $(INC) -L. -lmlx -framework OpenGL -framework AppKit ./libft/libft.a -o $(NAME)
	@echo "\033[32mfractol done\033[0m"
$(OBJ_DIRS):
	@mkdir -p $(OBJ_DIRS)
$(OBJS) : includes/fractol.h ./libft/libft.h
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$@ \033[32mcreated\033[0m"
clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) clean -C libft
fclean: 	clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C libft
re:		fclean all