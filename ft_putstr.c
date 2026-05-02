#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	main(int argc, char **argv)
{
	if (argc != 2 && argc != 3)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	ft_putstr("OK\n"); // temporário
	return (0);
}
