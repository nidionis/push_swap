/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/23 15:32:14 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	special_item(t_lnk *lst_a, int max)
{
	if (lst_a->rank == 0 || lst_a->rank == max)
		return (1);
	return (0);
}


void	fl_loop(t_lnk **lst_a, t_lnk **lst_b, int max, int indice_optimisation)
{
	if (special_item(*lst_a, max))
	{
		apply_instr(pb, lst_a, lst_b, 1);	
		apply_instr(rb, lst_a, lst_b, 1);	
	}
	else if (special_item((*lst_a)->next, max))
	{
		apply_instr(pb, lst_a, lst_b, 1);	
	}
	else
	{
		if ((*lst_a)->rank > (*lst_a)->prev->rank && (*lst_a)->rank < (*lst_a)->prev->rank + max / indice_optimisation)
			apply_instr(ra, lst_a, lst_b, 1);	
		else
			apply_instr(pb, lst_a, lst_b, 1);	
	}
}

void first_load(t_lnk **lst_a, t_lnk **lst_b, int max)
{
	int i;
	int ind_optimisation;

	i = max;
	ind_optimisation = 10;
	if (special_item(*lst_a, max) || (*lst_a)->rank > max / 2)
	{
		while (special_item(*lst_a, max) || (*lst_a)->rank > max / 2)
			apply_instr(ra, lst_a, lst_b, 1);
	}
	apply_instr(ra, lst_a, lst_b, 1);
	while (i--)
	{
		fl_loop(lst_a, lst_b, max, ind_optimisation);
	}
	//dump on min
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

void load_b(t_lnk **lst_a, t_lnk **lst_b, int max)
{
	int i;
	int ind_optimisation;

	i = max;
	ind_optimisation = 10;
	if (special_item(*lst_a, max) || (*lst_a)->rank > max / 2)
	{
		while (special_item(*lst_a, max) || (*lst_a)->rank > max / 2)
			apply_instr(ra, lst_a, lst_b, 1);
	}
	apply_instr(ra, lst_a, lst_b, 1);
	while (i--)
	{
		fl_loop(lst_a, lst_b, max, ind_optimisation);
	}
	//dump on min
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
