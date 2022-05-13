/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifications.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/13 16:53:34 by supersko         ###   ########.fr       */
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