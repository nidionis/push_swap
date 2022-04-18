/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:10:49 by supersko          #+#    #+#             */
/*   Updated: 2022/04/18 19:30:02 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//void	refresh_indinlist_poped(t_lst *lst, t_lnk *moved_item)
//{
//	t_lnk	*lnk;
//
//	lnk = lst->first;
//	while (lnk->next != lst->first)
//	{
//		if (lnk->indinlist > moved_item->indinlist)
//			lnk->indinlist -= 1;
//		lnk = lnk->next;
//	}
//}
//
//void	refresh_rankinlist_poped(t_lst *lst, t_lnk *moved_item)
//{
//	t_lnk	*lnk;
//
//	lnk = lst->first;
//	while (lnk->next != lst->first)
//	{
//		if (lnk->rankinlist > moved_item->rankinlist)
//			lnk->rankinlist -= 1;
//		lnk = lnk->next;
//	}
//}

void	refresh_afterpop_inlist(t_lst *lst, t_lnk *moved_item)
{
	t_lnk	*lnk;

	lnk = lst->first;
	if (lnk)
		while (lnk->next != lst->first)
		{
			if (lnk->rankinlist > moved_item->rankinlist)
				lnk->rankinlist -= 1;
			if (lnk->indinlist > moved_item->indinlist)
				lnk->indinlist -= 1;
			lnk = lnk->next;
		}
}

void	refresh_afterpush_inlist(t_lst *lst, t_lnk *moved_item)
{
	t_lnk	*lnk;

	lnk = lst->first;
	lnk->indinlist = 0;
	lnk->rankinlist = 0;
	while (lnk->next != lst->first)
	{
		if (lnk->nb > moved_item->nb)
		{
			if (moved_item->rankinlist <= lnk->rankinlist &&
					moved_item->nb > lnk->nb)
				moved_item->rankinlist = lnk->rankinlist;
			if (lnk->nb > moved_item->nb)
			lnk->rankinlist += 1;
		}
		lnk = lnk->next;
		lnk->indinlist += 1;
	}
}

//void	refresh_indinlist_pushed(t_lst *lst, t_lnk *moved_item)
//{
//	t_lnk	*lnk;
//
//	lnk = lst->first;
//	lnk->indinlist = 0;
//	while (lnk->next != lst->first)
//	{
//		lnk = lnk->next;
//		lnk->indinlist += 1;
//	}
//	if (moved_item == lst->first)
//		lnk->indinlist = 0;
//	else
//		error_msg(
//			"[refresh_indinlist] error refreshing rank after a push");
//}
//
//void	refresh_rankinlist_pushed(t_lst *lst, t_lnk *moved_item)
//{
//	t_lnk	*lnk;
//
//	lnk = lst->first;
//	while (lnk->next != lst->first)
//	{
//		if (lnk->nb > moved_item->nb)
//		{
//			if (moved_item->rankinlist > lnk->rankinlist)
//				moved_item->rankinlist = lnk->rankinlist;
//			lnk->rankinlist += 1;
//		}
//		lnk = lnk->next;
//	}
//}
