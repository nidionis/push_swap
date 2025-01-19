/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_dump.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/01/20 00:19:54 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
void	init_best_comb(int *best_comb, int *itm_insert_result, t_lnk *lst_a, t_lnk *lst_b)
{
	if (!best_comb)
		ft_errmsg("[init_best_comb] did not malloc");
	itm_insert_result = itm_insert(lst_a, lst_b);
	best_comb[0] = 0;
	best_comb[1] = 0;
	best_comb[2] = itm_insert_result[0];
	best_comb[3] = itm_insert_result[1];
	free(itm_insert_result);
}

int	*best_insert(t_lnk *lst_a, t_lnk *lst_b, int *best_comb)
{
	int	*itm_insert_result;
	int	instr;

	itm_insert_result = NULL;
	init_best_comb(best_comb, itm_insert_result, lst_a, lst_b);
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
		if (TRUE)//!can_push_a(*lst_a, *lst_b))
		{
			best_comb = best_insert(*lst_a, *lst_b, best_comb);
			while (nb_instruction(&best_comb, FIRST_INSTR))
				apply_instr(best_comb[NB_FIRST_INSTR], lst_a, lst_b, PRINT);
			while (nb_instruction(&best_comb, SECOND_INSTR))
				apply_instr(best_comb[NB_SECOND_INSTR], lst_a, lst_b, PRINT);
		}
		apply_instr(pa, lst_a, lst_b, 1);
	}
}
*/