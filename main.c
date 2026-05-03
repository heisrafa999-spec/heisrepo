#include "rush.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*number;
	char	*dict;
	t_dict	*parsed;

	if (argc != 2 && argc != 3)
	{
		write(1, "Error\n", 6);
		return (1);
	}

	if (argc == 2)
		number = argv[1];
	else
		number = argv[2];

	if (!is_number(number))
	{
		write(1, "Error\n", 6);
		return (1);
	}

	if (argc == 3)
		dict = read_dict(argv[1]);
	else
		dict = read_dict("numbers.dict");

	if (!dict)
	{
		write(1, "Dict Error\n", 11);
		return (1);
	}

	parsed = parse_dict(dict);

	if (!parsed)
	{
		write(1, "Dict Error\n", 11);
		return (1);
	}

	print_number(number, parsed);

	return (0);
}
