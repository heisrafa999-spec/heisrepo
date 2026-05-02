#ifndef RUSH_H
# define RUSH_H

typedef struct s_dict
{
	char *key;
	char *value;
}	t_dict;

int		is_number(char *str);
void	ft_putstr(char *str);
char	*read_dict(char *filename);
t_dict	*parse_dict(char *str);

#endifexit

