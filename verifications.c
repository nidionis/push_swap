/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifications.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/21 16:54:03 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int ft_is_sorted(t_lnk *lst)
{
    t_lnk	*lnk_ind;
    int     is_sorted;

    is_sorted = 0;
	lnk_ind = lst->next;
    if (lnk_ind->rank != lnk_ind->rank + 1)	
    {
        is_sorted = -1;
    }
    if (lnk_ind->rank != lnk_ind->rank - 1)	
    {
        is_sorted = 1;
    }
	while (lnk_ind != lst)
	{
        if (lnk_ind->rank != lnk_ind->rank + is_sorted)
        {
            is_sorted = 0;
            break;
        }
		lnk_ind = lnk_ind->next;
	}
    if (is_sorted)
        return (1);
    return (0);
}

int is_sorted(t_lnk *lst)
{
    t_lnk	*lnk_ind;
    int     is_sorted;

    is_sorted = 0;
    if (!lst)
        is_sorted = 1;
	lnk_ind = lst->next;
	while (lnk_ind != lst)
	{
        if (lnk_ind->rank == lnk_ind->next->rank - 1)
            lnk_ind = lnk_ind->next;
        else
        {
            is_sorted++;
            if (is_sorted > 1)
                return (0);
            lnk_ind = lnk_ind->next;
        }
	}
    return (1);
}

int ft_no_duplicate(t_lnk *lst)
{
    t_lnk	*lnk_ind1;
    t_lnk	*lnk_ind2;

	lnk_ind1 = lst;
	do
    {
	    lnk_ind2 = lnk_ind1->next;
        while (lnk_ind1 != lnk_ind2)
	    {
           if (lnk_ind1->nb == lnk_ind2->nb)
               return (0);
	    	lnk_ind2 = lnk_ind2->next;
	    }
	    lnk_ind1 = lnk_ind1->next;
    } while (lnk_ind1 != lst);
    return (1);
}