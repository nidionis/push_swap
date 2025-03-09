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

/**
 * @brief Checks if a list is sorted by rank without modifying it
 * This version safely checks for sorted order without moving the list.
 * 
 * @param lst List to check
 * @return int TRUE if sorted, FALSE otherwise
 */
int	is_sorted(t_lnk *lst)
{
	t_lnk	*start;
	
	if (!lst)
		return (TRUE); /* Empty list is sorted */
	
	/* Save starting point */
	start = lst;
	
	/* Check each node with the next until we come back to start */
	while (lst->next != start)
	{
		/* Check if current rank and next rank are sequential */
		if (lst->rank + 1 != lst->next->rank)
			return (FALSE);
		lst = lst->next;
	}
	return (TRUE);
}

/**
 * @brief Checks if a list contains rank 0 and is sorted from that point
 * 
 * @param lst List to check
 * @return int TRUE if list contains rank 0 and is sorted, FALSE otherwise
 */
int	has_rank_zero_and_sorted(t_lnk *lst)
{
	t_lnk	*start;
	t_lnk	*zero_pos;
	
	if (!lst)
		return (FALSE); /* Empty list doesn't have rank 0 */
	
	/* Find rank 0 in the list */
	start = lst;
	zero_pos = NULL;
	
	do {
		if (lst->rank == 0) {
			zero_pos = lst;
			break;
		}
		lst = lst->next;
	} while (lst != start);
	
	/* If rank 0 not found, return FALSE */
	if (!zero_pos)
		return (FALSE);
	
	/* Start from rank 0 and check if list is sorted */
	return (is_sorted(zero_pos));
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
