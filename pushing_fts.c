/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing_fts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 21:16:34 by supersko          #+#    #+#             */
/*   Updated: 2022/05/11 16:32:11 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_lnk	*push_item(t_lnk *lnk, t_lnk **lst)
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
			*lst = lnk;
    	}
		if (!lnk)
			error_msg("[push item] pushing non existing link\n");
	}
	else
		error_msg("error at push_item\n");
	return (lnk);
}
