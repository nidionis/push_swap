/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing_fts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 21:16:34 by supersko          #+#    #+#             */
/*   Updated: 2022/05/10 21:27:51 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_lnk	*push_item(t_lnk *lnk, t_lst *lst)
{
	if (lst && lnk)
	{
		if ((lst->items)->size == 0)
		{
			lst->first = lnk;
			lst->last = lnk;
		}
		else
			refresh_lnks_push(lnk, lst);
		(lst->size)++;
		if ((lst->items)->min_val > (lnk->items)->nb)
			(lst->items)->min_val = (lnk->items)->nb;
		if ((lst->items)->max_val < (lnk->items)ft_->nb)
			(lst->items)->max_val = (lnk->items)->nb;
		refresh_afterpush_inlist(lst, lnk);
		if (!lnk)
			error_msg("pushing non existing link\n");
	}
	else
		error_msg("error at push_item\n");
	return (lnk);
}
