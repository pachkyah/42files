#include "push_swap.h"

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	add_number(char *str, t_stack **a)
{
	long	num;

	if (!is_valid_number(str))
		error_exit();
	num = ft_atol(str);
	if (num > INT_MAX || num < INT_MIN)
		error_exit();
	stack_add_back(a, stack_new((int)num));
}

void	parse_args(int argc, char **argv, t_stack **a)
{
	int		i;
	int		j;
	char	**split;

	i = 1;
	while (i < argc)
	{
		if (!argv[i][0])
			error_exit();
		split = ft_split(argv[i], ' ');
		if (!split)
			error_exit();
		j = 0;
		while (split[j])
		{
			add_number(split[j], a);
			free(split[j]);
			j++;
		}
		free(split);
		i++;
	}
	check_duplicates(*a);
}
