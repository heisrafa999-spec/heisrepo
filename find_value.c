#include "rush.h"

char	*find_value(char *key, t_dict *dict)
{
	int	i;

	i = 0;
	while (dict[i].key)
	{
		if (ft_strcmp(dict[i].key, key) == 0)
			return (dict[i].value);
		i++;
	}
	return (0);
}
