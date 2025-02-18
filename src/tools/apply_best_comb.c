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

int apply_set_and(int (*f_do)(t_data *d, int instr), t_data *data, t_instr_step *instr_step, int verbose)
{
    if (instr_step->instr == NO_INSTR)
        return (NO_INSTR);
    else if  (instr_step->nb_instr == CANT_INSERT || instr_step->nb_instr == SIZE_MAX || instr_step->nb_instr == 0)
        return (instr_step->nb_instr);
    while (instr_step->nb_instr--)
    {
        apply_instr(data, instr_step->instr, verbose);
        if (f_do)
            if (f_do(data, instr_step->instr) == BREAK_BEST_COMB)
                return (BREAK_BEST_COMB);
    }
    return (TRUE);
}

int apply_best_comb_and(int (*f_do)(t_data *d, int instr), t_data *data, t_list *best_comb, int verbose)
{
    int status;

    status = TRUE;
    if (best_comb)
        while (best_comb)
        {
            status = apply_set_and(f_do, data, best_comb->content, verbose);
            best_comb = best_comb->next;
        }
    if (status != TRUE)
        return status;
    return (TRUE);
}