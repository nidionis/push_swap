/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gather_min_and_max.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/17 20:42:00 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
	Find value 0, reach_push to max and dump next to max
	2 1
*/

int contains_only_higher(t_lnk *lst, int rank)
{
	t_lnk	*ind_lnk;

	ind_lnk = lst->next;
	if (lst->rank > rank)
		return (0);
	while (ind_lnk->rank > rank && ind_lnk != lst)
		ind_lnk = ind_lnk->next;
	if (ind_lnk == lst)
		return (1);
	return (0);
}

void	first_dump_relMax(t_lnk **lst_a, t_lnk **lst_b, int rank_max) 
{
	int local_relMin;
	t_lnk	*lst_b_cpy;

	local_relMin = 0;
	lst_b_cpy = (*lst_b)->prev;
	while (lst_b_cpy->prev->rank == lst_b_cpy->rank + 1)
	{
		local_relMin++;
		lst_b_cpy = lst_b_cpy->next;
	}
 	while (*lst_b)
	 {
		if ((*lst_b)->rank < (*lst_a)->prev->rank)
			while ((*lst_b)->rank < (*lst_a)->prev->rank && (*lst_b)->rank > local_relMin && contains_only_higher(*lst_a, (*lst_b)->rank));
				apply_instr(rra, lst_a, lst_b, 1);
		if ((*lst_b)->rank == local_relMin)
		{
			reach_rank(lst_a, rank_max, get_shortestway(rank_max, *lst_a));
			apply_instr(ra, lst_a, lst_b, 1);
			while ((*lst_b)->next != *lst_b)
				apply_instr(pa, lst_a, lst_b, 1);
		}
		apply_instr(pa, lst_a, lst_b, 1);
	 }
}

void	first_parse(t_lnk **lst_a, t_lnk **lst_b, int ind_max)
{
	int relMax;

	relMax = get_RelMax(*lst_a, ind_max);
	reach_rank(lst_a, 0, get_shortestway(0, *lst_a));
	apply_instr(pb, lst_a, lst_b, 1);
	reach_push(lst_a, lst_b, ind_max, 0, relMax);
	first_dump_relMax(lst_a, lst_b, ind_max);
}