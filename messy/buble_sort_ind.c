/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buble_sort_ind.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:04:14 by supersko          #+#    #+#             */
/*   Updated: 2022/04/18 15:04:58 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_loop_ind(t_lst *lst, t_lst *dest_lst)
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

t_lst	*bubble_sort_decr_ind(t_lst *lst, t_lst *dest_lst)
{
	int	step;

	step = 0;
	while (lst->size > 1)
	{
		while (step + 2 < lst->size)
		{
			bubble_loop_ind(lst, dest_lst);
			step++;
		}
		if (lst->size > 1 && (lst->first)->ind != lst->size - 1)
			rotate("A", lst, NULL);
		else if (lst->size > 1)
			push("A", dest_lst, lst);
		step = 0;
	}
	if (lst->size)
		push("A", dest_lst, lst);
	return (dest_lst);
}

void	bubble_loop_indinlst(t_lst *lst, t_lst *dest_lst)
{
	if (lst->size && (lst->last)->indinlist == lst->size - 1)
		rotate("ra", lst, NULL);
	if (lst->size && (lst->first)->indinlist == lst->size - 1)
		while (lst->first && (lst->first)->indinlist == lst->size - 1)
			push("a", dest_lst, lst);
	if (lst->size && (lst->first)->indinlist > ((lst->first)->next)->indinlist)
		swap("a", lst, NULL);
	if (lst->size > 1)
		rotate("a", lst, NULL);
}

t_lst	*bubble_sort_decr_indinlist(t_lst *lst, t_lst *dest_lst)
{
	int		step;

	step = 0;
	while (lst->size > 1)
	{
		while (step + 2 < lst->size)
		{
			bubble_loop_ind(lst, dest_lst);
			step++;
		}
		if (lst->size > 1 && (lst->first)->indinlist != lst->size - 1)
			rotate("a", lst, NULL);
		else if (lst->size > 1)
			push("a", dest_lst, lst);
		step = 0;
	}
	if (lst->size)
		push("a", dest_lst, lst);
	return (dest_lst);
}
