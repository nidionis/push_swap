/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/24 14:49:50 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void sort_3_nb(t_lnk **lst_a)
{
	if ((*lst_a)->rank != 0)
	{
		if ((*lst_a)->next->rank == 1) // 2 1 0
		{
			apply_instr(sa, lst_a, NULL, 1);
			apply_instr(rra, lst_a, NULL, 1);
		}
		else if ((*lst_a)->prev->rank == 1) // 2 0 1
			apply_instr(ra, lst_a, NULL, 1);
		else if ((*lst_a)->prev->rank == 2) // 1 0 2
			apply_instr(sa, lst_a, NULL, 1);
		else // 1 2 0
			apply_instr(rra, lst_a, NULL, 1);
	}
	else
	{
		if ((*lst_a)->next->rank != 1)
		{
			apply_instr(ra, lst_a, NULL, 1);
			apply_instr(sa, lst_a, NULL, 1);
			apply_instr(rra, lst_a, NULL, 1);
		}
	}
}