/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sucks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/17 19:31:52 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

// reach rank 0 
int	get_RelMax(t_lnk *lst, int rankMax)
{
	t_lnk	*first_lnk;

	if (!lst || rankMax < 1)
		return (0);
	first_lnk = lst;
	if (lst->rank != rankMax)
	{
		lst = lst->next;
		while (lst->rank != rankMax && lst != first_lnk)
			lst = lst->next;
	}
	while (lst->rank == (lst->prev)->rank + 1)
		lst = lst->prev;
	return (lst->rank);
}

int	get_RelMin(t_lnk *lst)
{
	t_lnk	*first_lnk;

	if (!lst)
		return (0);
	first_lnk = lst;
	if (lst->rank != 0)
	{
		lst = lst->next;
		while (lst->rank != 0 && lst != first_lnk)
			lst = lst->next;
	}
	while (lst->rank == (lst->next)->rank - 1)
		lst = lst->next;
	return (lst->rank);
}

void	reach_rank(t_lnk **lst, int rank, int direction)
{
	t_lnk	*first_lnk;
	int		instr;

	instr = ra;
	if (direction < 0)
		instr = rra;
	first_lnk = *lst;
	if (first_lnk->rank != rank)
	{
		apply_instr(instr, lst, NULL, 1);
		while ((*lst)->rank != rank && *lst != first_lnk)
			apply_instr(instr, lst, NULL, 1);
	}
}

int		push_return_rank(t_lnk **lst_a, t_lnk **lst_b)
{
	apply_instr(pb, lst_a, lst_b, 1);	
	return ((*lst_b)->rank);
}

void	reach_push(t_lnk **lst_a, t_lnk **lst_b, int rank, int relMin, int relMax)
{
	int		instr;

	instr = ra;
	if (get_shortestway(rank, *lst_a) < 0)
		instr = rra;
	if ((*lst_a)->rank != rank)
	{
		if ((*lst_a)->rank > relMin)
			while ((*lst_a)->rank > relMin && (*lst_a)->rank < relMax)
				relMin = push_return_rank(lst_a, lst_b);
		apply_instr(instr, lst_a, NULL, 1);
		while ((*lst_a)->rank != rank)
		{
			if ((*lst_a)->rank > relMin)
				while ((*lst_a)->rank > relMin && (*lst_a)->rank < relMax)
					relMin = push_return_rank(lst_a, lst_b);
			apply_instr(instr, lst_a, NULL, 1);
		}
	}
}

void	dump_relMax(t_lnk **lst_a, t_lnk **lst_b) 
{
	print_lst_byrank(*lst_a, "A Before Dump");
	print_lst_byrank(*lst_b, "B Before Dump");
 	while (*lst_b)
	 {
		if ((*lst_b)->rank < (*lst_a)->prev->rank)
			while ((*lst_b)->rank < (*lst_a)->prev->rank)
				apply_instr(rra, lst_a, lst_b, 1);
		apply_instr(pa, lst_a, lst_b, 1);
	 }
}

void	dump_relMin(t_lnk **lst_a, t_lnk **lst_b) 
{
 	while (*lst_b)
	 {
		if ((*lst_b)->rank > (*lst_a)->next->rank)
			while ((*lst_b)->rank > (*lst_a)->next->rank)
				apply_instr(ra, lst_a, lst_b, 1);
		apply_instr(pa, lst_a, lst_b, 1);
	 }
}