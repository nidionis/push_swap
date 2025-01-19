/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/01/20 00:10:12 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	is_min_or_max(t_lnk *lst_a, int i1, int i2)
{
	if (lst_a->rank == i1)
		return (LOWEST);
	if (lst_a->rank == i2)
		return (MAX);
	return (MAYBE_A_WEAKNESS);
}

int get_dir(t_lnk *lst, int target_rk, int intermediate_target)
{
	int dir;

	dir = get_shortestway(lst, target_rk);
	dir -= get_shortestway(lst, intermediate_target);
	return (dir);
}

int get_softmin_a(t_lnk *lst)
{
	int max;
	t_lnk *l_ind;

	if (!lst)
		return (INT_MIN);
	l_ind = lst->prev;
	max = get_max(lst);
	reach_rank(&l_ind, max, REVERSE_ROTATE, QUIET);
	while (lst->rank == max--)
		lst = lst->prev;
	return (max);
}


int get_softmax_a(t_lnk *lst)
{
	int min;
	t_lnk *l_ind;

	if (!lst)
		return (INT_MIN);
	l_ind = lst->next;
	min = get_min(lst);
	reach_rank(&l_ind, min, ROTATE, QUIET);
	while (lst->rank == min++)
		lst = lst->next;
	return (min);
}


int get_max(t_lnk *lst)
{
	t_lnk	*lnk;
	int max;

	max = INT_MIN;
	lnk = lst->next;
	while (lnk != lst)
	{
		if (lnk->rank > max)
			max = lnk->rank;
		lnk = lnk->next;
	}
	return (max);
}

int get_min(t_lnk *lst)
{
	t_lnk	*lnk;
	int min;

	min = INT_MAX;
	lnk = lst->next;
	while (lnk != lst)
	{
		if (lnk->rank < min)
			min = lnk->rank;
		lnk = lnk->next;
	}
	return (min);
}