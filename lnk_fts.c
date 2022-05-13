/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lnk_fts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:19:58 by supersko          #+#    #+#             */
/*   Updated: 2022/05/13 13:29:11 by supersko         ###   ########.fr       */
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
		error_msg("[lnk_init] NULL passed in params");
	return (lnk);
}

t_lnk	*ft_new_lnk(int nb, int ind, int rank)
{
	t_lnk		*lnk;
	t_itm	*lnk_itm;

	lnk = (t_lnk *) malloc(sizeof(t_lnk));
	if (!lnk)
		error_msg("Error creating a new link\n");
	lnk_itm = (t_itm *) malloc(sizeof(t_itm));
	if (!lnk_itm)
		error_msg("Error mallocing lnk_itm\n");
	lnk->itm = (void *) lnk_itm;
	((t_itm *)lnk->itm)->nb = nb;
	((t_itm *)lnk->itm)->ind = ind;
	((t_itm *)lnk->itm)->rank = rank;
	lnk_init(lnk);
	return (lnk);
}

t_lnk	*new_instr_lnk(char *instr)
{
	t_lnk		*lnk;
	t_instr		*lnk_itm;

	lnk = (t_lnk *) malloc(sizeof(t_lnk));
	if (!lnk)
		error_msg("Error creating a new link\n");
	lnk_itm = (t_instr *) malloc(sizeof(t_instr));
	if (!lnk_itm)
		error_msg("[new_instr_lnk] Error mallocing lnk_itm\n");
	lnk->itm = (void *) lnk_itm;
	ft_strlcpy(((t_instr *) lnk->itm)->instr, instr, 4);
	lnk_init(lnk);
	return (lnk);
}

void	del_lst(t_lnk **lst)
{
	t_lnk	*next_lnk;
	t_lnk	*first_lnk;

	if (*lst && (*lst)->next != *lst)
	{
		first_lnk = *lst;
		while ((*lst)->next != first_lnk)
		{
			next_lnk = (*lst)->next;
			free((*lst)->itm);
			free(*lst);
			*lst = next_lnk;
		}
	}
	free((*lst)->itm);
	free(*lst);
	*lst = NULL;
}

void	lst_init_ranks(t_lnk **lst)
{
	t_lnk	*lnk;
	t_lnk	*l_i;

	lnk = *lst;
	do
	{
		l_i = lnk;
		do
		{
			if (((t_itm *)lnk->itm)->nb > ((t_itm *)(l_i)->itm)->nb)
				(((t_itm *)lnk->itm)->rank)++;
			l_i = l_i->next;
		} while (l_i != lnk);
		lnk = lnk->next;
	} while (lnk != *lst);
}