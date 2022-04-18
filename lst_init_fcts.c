/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_init_fcts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:14:24 by supersko          #+#    #+#             */
/*   Updated: 2022/04/18 20:04:32 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*new_lst(void)
{
	t_lst	*lst;

	lst = (t_lst *) malloc(sizeof(t_lst));
	lst_init(lst);
	return (lst);
}

void	lst_init(t_lst *lst)
{
	lst->first = NULL;
	lst->last = NULL;
	lst->min_val = INT_MAX;
	lst->max_val = INT_MIN;
	lst->size = 0;
}

void	del_list(t_lst *lst)
{
	t_lnk	*lnk;

	while (lst->size > 0)
	{
		lnk = pop(lst);
		free(lnk);
	}
	free(lst);
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
