/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reach_and_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:52:02 by supersko          #+#    #+#             */
/*   Updated: 2022/05/15 22:29:05 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*reachsorting_rev_decr(t_lst *lst, int rank_inlst)
{
	if (lst && lst->size > 1 && rank_inlst < lst->size)
	{
		if ((lst->first)->rankinlist == ((lst->first)->next)->rankinlist)
			error_msg("rankinlist not initialized for reachsorting_rev_decr\n");
		while ((lst->first)->rankinlist != rank_inlst)
		{
			if ((lst->first)->rankinlist > ((lst->first)->next)->rankinlist)
				swap("A", lst, NULL);
			if ((lst->first)->rankinlist != rank_inlst)
				rotate("RA", lst, NULL);
		}
	}
	return (lst);
}

t_lst	*reachsorting_rev_incr(t_lst *lst, int rank_inlst)
{
	if (lst && lst->size > 1 && rank_inlst < lst->size)
	{
		if ((lst->first)->rankinlist == ((lst->first)->next)->rankinlist)
			error_msg("rankinlist not initialized for reachsorting_rev_incr\n");
		while ((lst->first)->rankinlist != rank_inlst)
		{
			if ((lst->first)->rankinlist < ((lst->first)->next)->rankinlist)
				swap("A", lst, NULL);
			if ((lst->first)->rankinlist != rank_inlst)
				rotate("RA", lst, NULL);
		}
	}
	return (lst);
}

t_lst	*reachsorting_incr(t_lst *lst, int rank_inlst)
{
	if (lst && lst->size > 1 && rank_inlst < lst->size)
	{
		if ((lst->first)->rankinlist == ((lst->first)->next)->rankinlist)
			error_msg("rankinlist not initialized for reachsorting_incr\n");
		while ((lst->first)->rankinlist != rank_inlst)
		{
			if ((lst->first)->rankinlist < ((lst->first)->next)->rankinlist)
				swap("A", lst, NULL);
			if ((lst->first)->rankinlist != rank_inlst)
				rotate("A", lst, NULL);
		}
	}
	return (lst);
}

t_lst	*reachsorting_decr(t_lst *lst, int rank_inlst)
{
	if (lst && lst->size > 1 && rank_inlst < lst->size)
	{
		if ((lst->first)->rankinlist == ((lst->first)->next)->rankinlist)
			error_msg("rankinlist not initialized for reachsorting_decr\n");
		while ((lst->first)->rankinlist != rank_inlst)
		{
			if ((lst->first)->rankinlist > ((lst->first)->next)->rankinlist)
				swap("A", lst, NULL);
			if ((lst->first)->rankinlist != rank_inlst)
				rotate("A", lst, NULL);
		}
	}
	return (lst);
}

void	reachandsort(t_lst *lst, int rank_inlst, int ordre_croissant)
{
	if (lst && rank_inlst < lst->size)
	{
		if (ordre_croissant)
		{
			if (rank_inlst > (lst->size / 2))
				reachsorting_rev_incr(lst, rank_inlst);
			else
				reachsorting_incr(lst, rank_inlst);
		}
		else
		{
			if (rank_inlst > (lst->size / 2))
				reachsorting_rev_decr(lst, rank_inlst);
			else
				reachsorting_decr(lst, rank_inlst);
		}
	}
}
/*
t_lst *bubbleReachandsort(t_lst *lst, int rank_inlst, int ordre_croissant)
{
	if (lst && lst->size > 1 && rank_inlst < lst->size)
	{
	}
}
*/

/*
int	main(int argc, char **argv)
{
	t_lst	*lst;
	t_lst	*tmp;
	t_lnk	*lnk;

	lst = get_args(argc, argv);
	tmp = malloc(sizeof(t_lst));
	print_lst(lst, tmp);
	push("A", tmp, lst);
	print_lst(lst, tmp);
	swap("A", lst, NULL);
	print_lst(lst, tmp);
	push("B", tmp, lst);
	print_lst(lst, tmp);
	rotate("RA", lst, NULL);
	print_lst(lst, tmp);
	//printf("rankInlst %d, ind %d\n", 1, get_ind_from_rank_inlist(lst, 1));
*/
/*
	printf("going to the min value, decroissant:\n", lst->min_val);
	reachandsort(lst, 0, 0);
	print_lst(lst, NULL);
	printf("going to the max value, croissant:\n", lst->max_val);
	reachandsort(lst, lst->size - 1, 1);
	print_lst(lst, NULL);
	printf("going to the min value, croissant:\n", lst->min_val);
	reachandsort(lst, 0, 1);
	print_lst(lst, NULL);
	printf("going to the max value, decroissant:\n", lst->max_val);
	reachandsort(lst, lst->size - 1, 0);
	print_lst(lst, NULL);
	del_list(tmp);
}
	*/
