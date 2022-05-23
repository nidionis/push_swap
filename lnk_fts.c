/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lnk_fts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:19:58 by supersko          #+#    #+#             */
/*   Updated: 2022/05/23 18:18:32 by supersko         ###   ########.fr       */
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

	lnk = (t_lnk *) malloc(sizeof(t_lnk));
	if (!lnk)
		error_msg("Error creating a new link\n");
	lnk->nb = nb;
	lnk->ind = ind;
	lnk->rank = rank;
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
			free(*lst);
			*lst = next_lnk;
		}
	}
	if (*lst)
	{
		free(*lst);
		*lst = NULL;
	}
}

// return ind max
int	lst_init_ranks(t_lnk **lst)
{
	t_lnk	*lnk;
	t_lnk	*l_i;
	int		max;

	lnk = *lst;
	max = 0;
	do
	{
		l_i = lnk;
		do
		{
			if (lnk->nb > l_i->nb)
			{
				(lnk->rank)++;
				if (max < lnk->rank)
					max = lnk->rank;
			}
			l_i = l_i->next;
		} while (l_i != lnk);
		lnk = lnk->next;
	} while (lnk != *lst);
	return (max);
}