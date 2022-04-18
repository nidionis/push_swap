/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_fts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:25:34 by supersko          #+#    #+#             */
/*   Updated: 2022/04/18 19:34:10 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			refresh_lnks_pop(lst);
		refresh_afterpop_inlist(poped, lst);
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
		}
		else
			refresh_lnks_push(lnk, lst);
		(lst->size)++;
		if (lst->min_val > lnk->nb)
			lst->min_val = lnk->nb;
		if (lst->max_val < lnk->nb)
			lst->max_val = lnk->nb;
		refresh_afterpush_inlist(lst, lnk);
		if (!lnk)
			error_msg("pushing non existing link\n");
		return (lnk);
	}
	error_msg("error at push_item\n");
}

void	swap_lst(t_lst *lst)
{
	t_lnk	*item0;
	t_lnk	*item1;

	if (lst && lst->size)
	{	
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

void	rotate_lst(t_lst *lst, int reverse)
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

/*
int main(int argc, char *argv[])
{
	int ii = 0;
	t_lst *lst = get_args(argc, argv);
	t_lnk	*lnk;

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

/*
void	rev_lst(t_lst *lst)
{
	t_lnk	*lnk;
	t_lnk	*tmp;
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
