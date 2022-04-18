/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_init_fcts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:14:24 by supersko          #+#    #+#             */
/*   Updated: 2022/04/18 18:02:21 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_init_size(t_lst *lst)
{
	t_lnk	*lnk;
	size_t	size;

	if (lst)
	{
		lst->size = 0;
		if (lst->first)
		{
			lnk = lst->first;
			lst->size = 1;
			while (lnk->next != lst->last)
			{
				lnk = lnk->next;
				(lst->size)++;
			}
		}
	}
}

void	lst_init_indinlist(t_lst *lst)
{
	size_t		ii;
	t_lnk		*lnk;

	if (lst)
	{
		lnk = lst->last;
		ii = lst->size;
		while (--ii)
		{
			lnk->indinlist = ii;
			lnk = lnk->prev;
		}
	}
}

void	lst_init_rankinlist(t_lst *lst)
{
	int		rank;
	t_lst	*lst_sorted;
	t_lnk	*lnk;

	if (lst)
	{
		lst_sorted = new_lst();
		bubble_sort_decr_nb(lst, lst_sorted);
		rank = 0;
		lnk = lst_sorted->first;
		while (lnk->next != lst_sorted->first)
		{
			lnk->rankinlist = rank++;
			lnk = lnk->next;
		}
		bubble_sort_decr_ind(lst_sorted, lst);
		free(lst_sorted);
	}
}

void	lst_init_ranks(t_lst *lst_ini)
{
	int		rank;
	t_lnk	*lnk;
	t_lst	*lst_sorted;

	lst_sorted = new_lst();
	bubble_sort_decr_nb(lst_ini, lst_sorted);
	rank = 0;
	lnk = lst_sorted->first;
	while (rank < lst_sorted->size)
	{
		lnk->rankinlist = rank;
		lnk->rank = rank++;
		lnk = lnk->next;
	}
	bubble_sort_decr_ind(lst_sorted, lst_ini);
	free(lst_sorted);
}
