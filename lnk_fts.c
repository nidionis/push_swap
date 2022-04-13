#include "push_swap.h"

t_lnk	*lnk_init(t_lnk *lnk)
{
	lnk->next = lnk;
	lnk->prev = lnk;
	return (lnk);
}

t_lnk	*new_lnk(int nb, int ind, int rank)
{
	t_lnk	*lnk;

	lnk = (t_lnk *) malloc(sizeof(t_lnk));
	if (!lnk)
		error_msg("Error creating a new link\n");
	else
	{
		lnk->nb = nb;
		lnk->ind = ind;
		lnk->rank = rank;
		lnk_init(lnk);
	}
	return (lnk);
}

t_lst   *new_lst(void)
{
	t_lst   *lst;

	lst = (t_lst *) malloc(sizeof(t_lst));
	lst_init(lst);
	return (lst);
}

void   lst_init(t_lst *lst)
{
	lst->first = NULL;
	lst->last = NULL;
	lst->min_val = INT_MIN;
	lst->max_val = INT_MAX;
	lst->size = 0;
}

void	*del_list(t_lst *lst)
{
	t_lnk   *lnk;
	while (lst->size > 0)
	{
		lnk = pop(lst);
		free(lnk);
	}
	free(lst);
}
