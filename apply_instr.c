/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/13 18:25:06 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
void    fucking_norminette(int instr, t_lnk **lst_a, t_lnk **lst_b, t_lnk **instr_lst)
{
    if (instr == ra)
        rotate_lst(lst_a);
    else if (instr == rb)
        rotate_lst(lst_b);
    else if (instr == rr)
    {
        rotate_lst(lst_b);
        rotate_lst(lst_a);
    }
    else if (instr == rra)
        rrotate_lst(lst_a);
    else if (instr == rrb)
        rrotate_lst(lst_b);
    else if (instr == rrr)
    {
        rrotate_lst(lst_b);
        rotate_lst(lst_a);
    }
    else
        error_msg("[apply_instr] instruction probably wrong");
    (void)instr_lst;
}

void    apply_instr(int instr, t_lnk **lst_a, t_lnk **lst_b, t_lnk **instr_lst)
{
    if (instr == sa)
        swap_lst(lst_a);
    else if (instr == sb)
        swap_lst(lst_b);
    else if (instr == ss)
    {
        swap_lst(lst_a);
        swap_lst(lst_b);
    }
    else if (instr == pa)
        push(lst_a, lst_b);
    else if (instr == pb)
        push(lst_b, lst_a);
    else if (instr == ra)
        rotate_lst(lst_a);
    else if (instr == rb)
        rotate_lst(lst_b);
    else if (instr == rr)
    {
        rotate_lst(lst_b);
        rotate_lst(lst_a);
    }
    else
        fucking_norminette(instr, lst_a, lst_b, instr_lst);
    (void)instr_lst;
}