/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_refreshing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:42:45 by supersko          #+#    #+#             */
/*   Updated: 2022/04/18 19:22:21 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_max(t_lst *lst)
{
	t_lnk	*tmp;
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
	t_lnk	*tmp;
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
