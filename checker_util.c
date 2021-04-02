#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i]
		&& (unsigned char)s1[i] == (unsigned char)s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	revrotate(t_pile *p)
{
	int	x;

	if (p->length > 1)
	{
		x = popdown(p);
		addup(p, x);
	}
}

void	rrevrotate(t_pile *p1, t_pile *p2)
{
	revrotate(p1);
	revrotate(p2);
}
