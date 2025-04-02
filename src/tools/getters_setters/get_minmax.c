/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:49:48 by nidionis          #+#    #+#             */
/*   Updated: 2025/04/02 17:12:55 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lnk	*get_max(t_lnk *lst)
{
	t_lnk	*tmp;
	t_lnk	*max;

	tmp = lst;
	max = lst;
	if (!lst)
		return (NULL);
	tmp = tmp->next;
	while (tmp != lst)
	{
		if (tmp->rank > max->rank)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

t_lnk	*get_min(t_lnk *lst)
{
	t_lnk	*tmp;
	t_lnk	*min;

	tmp = lst;
	min = lst;
	if (!lst)
		return (NULL);
	tmp = tmp->next;
	while (tmp != lst)
	{
		if (tmp->rank < min->rank)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

t_lnk	*get_softmax(t_lnk *lst)
{
	t_lnk	*tmp;

	if (!lst || lst->next == lst)
		return (NULL);
	tmp = get_max(lst);
	if (tmp->rank == tmp->prev->rank + 1)
		while (tmp->rank == tmp->prev->rank + 1)
			rrotate_lst(&tmp);
	return (tmp);
}

t_lnk	*get_softmin(t_lnk *lst)
{
	t_lnk	*tmp;

	if (!lst || lst->next == lst)
		return (NULL);
	tmp = get_min(lst);
	if (tmp->rank == tmp->next->rank - 1)
		while (tmp->rank == tmp->next->rank - 1)
			rotate_lst(&tmp);
	return (tmp);
}
