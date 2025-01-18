/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_dump.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/01/18 23:50:46 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	*best_insert_in_dir(t_lnk *lst_a, t_lnk *lst_b, int *best_comb, int dir)
{
	int	*itm_insert_result;
	int	instr;
	int triquy;

	if (!best_comb)
		error_msg("[best_instert] did not malloc");
	itm_insert_result = itm_insert(lst_a, lst_b);
	best_comb[0] = 0;
	best_comb[1] = 0;
	best_comb[2] = itm_insert_result[0];
	best_comb[3] = itm_insert_result[1];
	free(itm_insert_result);
	instr = ra;
	triquy = MODULO_GIVING_REVERSE_ROTATE_INSTRUCTIONS;
	if (dir == ROTATE)
		triquy = MODULO_GIVING_ROTATE_INSTRUCTIONS;
	while (instr <= rrr)
		if (triquy % 2 == MODULO_GIVING_ROTATE_INSTRUCTIONS)
			refresh_in_dir(lst_a, lst_b, instr++, best_comb);
	return (best_comb);
}
int	*best_insert(t_lnk *lst_a, t_lnk *lst_b, int *best_comb)
{
	int	*itm_insert_result;
	int	instr;

	if (!best_comb)
		error_msg("[best_instert] did not malloc");
	itm_insert_result = itm_insert(lst_a, lst_b);
	best_comb[0] = 0;
	best_comb[1] = 0;
	best_comb[2] = itm_insert_result[0];
	best_comb[3] = itm_insert_result[1];
	free(itm_insert_result);
	instr = ra;
	while (instr <= rrr)
		refresh_in_dir(lst_a, lst_b, instr++, best_comb);
	return (best_comb);
}

int	nb_instruction(int **b, int INSTR)
{
	return ((*b)[INSTR]--);
}

void	b_dump(t_lnk **lst_a, t_lnk **lst_b)
{
	int	b[4];
	int	*best_comb;

	best_comb = b;
	while (*lst_b)
	{
		if (!can_push(*lst_a, *lst_b))
		{
			best_comb = best_insert(*lst_a, *lst_b, best_comb);
			best_comb = use_double_rotate(*lst_a, *lst_b, best_comb);
			while (nb_instruction(&best_comb, FIRST_INSTR))
				apply_instr(best_comb[NB_FIRST_INSTR], lst_a, lst_b, PRINT);
			while (nb_instruction(&best_comb, SECOND_INSTR))
				apply_instr(best_comb[NB_SECOND_INSTR], lst_a, lst_b, PRINT);
		}
		apply_instr(pa, lst_a, lst_b, 1);
	}
}
