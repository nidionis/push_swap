/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sucks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/18 14:46:25 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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