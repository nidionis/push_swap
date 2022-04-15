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

void	swap_loc(t_lnk *lnk)
{
	if (lnk && lnk->next != lnk)
	{	
		t_lnk   *second_lnk;

		second_lnk = lnk->next;
		(second_lnk->next)->prev = lnk;
		(lnk->prev)->next = second_lnk;
		lnk->next = second_lnk->next;
		second_lnk->prev = lnk->prev;
		lnk->prev = second_lnk;
		second_lnk->next = lnk;
	}
	else
		error_msg("error at swap_loc");
}

t_lst	*inplace_sort(t_lst *lst)
{
	int		ii;
	t_lnk	*lnk_ind;
	t_lnk	*lnk_end;
	t_lnk	*lnk_start;

	lst_init_rankinlist(lst);
	ii = 0;
	if ((lst->first)->rankinlist == 0)
	{
		lnk_start = lst->first;
		while (lnk_start->rankinlist == ii++)
			lnk_start = lnk_start->next;
	}
	else
		lnk_start = NULL;
	ii = lst->size - 1;
	if ((lst->last)->rankinlist == ii)
	{
		lnk_end = lst->last;
		while (lnk_end->rankinlist == ii--)
			lnk_end = lnk_end->prev;
	}
	else
		lnk_end = NULL;
	lnk_ind = lst->first;
	if (lnk_start)
		lnk_ind = lnk_start;
	else
	ii = 0;
	while (lnk_start && lnk_start != lnk_end)
	{
		if (lnk_ind->nb > (lnk_ind->next)->nb)
		{
			swap_loc(lnk_ind);
			lnk_ind = lnk_ind->prev;
			if (lnk_ind->rankinlist == lnk_start->rankinlist + 1)
				lnk_start = lnk_ind;
		}
		if (lnk_ind->next == lnk_end)
		{
			if (lnk_ind->rankinlist = lnk_end->rankinlist - 1)
				lnk_end = lnk_ind;
			lnk_ind = lnk_start->next;
		}
		lnk_ind = lnk_ind->next;
	}
}

void	lst_init_rankinlist(t_lst *lst)
{
	int		rank;
	t_lnk	*lnk;
	
	t_lst *lst_sorted;
	lst_sorted = new_lst();
	bubble_sort_decr_nb(lst, lst_sorted);
	rank = 0;
	lnk = lst_sorted->first;
	while (rank < lst_sorted->size)
	{
		lnk->rankinlist = rank;
		lnk = lnk->next;
		rank++;
	}
	bubble_sort_decr_ind(lst_sorted, lst);
	free(lst_sorted);
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

int main(int argc, char **argv)
{
	t_lst *lst_ini;

	lst_ini = get_args(argc, argv);
	print_lst(lst_ini, NULL);
	write(1, "\n", 1);
	reachSorting_up_incr(lst_ini, lst_ini->size - 1);
	write(1, "\n", 1);
	print_lst(lst_ini, NULL);
}
