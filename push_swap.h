#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "get_next_line.h"

typedef struct s_pile_elt
{
	int					x;
	struct s_pile_elt	*up;
	struct s_pile_elt	*down;
}				t_pile_elt;

typedef struct s_pile
{
	int			length;
	t_pile_elt	*top;
	t_pile_elt	*bottom;
}				t_pile;

t_pile_elt	*create(int y);
void		addup(t_pile *p, int y);
void		adddown(t_pile *p, int y);
int			popup(t_pile *p);
int			popdown(t_pile *p);
void		swap(t_pile *p);
void		sswap(t_pile *p1, t_pile *p2);
void		push(t_pile *p1, t_pile *p2);
void		rotate(t_pile *p);
void		rrotate(t_pile *p1, t_pile *p2);
void		revrotate(t_pile *p);
void		rrevrotate(t_pile *p1, t_pile *p2);
int			islegit(int argc, char **argv);
int			checksorted(t_pile *p1, t_pile *p2);
int			issmall(char *num);
int			islegit(int argc, char **argv);
int			execute(char *s, t_pile *p1, t_pile *p2);
void		init(t_pile *p1, t_pile *p2);
int			pushbacksorted(t_pile *p1, t_pile *p2);
int			im(int *t);
void		fetch(t_pile *p1, t_pile *p2, int x, int asc);
int			findmax(t_pile *p1, int *res);
int			findmin(t_pile *p1, int *res);
void		sort3(t_pile *p1);
void		medsort(t_pile *p1, t_pile *p2, int *q, int lq);
void		pb_shell(t_pile *p1, t_pile *p2);
int			*findmedian(int n, int nb, char **l);
void		blsort(char **t, int n);
int			is_string(int *argc, char ***argv);
int			ft_strcmp(const char *s1, const char *s2);

#endif