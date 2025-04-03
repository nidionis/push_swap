/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/04/03 22:32:45 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int sort_5_nb(t_data *d)
{
    int nb_instr;

    (void)d;
    nb_instr = 0;
    return (nb_instr);
}

int sort_2_nb(t_data *d)
{
    int nb_instr;

    nb_instr = 0;
    t_lst *a = &d->a;
    if (head(a) > next(a))
        nb_instr = apply_instr(d, sa, PRINT);
    return (nb_instr);
}

void sort_small_lst(t_data *d)
{
    if (d->a.size == 2)
        sort_2_nb(d);
    else if (d->a.size == 3)
        sort_3_nb(d);
    else if (d->a.size == 4)
        sort_4_nb(d);
    else if (d->a.size == 5)
        sort_5_nb(d);
}