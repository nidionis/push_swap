/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_dump.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/01/20 15:57:09 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void execute_best_comb(int *best_comb, t_lnk **lst_a, t_lnk **lst_b)
{
    while (best_comb[NB_FIRST_INSTR]-- > 0)
        apply_instr(best_comb[FIRST_INSTR], lst_a, lst_b, PRINT);
    while (best_comb[NB_SECOND_INSTR]-- > 0)
        apply_instr(best_comb[SECOND_INSTR], lst_a, lst_b, PRINT);
}

void	init_best_comb(int *best_comb, int *itm_insert_result, t_lnk *lst_a, t_lnk *lst_b)
{
	if (!best_comb)
		ft_errmsg("[init_best_comb] did not malloc");
	itm_insert_result = itm_insert(lst_a, lst_b);
	best_comb[NB_FIRST_INSTR] = 0;
	best_comb[FIRST_INSTR] = rr;
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

void b_dump(t_lnk **lst_a, t_lnk **lst_b)
{
    int best_comb[4];

    while (*lst_b)
    {
        if (!can_push_a(*lst_a, *lst_b))
        {
            best_insert(*lst_a, *lst_b, best_comb);
            execute_best_comb(best_comb, lst_a, lst_b);
        }
        apply_instr(pa, lst_a, lst_b, PRINT);
    }
}

