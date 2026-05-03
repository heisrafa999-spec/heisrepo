#include "rush.h"

int	safe_put(char *key, t_dict *dict)
{
	char *res;

	res = find_value(key, dict);
	if (!res)
	{
		ft_putstr("Dict Error\n");
		return (0);
	}
	ft_putstr(res);
	return (1);
}

/* ===================== UTILS ===================== */

int	get_group_count(int len)
{
	return ((len + 2) / 3);
}

/* ===================== 2 DIGITS ===================== */

void	print_2digits(char *nbr, t_dict *dict)
{
	char tens[3];
	char units[2];

	if (nbr[0] == '1')
	{
		ft_putstr(find_value(nbr, dict));
		return;
	}

	tens[0] = nbr[0];
	tens[1] = '0';
	tens[2] = '\0';

	if (nbr[1] == '0')
	{
		ft_putstr(find_value(tens, dict));
		return;
	}

	units[0] = nbr[1];
	units[1] = '\0';

	ft_putstr(find_value(tens, dict));
	ft_putstr(" ");
	ft_putstr(find_value(units, dict));
}

/* ===================== 0–999 ===================== */

void	print_3digits(char *nbr, t_dict *dict)
{
	char hundred[2];

	if (nbr[0] != '0')
	{
		hundred[0] = nbr[0];
		hundred[1] = '\0';

		ft_putstr(find_value(hundred, dict));
		ft_putstr(" ");
		ft_putstr(find_value("100", dict));

		if (nbr[1] != '0' || nbr[2] != '0')
			ft_putstr(" ");
	}

	if (nbr[1] != '0' || nbr[2] != '0')
	{
		if (nbr[1] == '0')
		{
			char unit[2];
			unit[0] = nbr[2];
			unit[1] = '\0';
			ft_putstr(find_value(unit, dict));
		}
		else
		{
			print_2digits(&nbr[1], dict);
		}
	}
}

/* ===================== BLOCO ===================== */

int	is_zero_block(char *block)
{
	return (block[0] == '0' && block[1] == '0' && block[2] == '0');
}

void	print_block(char *nbr, int size, t_dict *dict)
{
	char block[4];
	int	i = 0;
	int	j = 0;

	while (i < 3 - size)
		block[i++] = '0';

	while (j < size)
		block[i++] = nbr[j++];

	block[3] = '\0';

	if (is_zero_block(block))
		return;

	print_3digits(block, dict);
}

/* ===================== CÉREBRO ===================== */

void	print_number(char *nbr, t_dict *dict)
{
	int len = ft_strlen(nbr);
	int group_count = get_group_count(len);
	int first_group_size = len % 3;
	int i = 0;
	int index = 0;

	if (first_group_size == 0)
		first_group_size = 3;

	while (i < group_count)
	{
		int size;
		char block[4];
		int j = 0;
		int k = 0;

		if (i == 0)
			size = first_group_size;
		else
			size = 3;

		// construir bloco
		while (k < 3 - size)
			block[k++] = '0';
		while (j < size)
			block[k++] = nbr[index + j++];
		block[3] = '\0';

		if (!is_zero_block(block))
		{
			print_3digits(block, dict);

			int scale = group_count - i - 1;

			if (scale > 0)
			{
				if (scale == 1)
					ft_putstr(find_value("1000", dict));
				else if (scale == 2)
					ft_putstr(find_value("1000000", dict));
				else if (scale == 3)
					ft_putstr(find_value("1000000000", dict));
			}

			// só mete espaço se ainda houver números depois
			int next = index + size;
			int only_zeros = 1;

			while (next < len)
			{
				if (nbr[next] != '0')
					only_zeros = 0;
				next++;
			}
			if (!only_zeros)
				ft_putstr(" ");
		}

		index += size;
		i++;
	}

	ft_putstr("\n");
}
