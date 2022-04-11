/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_fts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:38:32 by supersko          #+#    #+#             */
/*   Updated: 2022/04/09 22:03:05 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lnk	*lnk_init(t_lnk *lnk)
{
	lnk->next = lnk;
	lnk->prev = lnk;
	return (lnk);
}

t_lnk	*new_lnk(int nb, int ind, int rank)
{
	t_lnk	*lnk;

	lnk = malloc(sizeof(t_lnk));
	if (!lnk)
                error_msg("Error creating a new link\n");
	else
	{
		lnk->nb = nb;
		lnk->ind = ind;
		lnk->rank = rank;
		lnk_init(lnk);
	}
	return (lnk);
}

t_lst   *new_lst(void)
{
    t_lst   *lst;

    lst = malloc(sizeof(t_lst));
    lst->first = NULL;
    lst->last = NULL;
    lst->size = 0;
    return (lst);
}

void   lst_init(t_lst *lst)
{
    lst->first = NULL;
    lst->last = NULL;
    lst->size = 0;
}

void    *del_list(t_lst *lst)
{
    t_lnk   *lnk;
    while (lst->size > 0)
    {
    	lnk = pop(lst);
        free(lnk);
    }
    free(lst);
}
