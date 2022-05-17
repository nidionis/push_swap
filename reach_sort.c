/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reach_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:47:40 by supersko          #+#    #+#             */
/*   Updated: 2022/05/17 13:30:54 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 
#include "push_swap.h"

/*
void	reachsort_step(t_lnk **lst, int ascend, int way, char lst_name)
{
	if (ascend < 0 && (*lst)->nb < ((*lst)->next)->nb && ft_printf("s%c\n", lst_name))
		apply_instr(sa, lst, NULL, 0);
	else if (ascend > -1 && (*lst)->nb > ((*lst)->next)->nb && ft_printf("s%c\n", lst_name))
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
*/

void	shortestway_fucking_norminette(t_lnk **lst, int *step_nb, int *found, int *rank)
{
	if (!(*found))
		(*step_nb)++;
	if ((*lst)->rank == *rank)
		*found = 1;
	*lst = (*lst)->next;
}

// renvoit un negatif si le chemin le plus court est en reverse
int	get_shortestway(int rank, t_lnk *lst)
{
	int		step_nb;
	int		len;
	t_lnk	*last_lnk;
	int found;

	if (!lst)
		error_msg("[get_shortestway] empty list passed");
	step_nb = 0;
	len = 1;
	last_lnk = lst;
	found = 0;

	if (lst->rank == rank)
		return (0);
	lst = lst->next;
	while (lst != last_lnk && len++)
		shortestway_fucking_norminette(&lst, &step_nb, &found, &rank);
	if (!found)
		error_msg("[get_shortestway] rank not found");
	if (step_nb > len / 2)
		return (step_nb - len);
	return (step_nb);
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
