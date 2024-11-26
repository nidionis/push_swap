/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_dump.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2024/11/26 14:53:18 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	*best_insert(t_lnk *lst_a, t_lnk *lst_b, int *best_inst_step)
{
	int	*itm_insert_result;
	int	instr;

	if (!best_inst_step)
		error_msg("[best_instert] did not malloc");
	itm_insert_result = itm_insert(lst_a, lst_b);
	best_inst_step[0] = 0;
	best_inst_step[1] = 0;
	best_inst_step[2] = itm_insert_result[0];
	best_inst_step[3] = itm_insert_result[1];
	free(itm_insert_result);
	instr = ra;
	while (instr <= rrr)
	{
		refresh_in_dir(lst_a, lst_b, instr++, best_inst_step);
	}
	return (best_inst_step);
}

void	b_dump(t_lnk **lst_a, t_lnk **lst_b)
{
	int	b[4];
	int	*best_inst_step;

	best_inst_step = b;
	while (*lst_b)
	{
		if (!can_push(*lst_a, *lst_b))
		{
			best_inst_step = best_insert(*lst_a, *lst_b, best_inst_step);
			while (best_inst_step[1]--)
				apply_instr(best_inst_step[0], lst_a, lst_b, 1);
			while (best_inst_step[3]--)
				apply_instr(best_inst_step[2], lst_a, lst_b, 1);
		}
		apply_instr(pa, lst_a, lst_b, 1);
	}
}
