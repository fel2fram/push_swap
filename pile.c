#include "push_swap.h"

t_pile_elt	*create(int y)
{
	t_pile_elt	*newpile;

	newpile = malloc(sizeof(t_pile_elt));
	newpile->x = y;
	newpile->up = NULL;
	newpile->down = NULL;
	return (newpile);
}

void	addup(t_pile *p, int y)
{
	t_pile_elt	*newpile;

	newpile = create(y);
	newpile->down = p->top;
	if (p->top)
	{
		p->top->up = newpile;
		p->top = newpile;
	}
	else
	{
		p->top = newpile;
		p->bottom = newpile;
	}
	p->length++;
}

void	adddown(t_pile *p, int y)
{
	t_pile_elt	*newpile;

	newpile = create(y);
	newpile->up = p->bottom;
	if (p->top)
	{
		p->bottom->down = newpile;
		p->bottom = newpile;
	}
	else
	{
		p->bottom = newpile;
		p->top = newpile;
	}
	p->length++;
}

int	popup(t_pile *p)
{
	int			oldtopval;
	t_pile_elt	*oldtop;

	oldtopval = p->top->x;
	oldtop = p->top;
	p->top = p->top->down;
	free(oldtop);
	p->length -= 1;
	if (!p->length)
	{
		p->bottom = NULL;
		p->top = NULL;
	}
	else
		p->top->up = NULL;
	return (oldtopval);
}

int	popdown(t_pile *p)
{
	int			oldbotval;
	t_pile_elt	*oldbot;

	oldbotval = p->bottom->x;
	oldbot = p->bottom;
	p->bottom = p->bottom->up;
	free(oldbot);
	p->length -= 1;
	if (!p->length)
	{
		p->top = NULL;
		p->bottom = NULL;
	}
	else
		p->bottom->down = NULL;
	return (oldbotval);
}
