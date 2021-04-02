#include "push_swap.h"

void	swap(t_pile *p)
{
	int	x;
	int	y;

	if (p->length > 1)
	{
		x = popup(p);
		y = popup(p);
		addup(p, x);
		addup(p, y);
	}
}

void	sswap(t_pile *p1, t_pile *p2)
{
	swap(p1);
	swap(p2);
}

void	push(t_pile *p1, t_pile *p2)
{
	int	x;

	if (p2->length)
	{
		x = popup(p2);
		addup(p1, x);
	}
}

void	rotate(t_pile *p)
{
	int	x;

	if (p->length > 1)
	{
		x = popup(p);
		adddown(p, x);
	}
}

void	rrotate(t_pile *p1, t_pile *p2)
{
	rotate(p1);
	rotate(p2);
}
