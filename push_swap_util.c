#include "push_swap.h"

int	findmin(t_pile *p1, int *res)
{
	int			imin;
	t_pile_elt	*elt;
	int			i;
	int			l;

	imin = 0;
	i = 0;
	l = p1->length;
	*res = 2147483647;
	elt = p1->top;
	while (i < l)
	{
		if (elt->x < *res)
		{
			*res = elt->x;
			imin = i;
		}
		if (i != l - 1)
			elt = elt->down;
		i++;
	}
	return (imin);
}

int	findmax(t_pile *p1, int *res)
{
	int			imax;
	t_pile_elt	*elt;
	int			i;
	int			l;

	imax = 0;
	i = 0;
	l = p1->length;
	*res = -2147483648;
	elt = p1->top;
	while (i < l)
	{
		if (elt->x > *res)
		{
			*res = elt->x;
			imax = i;
		}
		if (i != l - 1)
			elt = elt->down;
		i++;
	}
	return (imax);
}

void	fetch(t_pile *p1, t_pile *p2, int x, int asc)
{
	while (p2->top->x != x)
	{
		if (asc)
		{
			rotate(p2);
			write(1, "rb\n", 3);
		}
		else
		{
			revrotate(p2);
			write(1, "rrb\n", 4);
		}
	}
	push(p1, p2);
	write(1, "pa\n", 3);
}

int	im(int *t)
{
	int	vmin;
	int	imin;
	int	i;

	vmin = 2147483647;
	i = 0;
	while (i < 4)
	{
		if (t[i] < vmin)
		{
			imin = i;
			vmin = t[i];
		}
		i++;
	}
	return (imin);
}

int	pushbacksorted(t_pile *p1, t_pile *p2)
{
	int	vmin;
	int	vmax;
	int	r;
	int	t[4];

	t[0] = findmin(p2, &vmin);
	t[2] = findmax(p2, &vmax);
	t[1] = p2->length - t[0];
	t[3] = p2->length - t[2];
	r = im(t);
	fetch(p1, p2, vmin * (r < 2) + vmax * (r >= 2), (r + 1) % 2);
	if (r <= 1)
	{
		rotate(p1);
		write(1, "ra\n", 3);
		return (0);
	}
	return (1);
}
