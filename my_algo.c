/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/16 15:38:49 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

// if itm_A0 < median
void		sort_push_step(t_lnk	**lst_a, t_lnk **lst_b, int median)
{
	if (((t_itm *)(*lst_a)->itm)->rank <= median)
		apply_instr(pb, lst_a, lst_b, 1);
	else if (((t_itm *)(*lst_a)->itm)->nb > ((t_itm *)((*lst_a)->next)->itm)->nb)
	{
		if (*lst_b && *lst_a && ((t_itm *)(*lst_b)->itm)->nb < ((t_itm *)((*lst_b)->next)->itm)->nb)
			apply_instr(ss, lst_a, lst_b, 1);
		else
			apply_instr(sa, lst_a, lst_b, 1);
	}
	else
	{
		if (*lst_b && ((t_itm *)(*lst_b)->itm)->nb < ((t_itm *)((*lst_b)->next)->itm)->nb)
			apply_instr(rr, lst_a, lst_b, 1);
		else
			apply_instr(ra, lst_a, lst_b, 1);
	}
}

// lst_a median to MAX, ordre croissant
// lst_b median to min, ordre decroissant
void	sort_push(t_lnk	**lst_a, t_lnk **lst_b, int ind_max)
{
	t_lnk	*last;

	int		median;

	last = (*lst_a)->prev;
	median = ind_max / 2;
	while (*lst_a != last)
	{
		sort_push_step(lst_a, lst_b, median);
	}
	sort_push_step(lst_a, lst_b, median);
}