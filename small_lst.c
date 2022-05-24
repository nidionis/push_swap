/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/24 15:38:45 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int is_median(t_lnk *lst_a, int max)
{
	if (lst_a->rank != 0 && lst_a->rank != max)
		return (1);
	return (0);
}

void sort_2_nb(t_lnk **lst_a)
{
	if ((*lst_a)->rank > (*lst_a)->next->rank)
		apply_instr(sa, lst_a, NULL, 1);
}

void sort_3_nb(t_lnk **lst_a, int max)
{
	if ((*lst_a)->rank != 0)
	{
		if (is_median((*lst_a)->next, max ))// 2 1 0
		{
			apply_instr(sa, lst_a, NULL, 1);
			apply_instr(rra, lst_a, NULL, 1);
		}
		else if (is_median((*lst_a)->prev, max)) // 2 0 1
			apply_instr(ra, lst_a, NULL, 1);
		else if ((*lst_a)->prev->rank == max) // 1 0 2
			apply_instr(sa, lst_a, NULL, 1);
		else // 1 2 0
			apply_instr(rra, lst_a, NULL, 1);
	}
	else
	{
		if (!is_median((*lst_a)->next, max))
		{
			apply_instr(ra, lst_a, NULL, 1);
			apply_instr(sa, lst_a, NULL, 1);
			apply_instr(rra, lst_a, NULL, 1);
		}
	}
}

void sort_4_nb(t_lnk **lst_a, t_lnk **lst_b)
{
	int i;

	i = 0;
	while (i++ < 4)
	{
		if ((*lst_a)->rank > 1)
			apply_instr(pb, lst_a, lst_b, 1);
		else
			apply_instr(ra, lst_a, lst_b, 1);
	}
	if ((*lst_a)->rank > (*lst_a)->next->rank)
		apply_instr(sa, lst_a, lst_b, 1); 
	if ((*lst_a)->rank < (*lst_a)->next->rank)
		apply_instr(sb, lst_a, lst_b, 1); 
	apply_instr(pa, lst_a, lst_b, 1); 
	apply_instr(pa, lst_a, lst_b, 1);
}

void sort_5_nb(t_lnk **lst_a, t_lnk **lst_b)
{
	int i;

	i = 0;
	while (i++ < 5)
	{
		if ((*lst_a)->rank > 2)
			apply_instr(pb, lst_a, lst_b, 1);
		else
			apply_instr(ra, lst_a, lst_b, 1);
	}
	sort_3_nb(lst_a, 2);
	if ((*lst_b)->rank < (*lst_b)->next->rank)
		apply_instr(sb, lst_a, lst_b, 1); 
	apply_instr(pa, lst_a, lst_b, 1); 
	apply_instr(pa, lst_a, lst_b, 1);
	apply_instr(ra, lst_a, lst_b, 1);
	apply_instr(ra, lst_a, lst_b, 1);
}