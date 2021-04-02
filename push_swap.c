#include "push_swap.h"

void	sort5aux(t_pile *p1, t_pile *p2, int vmin, int vmax)
{
	if (p2->top->x == vmin)
	{
		swap(p2);
		write(1, "sb\n", 3);
	}
	push(p1, p2);
	write(1, "pa\n", 3);
	rotate(p1);
	write(1, "ra\n", 3);
	push(p1, p2);
	write(1, "pa\n", 3);
}

void	sort5(t_pile *p1, t_pile *p2)
{
	int	vmin;
	int	vmax;
	int	i;

	findmin(p1, &vmin);
	findmax(p1, &vmax);
	i = p1->length;
	while (i > 0)
	{
		if (p1->top->x == vmin || p1->top->x == vmax)
		{
			push(p2, p1);
			write(1, "pb\n", 3);
		}
		else
		{
			rotate(p1);
			write(1, "ra\n", 3);
		}
		i--;
	}
	sort3(p1);
	sort5aux(p1, p2, vmin, vmax);
}

void	execute_small(t_pile *p1, t_pile *p2, int argc, char **argv)
{
	int	*q;

	if (argc <= 1)
	{
	}
	else if (argc <= 3)
		sort3(p1);
	else if (argc <= 5)
		sort5(p1, p2);
	else if (argc <= 200)
	{
		q = findmedian(3, argc, argv);
		medsort(p1, p2, q, 4);
		free(q);
	}
	else
	{
		q = findmedian(6, argc, argv);
		medsort(p1, p2, q, 7);
		free(q);
	}
}

void	iflegit(t_pile *p1, t_pile *p2, int argc, char **argv)
{
	int		c;

	c = 0;
	while (c < argc)
	{
		adddown(p1, ft_atoi(argv[c]));
		c++;
	}
	execute_small(p1, p2, argc, argv);
	while (c)
	{
		popdown(p1);
		c--;
	}
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
	if (islegit(argc, argv))
		iflegit(&p1, &p2, argc, argv);
	else
		write(2, "Error\n", 6);
	if (l)
	{
		while (argc >= 0)
			free(argv[argc--]);
		free(argv);
	}
}
