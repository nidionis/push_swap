/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gather_min_and_max.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/19 19:10:34 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static t_lnk **first_reach_push_loop(t_lnk **lst_a, t_lnk **lst_b, int instr_way, t_lnk *rel_MinMax[2])
{
	if (!(*lst_b))
		apply_instr(pb, lst_a, lst_b, 1);
	else if (*lst_b && (*lst_a)->rank > (*lst_b)->rank)
		apply_instr(pb, lst_a, lst_b, 1);
	else if (*lst_b && (*lst_b)->next != *lst_b && (*lst_a)->rank < (*lst_b)->prev->rank)
	{
		apply_instr(pb, lst_a, lst_b, 1);
		if ((*lst_b)->next->rank > (*lst_b)->rank)
			apply_instr(rb, lst_a, lst_b, 1);
	}
	else
		apply_instr(instr_way, lst_a, lst_b, 1);
	return (rel_MinMax);
}

t_lnk	**first_reach_push(t_lnk **lst_a, t_lnk **lst_b, int rank, int instr_way, t_lnk	*relMinMax[2])
{
	if (instr_way <= 0)
	{
		instr_way = ra;
		if (get_shortestway(rank, *lst_a) < 0)
			instr_way = rra;
	}
	if ((*lst_a)->rank != rank)
	{
		while ((*lst_a)->rank != rank)
		{
			relMinMax = first_reach_push_loop(lst_a, lst_b, instr_way, relMinMax);
		}
	}
	return (relMinMax);
}

//gather min and max
t_lnk	**first_parse(t_lnk **lst_a, t_lnk **lst_b, int ind_max, t_lnk *relMinMax[2])
{
	if (*relMinMax && relMinMax[0]->rank <= relMinMax[1]->rank)
	{
		while ((*lst_a)->rank <= relMinMax[0]->rank)
			apply_instr(ra, lst_a, lst_b, 1);
		relMinMax = first_reach_push(lst_a, lst_b, ind_max, -1, relMinMax);
		apply_instr(pb, lst_a, lst_b, 1);
		reach_rank(lst_a, 0, -1);
		dump_relMax(lst_a, lst_b);
	}
	return (relMinMax);
}