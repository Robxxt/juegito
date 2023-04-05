#include "so_long.h"

static void	valid_file_extension(char *filename, char *extension)
{
	int	f_len;
	int	e_len;
	
	f_len = (int)ft_strlen(filename);
	e_len = (int)ft_strlen(extension);
	while (f_len >= e_len && e_len > 0)
	{
		if (filename[--f_len] != extension[--e_len])
			handle_error("Invalid file extension!");
	}
	if (e_len > 0)
		handle_error("Invalid file extension!");
}

/*
If the file extension is valid & the filename exists
returns the fd. Else exits with error message.
*/
int	file_checker(char *filename)
{
	int	fd;

	valid_file_extension(filename, ".ber");
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		handle_error("Can't open the file!");
	return (fd);
}
