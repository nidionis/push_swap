/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifications.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/24 18:22:22 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	is_sorted(t_lnk *lst)
{
	if (lst->rank != 0)
		return (0);
	lst = lst->next;
	while (lst->rank != 0)
	{
		if (lst->rank == lst->prev->rank + 1)
			lst = lst->next;
		else
			return (0);
	}
	return (1);
}

int	ft_no_duplicate(t_lnk *lst)
{
	t_lnk	*lnk_ind1;
	t_lnk	*lnk_ind2;

	lnk_ind1 = lst;
	lnk_ind2 = lnk_ind1->next;
	while (lnk_ind1 != lnk_ind2)
	{
		if (lnk_ind1->nb == lnk_ind2->nb)
			return (0);
		lnk_ind2 = lnk_ind2->next;
	}
	lnk_ind1 = lnk_ind1->next;
	while (lnk_ind1 != lst)
	{
		lnk_ind2 = lnk_ind1->next;
		while (lnk_ind1 != lnk_ind2)
		{
			if (lnk_ind1->nb == lnk_ind2->nb)
				return (0);
			lnk_ind2 = lnk_ind2->next;
		}
		lnk_ind1 = lnk_ind1->next;
	}
	return (1);
}
