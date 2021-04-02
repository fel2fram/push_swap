#include "push_swap.h"

int	execute_2(char *s, t_pile *p1, t_pile *p2)
{
	if (!ft_strcmp(s, "rr"))
		rrotate(p1, p2);
	else if (!ft_strcmp(s, "rra"))
		revrotate(p1);
	else if (!ft_strcmp(s, "rrb"))
		revrotate(p2);
	else if (!ft_strcmp(s, "rrr"))
		rrevrotate(p1, p2);
	else
		return (0);
	return (1);
}

int	execute(char *s, t_pile *p1, t_pile *p2)
{
	if (!ft_strcmp(s, "sa"))
		swap(p1);
	else if (!ft_strcmp(s, "sb"))
		swap(p2);
	else if (!ft_strcmp(s, "ss"))
		sswap(p1, p2);
	else if (!ft_strcmp(s, "pa"))
		push(p1, p2);
	else if (!ft_strcmp(s, "pb"))
		push(p2, p1);
	else if (!ft_strcmp(s, "ra"))
		rotate(p1);
	else if (!ft_strcmp(s, "rb"))
		rotate(p2);
	else
		return (execute_2(s, p1, p2));
	return (1);
}

int	gnl(t_pile *p1, t_pile *p2)
{
	int		error;
	char	*line;
	char	**aline;

	error = 0;
	aline = &line;
	while (get_next_line(0, aline))
	{
		if (!execute(*aline, p1, p2))
			error = 1;
		free(*aline);
	}
	free(*aline);
	return (error);
}

void	iflegit_check(t_pile *p1, t_pile *p2, int argc, char **argv)
{
	int		c;

	c = 0;
	while (c < argc)
		adddown(p1, ft_atoi(argv[c++]));
	if (gnl(p1, p2))
		write(2, "Error\n", 6);
	else if (checksorted(p1, p2))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	while (p1->length)
		popdown(p1);
	while (p2->length)
		popdown(p2);
}

int	main(int argc, char **argv)
{
	t_pile	p1;
	t_pile	p2;
	int		l;

	init(&p1, &p2);
	argc--;
	argv++;
	l = is_string(&argc, &argv);
	if (!argc)
		return (0);
	if (islegit(argc, argv))
		iflegit_check(&p1, &p2, argc, argv);
	else
		write(2, "Error\n", 6);
	if (l)
	{
		while (argc >= 0)
			free(argv[argc--]);
		free(argv);
	}
}
