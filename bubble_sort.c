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
			rotate("A", lst, NULL);
		else if (lst->size > 1)
			push("A", dest_lst, lst);
		step = 0;
	}
	if (lst->size)
		push("A", dest_lst, lst);
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

t_lst	*bubble_sort_decr_ind(t_lst *lst, t_lst *dest_lst)
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
			rotate("A", lst, NULL);
		else if (lst->size > 1)
			push("A", dest_lst, lst);
		step = 0;
	}
	if (lst->size)
		push("A", dest_lst, lst);
	return (dest_lst);
}

void bubble_loop_indlst(t_lst *lst, t_lst *dest_lst)
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

t_lst *bubble_sort_decr_indinlist(t_lst *lst, t_lst *dest_lst)
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

t_lst	*inplace_sort_incr(t_lst *lst)
{
	int		ii;
	t_lnk	*lnk_ind;

	if (lst)
	{
		lst_init_rankinlist(lst);
		lst_init_indinlist(lst);
		ii = 0;
	}
}

/*
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
*/
