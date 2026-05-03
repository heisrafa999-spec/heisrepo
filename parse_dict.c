#include "rush.h"
#include <stdlib.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

char	*str_dup_range(char *str, int start, int end)
{
	char	*res;
	int		i;

	if (end <= start)
		return (0);
	res = malloc(end - start + 1);
	if (!res)
		return (0);
	i = 0;
	while (start < end)
		res[i++] = str[start++];
	res[i] = '\0';
	return (res);
}

t_dict	parse_line(char *line)
{
	t_dict	entry;
	int		i;
	int		start;

	entry.key = 0;
	entry.value = 0;
	i = 0;

	while (line[i] && is_space(line[i]))
		i++;

	start = i;
	while (line[i] && line[i] != ':' && !is_space(line[i]))
		i++;
	entry.key = str_dup_range(line, start, i);

	while (line[i] && line[i] != ':')
		i++;
	if (line[i] == ':')
		i++;

	while (line[i] && is_space(line[i]))
		i++;

	start = i;
	while (line[i] && line[i] != '\n')
		i++;
	entry.value = str_dup_range(line, start, i);

	return (entry);
}

int	is_empty_line(char *str, int start, int end)
{
	while (start < end)
	{
		if (!is_space(str[start]))
			return (0);
		start++;
	}
	return (1);
}

int	count_lines(char *str)
{
	int	i;
	int	count;
	int	start;

	i = 0;
	count = 0;
	start = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			if (!is_empty_line(str, start, i))
				count++;
			start = i + 1;
		}
		i++;
	}
	if (i > start && !is_empty_line(str, start, i))
		count++;
	return (count);
}

t_dict	*parse_dict(char *str)
{
	t_dict	*dict;
	int		i;
	int		j;
	int		start;
	int		lines;

	i = 0;
	j = 0;
	start = 0;
	lines = count_lines(str);

	dict = malloc(sizeof(t_dict) * (lines + 1));
	if (!dict)
		return (0);

	while (str[i])
	{
		if (str[i] == '\n')
		{
			if (i > start && !is_empty_line(str, start, i))
				dict[j++] = parse_line(&str[start]);
			start = i + 1;
		}
		i++;
	}
	if (i > start && !is_empty_line(str, start, i))
		dict[j++] = parse_line(&str[start]);

	dict[j].key = 0;
	dict[j].value = 0;

	return (dict);
}
