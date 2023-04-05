NAME	:= so_long
MLXLIB	:= ./lib/MLX42
LIBFT	:= ./lib/libft
SRC		:= so_long.c
OBJ		:= $(SRC:.c=.o)

all: $(LIBFT) $(MLXLIB) $(NAME) 

$(NAME): $(OBJ) $(LIBFT) $(MLXLIB)
	cc $(LIBFT)/libft.a $(MLXLIB)/build

$(LIBFT):
	echo HOLA
	@make -C $(LIBFT)

$(MLXLIB):
	echo HOLA
	@cmake -S $(MLXLIB) -B $(MLXLIB)/build

.PHONY: so_long, all, clean, fclean, re