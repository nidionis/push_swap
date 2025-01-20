/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/01/20 03:14:18 by nidionis         ###   ########.fr       */
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

int get_size(t_lnk *lst)
{
	t_lnk	*lnk;
	int size;

	if (!lst)
		return (0);
	size = 1;
	lnk = lst->next;
	while (lnk != lst)
	{
		size++;
		lnk = lnk->next;
	}
	return (size);
}

int get_max(t_lnk *lst)
{
	t_lnk	*lnk;
	int max;

	if (!lst)
		return (EMPTY_LIST);
	max = lst->rank;
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

	if (!lst)
		return (EMPTY_LIST);
	min = lst->rank;
	lnk = lst->next;
	while (lnk != lst)
	{
		if (lnk->rank < min)
			min = lnk->rank;
		lnk = lnk->next;
	}
	return (min);
}