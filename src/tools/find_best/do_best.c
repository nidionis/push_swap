/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifications.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/03/30 20:44:50 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	do_best_insert(t_data *data, t_searching_op *op)
{
    t_list *insertion_step;
    int nb_instr;

    nb_instr = UNSET_NB_INSTR;
    if (op->f_can(data))
        nb_instr = apply_instr(data, op->px, op->verbose);
    else
    {
        insertion_step = ft_best_comb(data, op->instr_ls, op->f_can, SIZE_MAX);
        if (!insertion_step)
            return (ERR_NO_BEST_COMB);
        nb_instr = ft_nb_instr(insertion_step);
        if (apply_best_comb_and(op->f_do, data, insertion_step, op->verbose) == BREAK_BEST_COMB)
            nb_instr = BREAK_BEST_COMB;
        ft_lstclear(&insertion_step, free);
    }
    return (nb_instr);
}
