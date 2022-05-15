/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifications.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/15 17:14:39 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int ft_is_sorted(t_lnk *lst)
{
    t_lnk	*lnk_ind;
    int     is_sorted;

    is_sorted = 0;
	lnk_ind = lst->next;
    if (((t_itm *)lnk_ind->itm)->rank != ((t_itm *)(lnk_ind->prev)->itm)->rank + 1)	
        is_sorted = -1;
    if (((t_itm *)lnk_ind->itm)->rank != ((t_itm *)(lnk_ind->prev)->itm)->rank - 1)	
        is_sorted = 1;
	while (lnk_ind != lst)
	{
        if (((t_itm *)lnk_ind->itm)->rank != ((t_itm *)(lnk_ind->prev)->itm)->rank + is_sorted)
        {
            is_sorted = 0;
            break;
        }
		lnk_ind = lnk_ind->next;
	}
    return (is_sorted);
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
           if (((t_itm *)lnk_ind1->itm)->nb == ((t_itm *)(lnk_ind2)->itm)->nb)
               return (0);
	    	lnk_ind2 = lnk_ind2->next;
	    }
	    lnk_ind1 = lnk_ind1->next;
    } while (lnk_ind1 != lst);
    return (1);
}