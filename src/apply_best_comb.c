/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_best_comb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 01:31:51 by nidionis          #+#    #+#             */
/*   Updated: 2025/02/03 01:39:29 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int apply_set_and(int (*f_do)(t_data *d, int instr), t_data *data, int *best_comb_set)
{
    if (best_comb_set[INSTR] == NO_INSTR || best_comb_set[NB_INSTR] == CANT_INSERT)
        return (NO_MOVE);
    while (best_comb_set[NB_INSTR]--)
    {
        apply_instr(data, best_comb_set[INSTR], PRINT);
        if (f_do)
            if (f_do(data, best_comb_set[INSTR]) == BREAK_BEST_COMB)
                return (BREAK_BEST_COMB);
    }
    return (TRUE);
}

int apply_best_comb_and(int (*f_do)(t_data *d, int instr), t_data *data, int *best_comb)
{
    int result;

    result = apply_set_and(f_do, data, &best_comb[FIRST_INSTR]);
    if (result != TRUE)
        return result;
    result = apply_set_and(f_do, data, &best_comb[SECOND_INSTR]);
    return (TRUE);
}