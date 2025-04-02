/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_load_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:41:34 by nidionis          #+#    #+#             */
/*   Updated: 2025/04/02 23:14:25 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void init_r_instr_load_b_turk_(int r_instr[12])
{
    r_instr[0] = ra;
    r_instr[1] = rr;
    r_instr[2] = rb;
    r_instr[5] = rrb;
    r_instr[4] = rrr;
    r_instr[3] = rra;
    r_instr[6] = LOOP_END;
}

void init_r_instr_load_b_basic(int r_instr[12])
{
    r_instr[0] = rrr;
    r_instr[1] = rr;
    r_instr[2] = ra;
    r_instr[3] = rra;
    r_instr[4] = rb;
    r_instr[5] = rrb;
    r_instr[6] = LOOP_END;
}
