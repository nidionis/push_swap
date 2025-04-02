/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_load_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:41:34 by nidionis          #+#    #+#             */
/*   Updated: 2025/04/02 23:10:30 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int dump_b_basic(t_data *d, int *r_instr, int verbose)
{
    t_searching_op op_best_insert_b;
    int ret;

    op_best_insert_b = (t_searching_op) {can_dump_b, NULL, r_instr, pa, verbose};
    ret = 0;
    d->r_instr = r_instr;
    while (d->b.size) {
        ret += do_best_insert(d, &op_best_insert_b);
    }
    return (ret);
}
