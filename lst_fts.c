#include "push_swap.h"

void	reset_max(t_lst *lst)
{
	t_lnk 	*tmp;
	int		max;

	if (lst->size == 1)
		max = (lst->first)->nb;
	else
	{
		max = (lst->first)->nb;
		tmp = (lst->first)->next;
		while (tmp != lst->first)
		{
			if (max < tmp->nb)
				max = tmp->nb;
			tmp = tmp->next;
		}	
	}
	lst->max_val = max;
}

void	reset_min(t_lst *lst)
{
	t_lnk 	*tmp;
	int		min;

	if (lst->size == 1)
		min = (lst->first)->nb;
	else
	{
		min = (lst->first)->nb;
		tmp = (lst->first)->next;
		while (tmp != lst->first)
		{
			if (min > tmp->nb)
				min = tmp->nb;
			tmp = tmp->next;
		}	
	}
	lst->min_val = min;
}

t_lnk	*pop(t_lst	*lst)
{
	t_lnk	*poped;

	poped = NULL;
	if (lst && lst->size)
	{
		if (lst->size == 1)
		{
			poped = lst->first;
			lst_init(lst);
		}
		else
		{
			poped = lst->first;
			(lst->last)->next = poped->next;
			(poped->next)->prev = lst->last;
			(lst->first) = poped->next;
			lst->size -= 1;
			if (lst->min_val == poped->nb)
				reset_min(lst);
			if (lst->max_val == poped->nb)
				reset_max(lst);
			refreshRankinlist(lst, poped, "poped");
			refreshIndinlist(lst, poped, "poped");
		}
	}
	return (lnk_init(poped));
}

t_lnk	*push_item(t_lnk *lnk, t_lst *lst)
{
	if (lst && lnk)
	{
		if (lst->size == 0)
		{
			lst->first = lnk;
			lst->last = lnk;
			lst->min_val = lnk->nb;
			lst->max_val = lnk->nb;
		}
		else
		{
			lnk->next = lst->first;
			lnk->prev = lst->last;
			(lst->first)->prev = lnk;
			(lst->last)->next = lnk;
			lst->first = lnk;
		}
		(lst->size)++;
		if (lst->min_val > lnk->nb)
			lst->min_val = lnk->nb;
		if (lst->max_val < lnk->nb)
			lst->max_val = lnk->nb;
		refreshRankinlist(lst, lnk, "pushed");
	}
	else
	{
		if (!lnk)
			error_msg("pushing non existing link\n");
		error_msg("error at push_item\n");
	}
	return (lnk);
}

void	swap_lst(t_lst *lst)
{
	if (lst && lst->size)
	{	
		t_lnk   *item0;
		t_lnk   *item1;

		item0 = lst->first;
		item1 = (lst->first)->next;
		(lst->last)->next = item1;
		item0->next = item1->next;
		(item1->next)->prev = item0;
		item0->prev = item1;
		item1->prev = lst->last;
		item1->next = item0;
		lst->first = item0;
	}
	else
		error_msg("error at swap_lst");
}

/*
void	rev_lst(t_lst *lst)
{
	t_lnk   *lnk;
	t_lnk   *tmp;
	size_t	 looped;

	lnk = lst->first;
	looped = 0;
	if (lst->size)
	{
		while (looped++ < lst->size)
		{
				tmp = lnk->next;
				lnk->next = lnk->prev;
				lnk->prev = tmp;
				lnk = lnk->next;
		}
		tmp = lst->first;
		lst->first = lst->last;
		lst->last = tmp;
	}
}
*/

void rotate_lst(t_lst *lst, int reverse)
{
	if (lst && lst->size > 1)
	{
		if (reverse)
		{
			lst->first = (lst->first)->prev;
			lst->last = (lst->last)->prev;
		}
		else
		{
			lst->first = (lst->first)->next;
			lst->last = (lst->last)->next;
		}
	}
	else
		error_msg("error at rotate_lst");
}

#include <stdio.h>
void print_lst(t_lst *lst_a, t_lst *lst_b)
{
	size_t	loop_nb;
	size_t	ii;
	t_lnk   *lnk_a;
	t_lnk   *lnk_b;

	lnk_a = lst_a->first;
	lnk_b = NULL;
	if (lst_b)
		lnk_b = lst_b->first;
	loop_nb = lst_a->size;
	if (lst_b && lst_a->size < lst_b->size)
		loop_nb = lst_b->size;
	if (lst_a)
		printf("[lst_a]: size=%d,	min_val=%d, 	maw_val=%d\n", lst_a->size, lst_a->min_val, lst_a->max_val);
	if (lst_b)
		printf("[lst_b]: size=%d,	min_val=%d, 	maw_val=%d\n", lst_b->size, lst_b->min_val, lst_b->max_val);
	ii = 0;
	while (ii < loop_nb)
	{
		if (!lst_b)
			printf("%10d\t|\n", lnk_a->nb);
		else
		{
			if (ii < lst_a->size && ii < lst_b->size)
				printf("%8d\t|%8d\n", lnk_a->nb, lnk_b->nb);
			else if (ii < lst_a->size)
				printf("%8d\t|\n", lnk_a->nb);
			else if (ii < lst_b->size)
				printf("\t\t|%8d\n", lnk_b->nb);
		}
		if (lnk_a)
				lnk_a = lnk_a->next;
		if (lnk_b)
				lnk_b = lnk_b->next;
		ii++;
	}
	printf("	***************\n");
}

/*
int main(int argc, char *argv[])
{
	int ii = 0;
	t_lst *lst = get_args(argc, argv);
	t_lnk   *lnk;

	lnk = pop(lst);
	printf("min: %d\n", lst->min_val);
	printf("max: %d\n", lst->max_val);
	print_lst(lst, NULL);
	push_item(lnk, lst);
	printf("min: %d\n", lst->min_val);
	printf("max: %d\n", lst->max_val);
	print_lst(lst, NULL);
	del_list(lst);
}
*/
