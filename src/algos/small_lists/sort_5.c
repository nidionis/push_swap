/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/04/04 15:21:43 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int sort_3_nexts_a(t_data *d)
{
    int nb_instr;

    nb_instr = 0;
    if (!is_sorted_a_n_nexts(d->a, 3))
        nb_instr = apply_instr(d, sa, PRINT);
    return (nb_instr);
}

int sort_5_nb(t_data *d)
{
    int nb_instr;
    int	r_instr[12];

    nb_instr = 0;
    if (!is_sorted_a_n_nexts(d->a, 5))
    {
        nb_instr = apply_instr(d, pb, PRINT);
        if (should_swap_a(&d->b))
            nb_instr += apply_instr(d, sa, PRINT);
        if (!is_sorted_a_n_nexts(d->a, 4))
        {
            nb_instr += apply_instr(d, pb, PRINT);
            nb_instr += sort_3_nexts_a(d);
            if (should_swap_b(&d->b)) {
                if (should_swap_a(&d->b))
                    nb_instr += apply_instr(d, ss, PRINT);
                else
                    nb_instr += apply_instr(d, sb, PRINT);
            }
        }
    }
    r_instr[0] = ra;
    r_instr[1] = rra;
    r_instr[2] = LOOP_END;
    nb_instr += dump_b_basic(d, r_instr, PRINT);
    reach_rank_a(d, 0, PRINT);
    return (nb_instr);
}