#include "rush.h"

void	print_2digits(char *nbr, t_dict *dict)
{
	char tens[3];
	char units[2];

	if (nbr[1] == '0')
	{
		tens[0] = nbr[0];
		tens[1] = '0';
		tens[2] = '\0';

		ft_putstr(find_value(tens, dict));
		ft_putstr("\n");
		return;
	}

	tens[0] = nbr[0];
	tens[1] = '0';
	tens[2] = '\0';

	units[0] = nbr[1];
	units[1] = '\0';

	ft_putstr(find_value(tens, dict));
	ft_putstr(" ");
	ft_putstr(find_value(units, dict));
	ft_putstr("\n");
}
