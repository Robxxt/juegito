#include <stdio.h>
#include "so_long.h"

void	handle_error(char *str)
{
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	exit(1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		handle_error("Invalid number of arguments!");
	printf("%s", argv[1]);
	return (0);
}
