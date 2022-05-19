/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reach_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:47:40 by supersko          #+#    #+#             */
/*   Updated: 2022/05/19 18:31:20 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static t_lnk **reach_push_loop(t_lnk **lst_a, t_lnk **lst_b, int instr_way, t_lnk *rel_MinMax[2])
{
	if ((*lst_a)->rank > rel_MinMax[0]->rank && (*lst_a)->rank < rel_MinMax[1]->rank)
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
	}
	if ((*lst_a)->rank <= rel_MinMax[0]->rank || (*lst_a)->rank >= rel_MinMax[1]->rank)
		rel_MinMax = recentrer(lst_a, rel_MinMax);
	return (rel_MinMax);
}

t_lnk	**reach_push(t_lnk **lst_a, t_lnk **lst_b, int rank, int instr_way, t_lnk	*relMinMax[2])
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
			relMinMax = reach_push_loop(lst_a, lst_b, instr_way, relMinMax);
		}
	}
	return (relMinMax);
}

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
