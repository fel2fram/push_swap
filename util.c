#include "push_swap.h"

int	issmall(char *num)
{
	if (num[0] == '-')
	{
		if (ft_strlen(num) > 11 || (ft_strlen(num) == 11 && ft_atoi(num) > 0))
			return (0);
	}
	else if (num[0] == '+')
	{
		if (ft_strlen(num) > 11 || (ft_strlen(num) == 11 && ft_atoi(num) < 0))
			return (0);
	}
	else
	{
		if (ft_strlen(num) > 10 || (ft_strlen(num) == 10 && ft_atoi(num) < 0))
			return (0);
	}
	return (1);
}

int	islegit(int argc, char **argv)
{
	int	i;
	int	j;

	i = -1;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
			if (!(ft_isdigit(argv[i][j]) || ((j == 0)
					&& (argv[i][j] == '-' || argv[i][j] == '+'))))
				return (0);
		if (!issmall(argv[i]))
			return (0);
		j = -1;
		while (++j < i)
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
	}
	return (1);
}

int	is_string(int *argc, char ***argv)
{
	int	i;

	if (*argc == 1)
	{
		*argv = ft_split((*argv)[0], ' ');
		i = 0;
		while ((*argv)[i])
			i++;
		*argc = i;
		return (1);
	}
	return (0);
}

void	init(t_pile *p1, t_pile *p2)
{
	p1->length = 0;
	p1->bottom = NULL;
	p1->top = NULL;
	p2->length = 0;
	p2->bottom = NULL;
	p2->top = NULL;
}
