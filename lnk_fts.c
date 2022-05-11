/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lnk_fts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:19:58 by supersko          #+#    #+#             */
/*   Updated: 2022/05/11 16:33:03 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_lnk	*lnk_init(t_lnk *lnk)
{
	if (lnk)
	{
		lnk->next = lnk;
		lnk->prev = lnk;
	}
	else
		lnk = NULL;
	return (lnk);
}

t_lnk	*new_lnk(int nb, int ind, int rank)
{
	t_lnk		*lnk;
	t_lnk_items	*lnk_items;

	lnk = (t_lnk *) malloc(sizeof(t_lnk));
	if (!lnk)
		error_msg("Error creating a new link\n");
	else
	{
		lnk_items = (t_lnk_items *) malloc(sizeof(t_lnk_items));
		if (!lnk_items)
			error_msg("Error mallocing lnk_items\n");
		lnk->items = lnk_items;
		(lnk->items)->nb = nb;
		(lnk->items)->ind = ind;
		(lnk->items)->rank = rank;
		lnk_init(lnk);
	}
	return (lnk);
}
