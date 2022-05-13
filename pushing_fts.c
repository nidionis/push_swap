/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing_fts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 21:16:34 by supersko          #+#    #+#             */
/*   Updated: 2022/05/12 18:43:11 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	push(t_lnk **from_lst, t_lnk **to_lst)
{
	push_item(pop_item(from_lst), to_lst);
}

void	push_item(t_lnk *lnk, t_lnk **lst)
{
	if (lnk)
	{
		if (*lst == NULL)
			*lst = lnk_init(lnk);
		else
    	{
    	    lnk->next = *lst;
    	    lnk->prev = (*lst)->prev;
    	    ((*lst)->prev)->next = lnk;
    	    (*lst)->prev = lnk;
			(*lst) = lnk;
    	}
		if (!lnk)
			error_msg("[push item] pushing non existing link\n");
	}
	else
		error_msg("error at push_item\n");
}

t_lnk	*pop_item(t_lnk **lst)
{
    t_lnk   *poped_item;

    poped_item = *lst;
	if (*lst == NULL)
		error_msg("[pop_item] trying to pop a NULL list\n");
    else if ((*lst)->next == *lst)
        *lst = NULL;
    else
    {
        (poped_item->prev)->next = (*lst)->next;
        (poped_item->next)->prev = (*lst)->prev;
        *lst = (*lst)->next;
    }
    return (lnk_init(poped_item));
}