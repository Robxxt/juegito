NAME	:= so_long
MLXLIB	:= ./lib/MLX42
LIBFT	:= ./lib/libft
SRC		:= src/so_long.c
OBJ		:= $(SRC:.c=.o)

all: $(LIBFT) $(MLXLIB) $(NAME) 

$(NAME): build_mlx build_libft $(OBJ)
	cc $(OBJ) $(LIBFT)/libft.a $(MLXLIB)/build/libmlx42.a -o $(NAME)

$(LIBFT):
	echo HOLA
	@make -C $(LIBFT)

build_mlx:
	@cmake -S $(MLXLIB) -B $(MLXLIB)/build
	@make -C $(MLXLIB)/build
build_libft:
	@make -C $(LIBFT)

clean: $(OBJ)
	@make -C $(LIBFT) clean
	@make -C $(MLXLIB)/build clean
	@rm -Rf $(OBJ)

fclean: clean
	@make -C $(LIBFT) fclean
	@rm -f $(NAME)


.PHONY: so_long, build_mlx, build_libft, all, clean, fclean, re