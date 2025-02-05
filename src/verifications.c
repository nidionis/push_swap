/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifications.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/01/31 18:35:28 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	is_sorted(t_lnk *lst)
{
	t_lnk	*lst_orig;

	reach_rank(&lst, 0, rr, QUIET);
	lst_orig = lst;
	while (lst != lst_orig->prev)
	{
		if (lst->rank == lst->next->rank - 1)
			lst = lst->next;
		else
			return (FALSE);
	}
	return (TRUE);
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
