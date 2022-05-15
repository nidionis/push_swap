/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:10:49 by supersko          #+#    #+#             */
/*   Updated: 2022/05/15 22:29:05 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	refresh_afterpop_inlist(t_lst *lst, t_lnk *moved_item)
{
	t_lnk	*lnk;

	lnk = lst->first;
	if (lnk)
		while (lnk->next != lst->first)
		{
			if (lnk->rankinlist > moved_item->rankinlist)
				lnk->rankinlist -= 1;
			if (lnk->indinlist > moved_item->indinlist)
				lnk->indinlist -= 1;
			lnk = lnk->next;
		}
}

void	refresh_afterpush_inlist(t_lst *lst, t_lnk *moved_item)
{
	t_lnk	*lnk;

	lnk = lst->first;
	lnk->indinlist = 0;
	lnk->rankinlist = 0;
	while (lnk->next != lst->first)
	{
		if (lnk->nb > moved_item->nb)
		{
			if (moved_item->rankinlist <= lnk->rankinlist &&
					moved_item->nb > lnk->nb)
				moved_item->rankinlist = lnk->rankinlist;
			if (lnk->nb > moved_item->nb)
			lnk->rankinlist += 1;
		}
		lnk = lnk->next;
		lnk->indinlist += 1;
	}
}

void	refresh_lnks_pop(t_lst *lst)
{
	t_lnk	*poped;

	poped = lst->first;
	(lst->last)->next = poped->next;
	(poped->next)->prev = lst->last;
	(lst->first) = poped->next;
	lst->size -= 1;
	if (lst->min_val == poped->nb)
		reset_min(lst);
	if (lst->max_val == poped->nb)
		reset_max(lst);
}

void	refresh_lnks_push(t_lnk *lnk, t_lst *lst)
{
	if (lst && lst->size == 0)
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
}
