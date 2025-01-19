/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifications.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/01/19 04:11:38 by nidionis         ###   ########.fr       */
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
			return (FALSE);
	}
	return (TRUE);
}

int	is_in_lst(t_lnk *lst, int val)
{
	t_lnk	*lnk_ind;

	lnk_ind = lst;
	while (lnk_ind->nb != val)
	{
		lnk_ind = lnk_ind->next;
		if (lnk_ind == lst)
			return (FALSE);
	}
	return (TRUE);
}

int	ft_no_duplicate(t_lnk *lst)
{
	t_lnk	*lnk_ind1;

	lnk_ind1 = lst;
	do
	{
		if (is_in_lst(lnk_ind1->next, lnk_ind1->nb))
			return (FALSE);
		lnk_ind1 = lnk_ind1->next;
	} while (lnk_ind1 != lst);
	return (TRUE);
}
