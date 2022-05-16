/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_next_prev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/16 12:27:00 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void    cpy_p_to_initp(t_lnk *lnk)
{
	lnk->init_next = lnk->next;
	lnk->init_prev = lnk->prev;
}

void	set_initial_pointers(t_lnk **lst)
{
	t_lnk	*lnk;

	if (*lst)
	{
		cpy_p_to_initp(*lst);
		lnk = (*lst)->next;
		while (*lst != lnk)
		{
			cpy_p_to_initp(lnk);
			lnk = lnk->next;
		}
	}
}

void    cpy_initp_to_p(t_lnk *lnk)
{
	lnk->next = lnk->init_next;
	lnk->prev = lnk->init_prev;
}

void	reset_initial_pointers(t_lnk **lst_a)
{
	t_lnk	*lnk;

	if (*lst_a)
	{
		cpy_initp_to_p(*lst_a);
		lnk = (*lst_a)->next;
		while (*lst_a != lnk)
		{
			cpy_initp_to_p(lnk);
			lnk = lnk->next;
		}
	} 
}