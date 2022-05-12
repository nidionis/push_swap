/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_item.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:10:44 by supersko          #+#    #+#             */
/*   Updated: 2022/05/12 14:24:22 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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