/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:47:40 by supersko          #+#    #+#             */
/*   Updated: 2022/04/08 13:48:06 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 
#include "push_swap.h"

void bubble_loop_nb(t_lst *lst, t_lst *dest_lst)
{
	if (lst->size && (lst->last)->nb == lst->max_val)
			rotate("ra", lst, NULL);
	if (lst->size && (lst->first)->nb == lst->max_val)
		while (lst->first && (lst->first)->nb == lst->max_val)
			push("a", dest_lst, lst);
	if (lst->size && (lst->first)->nb > ((lst->first)->next)->nb)
		swap("a", lst, NULL);
	if (lst->size > 1)
		rotate("a", lst, NULL);
}

t_lst *bubble_sort_decr_nb(t_lst *lst, t_lst *dest_lst)
{
	int		step;

	step = 0;
	while (lst->size > 1)
	{
		while (step + 2 < lst->size)
		{
			bubble_loop_nb(lst,  dest_lst);
			step++;
		}
		if (lst->size > 1 && (lst->first)->nb != lst->max_val)
			rotate("a", lst, NULL);
		else if (lst->size > 1)
			push("a", dest_lst, lst);
		step = 0;
	}
	if (lst->size)
		push("a", dest_lst, lst);
	return (dest_lst);
}


void bubble_loop_ind(t_lst *lst, t_lst *dest_lst)
{
	if (lst->size && (lst->last)->ind == lst->size - 1)
			rotate("ra", lst, NULL);
	if (lst->size && (lst->first)->ind == lst->size - 1)
		while (lst->first && (lst->first)->ind == lst->size - 1)
			push("a", dest_lst, lst);
	if (lst->size && (lst->first)->ind > ((lst->first)->next)->ind)
		swap("a", lst, NULL);
	if (lst->size > 1)
		rotate("a", lst, NULL);
}

t_lst *bubble_sort_decr_ind(t_lst *lst, t_lst *dest_lst)
{
	int		step;

	step = 0;
	while (lst->size > 1)
	{
		while (step + 2 < lst->size)
		{
			bubble_loop_ind(lst,  dest_lst);
			step++;
		}
		if (lst->size > 1 && (lst->first)->ind != lst->size - 1)
			rotate("a", lst, NULL);
		else if (lst->size > 1)
			push("a", dest_lst, lst);
		step = 0;
	}
	if (lst->size)
		push("a", dest_lst, lst);
	return (dest_lst);
}

void	lst_init_rank(t_lst *lst_ini)
{
	int		rank;
	t_lnk	*lnk;
	
	t_lst *lst_sorted;
	lst_sorted = new_lst();
	bubble_sort_decr_nb(lst_ini, lst_sorted);
	rank = 0;
	lnk = lst_sorted->first;
	while (rank < lst_sorted->size)
	{
		lnk->rank = rank;
		lnk = lnk->next;
		rank++;
	}
	bubble_sort_decr_ind(lst_sorted, lst_ini);
	free(lst_sorted);
}
