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

void	apply_instr_step_itm_test(t_lnk **lst_a, t_lnk **lst_b,
		int **instr_steps_itm_addr, int verbose)
{
	int	*instr_steps_itm;

	instr_steps_itm = *instr_steps_itm_addr;
	if (instr_steps_itm[NB_INSTR] != CANT_INSERT)
		while (instr_steps_itm[NB_INSTR]--)
			apply_instr(&d, lst_a, lst_b, instr_steps_itm[INSTR], verbose);
	free(instr_steps_itm);
	instr_steps_itm = NULL;
}

void	apply_instr_step_itm(int **instr_steps_itm_addr)
{
	apply_instr_step_itm_test(&d.lst_a, &d.lst_b, instr_steps_itm_addr, PRINT);
}

int apply_instr(t_data *data, int *best_comb, int instr_idx, int nb_instr_idx)
{
    while (best_comb[nb_instr_idx]--)
    {
        if (f_do(data, best_comb[instr_idx]) == BREAK_BEST_COMB)
            return BREAK_BEST_COMB;
        apply_instr(data, best_comb[instr_idx], PRINT);
        if (f_do(data, best_comb[instr_idx]) == BREAK_BEST_COMB)
            return BREAK_BEST_COMB;
    }
    return TRUE;
}

int apply_first_set(t_data *data, int *best_comb)
{
    if (best_comb[FIRST_INSTR] == CANT_INSERT)
        return CANT_INSERT;
    
    return apply_instr(data, best_comb, FIRST_INSTR, NB_FIRST_INSTR);
}

int apply_second_set(t_data *data, int *best_comb)
{
    if (best_comb[SECOND_INSTR] != NO_INSTR && best_comb[NB_SECOND_INSTR] != CANT_INSERT)
    {
        return apply_instr(data, best_comb, SECOND_INSTR, NB_SECOND_INSTR);
    }
    return TRUE;
}

int apply_best_comb_and(int (*f_do)(t_data *d, int instr), t_data *data, int *best_comb)
{
    int result;

    result = apply_first_set(data, best_comb);
    if (result != TRUE)
        return result;

    result = apply_second_set(data, best_comb);
    if (result != TRUE)
        return result;

    free(best_comb);
    return TRUE;
}

int	apply_best_comb(t_data *data, int *best_comb)
{
	if (best_comb[FIRST_INSTR] == CANT_INSERT)
		return (CANT_INSERT);
	while (best_comb[NB_FIRST_INSTR]--)
		apply_instr(data, best_comb[FIRST_INSTR], PRINT);
	if (best_comb[SECOND_INSTR] != NO_INSTR && best_comb[NB_SECOND_INSTR] != CANT_INSERT)
		while (best_comb[NB_SECOND_INSTR]--)
			apply_instr(data,
				best_comb[SECOND_INSTR], PRINT);
	free(best_comb);
	return (TRUE);
}