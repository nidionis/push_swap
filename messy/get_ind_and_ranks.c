/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ind_and_ranks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:59:57 by supersko          #+#    #+#             */
/*   Updated: 2022/04/18 18:06:52 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_ind_from_rank(t_lst *lst, int rank)
{
	t_lnk	*lnk;

	if (lst && rank < lst->size)
	{
		lnk = lst->first;
		while (lnk->rank != rank && lnk->next != lst->first)
			lnk = lnk->next;
	}
	return (lnk->ind);
}

//
//t_lst	*lst_init_indinlist(t_lst *lst)
//{
//	t_lnk	*lnk;
//	int		ii;
//
//	if (lst)
//	{
//		ii = 0;
//		lnk = lst->first;
//		while (ii < lst->size)
//		{
//			lnk->indinlist = ii++;
//			lnk = lnk->next;
//		}
//		return (lst);
//	}
//}

int	get_ind_from_rank_inlist(t_lst *lst, int rank_inlst)
{
	t_lnk	*lnk;

	if (lst && rank_inlst < lst->size)
	{
		lnk = lst->first;
		if (lnk->rankinlist == (lnk->next)->rankinlist)
		{
			printf("get_ind_from_rank] before lst_init_rankinLst");
			lst_init_rankinlist(lst);
			printf("get_ind_from_rank] after lst_init_rankinLst");
		}
		if (lnk->indinlist == (lnk->next)->indinlist)
		{
			printf("get_ind_from_rank] before lst_init_indinlist");
			lst_init_indinlist(lst);
			printf("get_ind_from_rank] after lst_init_indinlist");
		}
		while (lnk->rankinlist != rank_inlst && lnk->next != lst->first)
			lnk = lnk->next;
	}
	else
		error_msg("[In get_ind_from_rank_inlist]: weird parameter\n");
	return (lnk->indinlist);
}
