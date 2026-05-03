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

char	*find_value(char *key, t_dict *dict);
int	ft_strcmp(char *s1, char *s2);
int	ft_strlen(char *str);

void	print_number(char *nbr, t_dict *dict);
void	print_2digits(char *nbr, t_dict *dict);

#endif
