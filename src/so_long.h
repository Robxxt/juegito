#ifndef SO_LONG_H
# define SO_LONG_H

#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

typedef struct s_map
{
	char	**matrix;
	int		width;
	int 	height;
	int		main_chars;
	int		p_row;
	int 	p_col;
	int		comestibles;
	int		exits;
	int		e_row;
	int		e_col;
} t_map;

void	handle_error(char *str);
void	file_checker(char *filename);
t_map	*get_map(char *filename);
void	check_map(t_map *map);

#endif