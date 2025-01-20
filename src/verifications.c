/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifications.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/01/20 07:56:27 by nidionis         ###   ########.fr       */
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

int is_sorted_a(t_lnk *lst)
{
	reach_rank_lst_a_in_dir(&lst, NULL, 0, ROTATE, QUIET);
	if (lst->rank != 0)
		return (0);
	lst = lst->next;
	while (lst->rank != 0)
	{
		if (lst->rank >= lst->prev->rank)
			lst = lst->next;
		else
			return (FALSE);
	}
	return (TRUE);
}


int is_sorted_b(t_lnk *lst)
{
	reach_rank_lst_a_in_dir(&lst, NULL, 0, ROTATE, QUIET);
	if (lst->rank != 0)
		return (0);
	lst = lst->prev;
	while (lst->rank != 0)
	{
		if (lst->rank <= lst->next->rank)
			lst = lst->prev;
		else
			return (FALSE);
	}
	return (TRUE);
}

int	is_in_lst(t_lnk *lst, int rank)
{
	t_lnk	*lnk_ind;

	if (!lst)
		return (FALSE);
	lnk_ind = lst->next;
	while (lnk_ind != lst)
	{
		if (lnk_ind->rank == rank)
			return (TRUE);
		lnk_ind = lnk_ind->next;
	}
	return (FALSE);
}

int	is_dup(t_lnk *lst)
{
	t_lnk	*lnk_ind;
	int		nb;

	if (lst->next == lst)
		return (FALSE);
	nb = lst->nb;
	lnk_ind = lst->next;
	while (lnk_ind != lst)
	{
		if (lnk_ind->nb == nb)
			return (TRUE);
		lnk_ind = lnk_ind->next;
	}
	return (FALSE);
}

int	ft_is_duplicate(t_lnk *lst)
{
	t_lnk	*lnk_ind1;

	lnk_ind1 = lst;
	do
	{
		if (is_dup(lnk_ind1))
			return (TRUE);
		lnk_ind1 = lnk_ind1->next;
	} while (lnk_ind1->next != lst);
	return (FALSE);
}
