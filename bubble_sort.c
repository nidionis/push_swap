/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:47:40 by supersko          #+#    #+#             */
/*   Updated: 2022/05/16 22:15:27 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 
#include "push_swap.h"


void	reachsort_step(t_lnk **lst, int ascend, int way, char lst_name)
{
	if (ascend < 0 && ((t_itm *)(*lst)->itm)->nb < ((t_itm *)((*lst)->next)->itm)->nb && ft_printf("s%c\n", lst_name))
		apply_instr(sa, lst, NULL, 0);
	else if (ascend > -1 && ((t_itm *)(*lst)->itm)->nb > ((t_itm *)((*lst)->next)->itm)->nb && ft_printf("s%c\n", lst_name))
		apply_instr(sa, lst, NULL, 0);
	else if ((*lst)->next != (*lst)->prev)
	{
		if (way < 0 && ft_printf("rr%c\n", lst_name))
			apply_instr(rra, lst, NULL, 0);
		else
		{
			apply_instr(ra, lst, NULL, 0);
			ft_printf("r%c\n", lst_name);
		}
	}
}

// renvoit un negatif si le chemin le plus court est en reverse
int	get_bestway(int rank, t_lnk *lst)
{
	int		step_nb;
	int		len;
	t_lnk	*last_lnk;
	int found;

	if (lst)
	{
		step_nb = 1;
		len = 2;
		last_lnk = lst;
		found = 0;
		if (((t_itm *)lst->itm)->rank == rank)
			return (1);
		lst = lst->next;
		while (rank && lst != last_lnk)
		{
			if (!found)
				step_nb++;
			len++;
			if (((t_itm *)lst->itm)->rank == rank)
				found = 1;
			lst = lst->next;
		}
		if (!found)
			error_msg("[get_bestway] rank not found");
		return ((len + 1) / 2 - step_nb);
	}
	error_msg("[get_bestway] empty list passed");
	return (-1);
}



/*
void	bubble_loop_nb(t_lst *lst, t_lst *dest_lst)
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

t_lst	*bubble_sort_decr_nb(t_lst *lst, t_lst *dest_lst)
{
	int		step;

	step = 0;
	while (lst->size > 1)
	{
		while (step + 2 < lst->size)
		{
			bubble_loop_nb(lst, dest_lst);
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

void	swap_loc(t_lnk *lnk)
{
	t_lnk	*second_lnk;

	if (lnk && lnk->next != lnk)
	{	
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
*/

/*
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
*/

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
