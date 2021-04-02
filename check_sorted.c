#include "push_swap.h"

int	checksorted(t_pile *p1, t_pile *p2)
{
	t_pile_elt	*elt;

	if (p2->top)
		return (0);
	elt = p1->top;
	while (elt && elt->down)
	{
		if (elt->down->x < elt->x)
			return (0);
		elt = elt->down;
	}
	return (1);
}
