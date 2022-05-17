/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sucks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/17 14:13:27 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

// reach rank 0 
int	get_RelMax(t_lnk *lst, int rankMax)
{
	t_lnk	*first_lnk;

	if (!lst || rankMax < 1)
		return (0);
	first_lnk = lst;
	if (lst->rank != rankMax)
	{
		lst = lst->next;
		while (lst->rank != rankMax && lst != first_lnk)
			lst = lst->next;
	}
	while (lst->rank == (lst->prev)->rank + 1)
		lst = lst->prev;
	return (lst->rank);
}

int	get_RelMin(t_lnk *lst)
{
	t_lnk	*first_lnk;

	if (!lst)
		return (0);
	first_lnk = lst;
	if (lst->rank != 0)
	{
		lst = lst->next;
		while (lst->rank != 0 && lst != first_lnk)
			lst = lst->next;
	}
	while (lst->rank == (lst->next)->rank - 1)
		lst = lst->next;
	return (lst->rank);
}