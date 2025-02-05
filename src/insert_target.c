/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_target.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 01:26:50 by nidionis          #+#    #+#             */
/*   Updated: 2025/02/03 01:28:20 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int *insert_target_to_list_steps(t_data *data, int lst_instr[],
    int (*can_push)(t_data *data), int cost)
{
    t_data d;
    int instr_steps_itm[2];

    ft_memcpy(&d, data, sizeof(t_data));
    d.best_cost_comb = cost;
    if (try_initial_push(&d, lst_instr[0], can_push, instr_steps_itm))
        return malloc_instr_steps_itm(&d);
    iterate_instructions(&d, lst_instr, can_push);
    return malloc_instr_steps_itm(&d);
}

int try_initial_push(t_data *d, int instr,
    int (*can_push)(t_data *data), int instr_steps_itm[2])
{
    set_instr_step_itm(instr, 0, instr_steps_itm);
    if (can_push(d, d->lst_a, d->lst_b))
    {
        update_best_instr(d, instr_steps_itm);
        return 1;
    }
    return 0;
}

void iterate_instructions(t_data *d, int lst_instr[],
    int (*can_push)(t_data *data))
{
    int i_instr = 0;
    int instr = lst_instr[i_instr];
    int instr_steps_itm[2];
    while (instr != LOOP_END)
    {
        set_instr_step_itm(instr, INT_MAX, instr_steps_itm);
        instr_steps_itm[NB_INSTR] = count_instr(d, instr, can_push);
        update_best_instr(d, instr_steps_itm);
        d->best_cost_comb = ft_cost(d->best_comb);
        instr = lst_instr[++i_instr];
    }
}