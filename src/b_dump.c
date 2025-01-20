/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_dump.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/01/20 12:31:47 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	init_best_comb(int *best_comb, int *itm_insert_result, t_lnk *lst_a, t_lnk *lst_b)
{
	if (!best_comb)
		ft_errmsg("[init_best_comb] did not malloc");
	itm_insert_result = itm_insert(lst_a, lst_b);
	best_comb[NB_FIRST_INSTR] = 0;
	best_comb[FIRST_INSTR] = ROTATE_MIN;
	best_comb[NB_SECOND_INSTR] = itm_insert_result[NB_FIRST_INSTR];
	best_comb[SECOND_INSTR] = itm_insert_result[FIRST_INSTR];
	free(itm_insert_result);
}

int	*best_insert(t_lnk *lst_a, t_lnk *lst_b, int *best_comb)
{
	int	*itm_insert_result;
	int	instr;

	itm_insert_result = NULL;
	init_best_comb(best_comb, itm_insert_result, lst_a, lst_b);
	instr = ROTATE_MIN;
	while (instr <= ROTATE_MAX)
	{
		if (is_rotate_instr(instr))
			refresh_in_dir(lst_a, lst_b, instr, best_comb);
		instr++;
	}
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
		if (!can_push_a(*lst_a, *lst_b))
		{
			best_comb = best_insert(*lst_a, *lst_b, best_comb);
			while (nb_instruction(&best_comb, FIRST_INSTR))
				if (is_rotate_instr(best_comb[FIRST_INSTR]))
					apply_instr(best_comb[NB_FIRST_INSTR], lst_a, lst_b, PRINT);
			while (nb_instruction(&best_comb, SECOND_INSTR))
				if (is_rotate_instr(best_comb[SECOND_INSTR]))
					apply_instr(best_comb[NB_SECOND_INSTR], lst_a, lst_b, PRINT);
		}
		apply_instr(pa, lst_a, lst_b, 1);
	}
}
