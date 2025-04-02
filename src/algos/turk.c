/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_load_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:41:34 by nidionis          #+#    #+#             */
/*   Updated: 2025/04/02 23:09:51 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int load_b_Turk(t_data *d, int coef_turk, int verbose)
{
    int ret;
    int pivot;
    t_lst *b;

    b = &d->b;
    pivot = d->min_to_load + (d->max_to_load - d->min_to_load) / COEF_TURK;
    ret = 0;
    ret = apply_instr(d, pb, verbose);
    if (head(b) < pivot)
        ret = apply_instr(d, rb, verbose);
    if (head(b) != b->max)
        if (head(b) < next(b) && head(b) < coef_turk)
            ret = apply_instr(d, sb, verbose);
    return (ret);
}


int load_b_opti_turk(t_data *d, int coef_turk, int r_x, int verbose)
{
    int nb_instr;

    nb_instr = 0;
    while (!is_sorted(d->a.lst)) {
        d->min_to_load = d->a.max / coef_turk;
        d->max_to_load = d->a.max - d->min_to_load * 2;
        if (head(&d->a) >= d->max_to_load || head(&d->a) <= d->min_to_load)
        {
            nb_instr += load_b_Turk(d, coef_turk, verbose);
        }
        else
            nb_instr += apply_instr(d, r_x, verbose);
    }
    return (nb_instr);
}
