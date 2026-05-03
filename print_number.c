#include "rush.h"

void	print_2digits(char *nbr, t_dict *dict);

void	print_number(char *nbr, t_dict *dict)
{
	int len;

	len = 0;
	while (nbr[len])
		len++;

	// 🔹 CASO 0–20
	if (len == 1 || (len == 2 && nbr[0] == '1'))
	{
		ft_putstr(find_value(nbr, dict));
		ft_putstr("\n");
		return;
	}

	// 🔹 CASO 20–99
	if (len == 2)
	{
		print_2digits(nbr, dict);
		return;
	}

	// 🔹 CASO 100–999
	if (len == 3)
	{
		char hundred[2];
		char rest[3];

		hundred[0] = nbr[0];
		hundred[1] = '\0';

		ft_putstr(find_value(hundred, dict));
		ft_putstr(" hundred");

		// se resto for 00
		if (nbr[1] == '0' && nbr[2] == '0')
		{
			ft_putstr("\n");
			return;
		}

		ft_putstr(" ");

		rest[0] = nbr[1];
		rest[1] = nbr[2];
		rest[2] = '\0';

		print_2digits(rest, dict);
		return;
	}
}
