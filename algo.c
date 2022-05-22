/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/22 19:42:41 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>


void	shortestway_fucking_norminette(t_lnk **lst, int *step_nb, int *found, int *rank)
{
	if (!(*found))
		(*step_nb)++;
	if ((*lst)->rank == *rank)
		*found = 1;
	*lst = (*lst)->next;
}

int	get_dir(int rank, t_lnk *lst)
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
		return (rra);
	return (ra);
}

int to_zero(t_lnk **lst_a, t_lnk **lst_b, int ind_max, int dir)
{
	int max_loaded;

	max_loaded = 0;
	while ((*lst_a)->rank != 0)
	{
		if ((*lst_a)->rank == ind_max)
		{
			apply_instr(pb, lst_a, lst_b, 1);
			apply_instr(rb, lst_a, lst_b, 1);
			max_loaded = 1;
		}
		if ((*lst_a)->rank < (*lst_a)->next->rank)
			apply_instr(dir, lst_a, lst_b, 1);
		else
			apply_instr(pb, lst_a, lst_b, 1);
	}
	return (max_loaded);
}

void	first_load_loop(t_lnk **lst_a, t_lnk **lst_b, int ind_max)
{
	if (*lst_a)
	{
		if ((*lst_a)->rank == 0 || (*lst_a)->rank == ind_max)
		{
			apply_instr(pb, lst_a, lst_b, 1);
			apply_instr(rb, lst_a, lst_b, 1);
		}
		else
		{
			if ((*lst_a)->rank > (*lst_a)->prev->rank)
				apply_instr(ra, lst_a, lst_b, 1);
			else
				apply_instr(pb, lst_a, lst_b, 1);
		}
	}
}

void first_load(t_lnk **lst_a, t_lnk **lst_b, int ind_max)
{
	int i;

	i = ind_max;
	if ((*lst_a)->rank == 0 || (*lst_a)->rank == ind_max || (*lst_a)->next->rank > ind_max / 2)
		while ((*lst_a)->rank == 0 || (*lst_a)->rank == ind_max || (*lst_a)->next->rank > ind_max / 2)
			apply_instr(ra, lst_a, lst_b, 1);
	while (i--)
	{
		first_load_loop(lst_a, lst_b, ind_max);
	}
		first_load_loop(lst_a, lst_b, ind_max);
		first_load_loop(lst_a, lst_b, ind_max);
		apply_instr(rrb, lst_a, lst_b, 1);
		if ((*lst_b)->rank == 0)
		{
			apply_instr(pa, lst_a, lst_b, 1);
			apply_instr(rrb, lst_a, lst_b, 1);
			apply_instr(pa, lst_a, lst_b, 1);
		}
		else
		{
			apply_instr(rrb, lst_a, lst_b, 1);
			apply_instr(pa, lst_a, lst_b, 1);
			apply_instr(pa, lst_a, lst_b, 1);
		}
}