#include "push_swap.h"

t_lst	*reachSorting_up_decr(t_lst *lst, int rank_nb)
{
	if (lst && lst->size > 1 && rank_nb < lst->size)
	{
		if ((lst->first)->rankinlist == ((lst->first)->next)->rankinlist)
			lst_init_rankinlist(lst);
		while ((lst->first)->rankinlist != rank_nb)
		{
			if ((lst->first)->rankinlist > ((lst->first)->next)->rankinlist)
				swap("A", lst, NULL);
			if  ((lst->first)->rankinlist != rank_nb)
				rotate("RA", lst, NULL);
		}
		return (lst);
	}
}

t_lst	*reachSorting_up_incr(t_lst *lst, int rank_nb)
{
	if (lst && lst->size > 1 && rank_nb < lst->size)
	{
		if ((lst->first)->rankinlist == ((lst->first)->next)->rankinlist)
			lst_init_rankinlist(lst);
		while ((lst->first)->rankinlist != rank_nb)
		{
			if ((lst->first)->rankinlist < ((lst->first)->next)->rankinlist)
				swap("A", lst, NULL);
			if  ((lst->first)->rankinlist != rank_nb)
				rotate("RA", lst, NULL);
		}
		return (lst);
	}
}

t_lst	*reachSorting_down_incr(t_lst *lst, int rank_nb)
{
	if (lst && lst->size > 1 && rank_nb < lst->size)
	{
		if ((lst->first)->rankinlist == ((lst->first)->next)->rankinlist)
			lst_init_rankinlist(lst);
		while ((lst->first)->rankinlist != rank_nb)
		{
			if ((lst->first)->rankinlist < ((lst->first)->next)->rankinlist)
				swap("A", lst, NULL);
			if  ((lst->first)->rankinlist != rank_nb)
				rotate("A", lst, NULL);
		}
		return (lst);
	}
}

t_lst	*reachSorting_down_decr(t_lst *lst, int rank_nb)
{
	if (lst && lst->size > 1 && rank_nb < lst->size)
	{
		if ((lst->first)->rankinlist == ((lst->first)->next)->rankinlist)
			lst_init_rankinlist(lst);
		while ((lst->first)->rankinlist != rank_nb)
		{
			if ((lst->first)->rankinlist > ((lst->first)->next)->rankinlist)
				swap("A", lst, NULL);
			if  ((lst->first)->rankinlist != rank_nb)
				rotate("A", lst, NULL);
		}
		return (lst);
	}
}

