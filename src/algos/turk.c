/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_load_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:41:34 by nidionis          #+#    #+#             */
/*   Updated: 2025/04/03 18:03:04 by nidionis         ###   ########.fr       */
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

static int	update_best_turk(int *best_coef, int *best_turk, int coef_turk, int nb_instr)
{
    if (nb_instr < *best_turk)
    {
        *best_turk = nb_instr;
        *best_coef = coef_turk;
    }
    return (1);
}

int	find_best_coef_turk(t_data d)
{
    int		coef_turk;
    int		best_coef;
    int		best_turk;
    int		nb_instr;
    t_lnk	*deep_cpy;

    coef_turk = 3;
    best_coef = coef_turk;
    best_turk = SIZE_MAX * 20;
    nb_instr = best_turk;
    deep_cpy = list_deep_cpy(d.a.lst);
    d.a.lst = list_deep_cpy(d.a.lst);
    while (coef_turk < 8)
    {
        reset_lst(&d, deep_cpy);
        nb_instr = main_algo(d, coef_turk, ra, QUIET);
        coef_turk += update_best_turk(&best_coef, &best_turk, coef_turk, nb_instr);
    }
    del_lst(&deep_cpy);
    del_lst(&d.a.lst);
    del_lst(&d.b.lst);
    return (best_coef);
}

