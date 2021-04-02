#include "push_swap.h"

void	blsort(char **t, int n)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (i < n + 1)
	{
		j = 0;
		while (j < n - 1)
		{
			if (ft_atoi(t[j + 1]) < ft_atoi(t[j]))
			{
				tmp = t[j];
				t[j] = t[j + 1];
				t[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	*findmedian(int n, int nb, char **l)
{
	int	*q;
	int	i;

	blsort(l, nb);
	q = malloc((nb + 1) * sizeof(int));
	i = 0;
	while (i < n + 1)
	{
		q[i] = ft_atoi(l[i * (nb - 1) / n]);
		i++;
	}
	q[i - 1] += 1;
	return (q);
}

void	pb_shell(t_pile *p1, t_pile *p2)
{
	int	cra;

	cra = 0;
	while (p2->length)
	{
		cra += pushbacksorted(p1, p2);
	}
	while (cra)
	{
		rotate(p1);
		write(1, "ra\n", 3);
		cra--;
	}
}

void	medsort(t_pile *p1, t_pile *p2, int *q, int lq)
{
	int	i;
	int	j;

	i = 0;
	while (i < lq - 1)
	{
		j = p1->length;
		while (j)
		{
			if (q[i] <= p1->top->x && p1->top->x < q[i + 1])
			{
				push(p2, p1);
				write(1, "pb\n", 3);
			}
			else
			{
				rotate(p1);
				write(1, "ra\n", 3);
			}
			j--;
		}
		pb_shell(p1, p2);
		i++;
	}
}

void	sort3(t_pile *p1)
{
	int	imin;
	int	imax;
	int	vmin;
	int	vmax;

	imin = findmin(p1, &vmin);
	imax = findmax(p1, &vmax);
	if ((imin - imax + p1->length) % p1->length == 1)
	{
		if (imax == 0)
			rotate(p1);
		if (imax == 0)
			write(1, "ra\n", 3);
		else if (imax == 1 && p1->length == 3)
		{
			revrotate(p1);
			write(1, "rra\n", 4);
		}
		return ;
	}
	swap(p1);
	write(1, "sa\n", 3);
	sort3(p1);
}
