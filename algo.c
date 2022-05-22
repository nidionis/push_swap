/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reach_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:47:40 by supersko          #+#    #+#             */
/*   Updated: 2022/05/19 22:13:45 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int best_instr(int lst[6])
{
    int i;
    int lowest;
    int instr_lowest;

    i = 1;
    lowest = lst[0];
    instr_lowest = ra;
    while (i < 6)
    {
        if (lst[i] < lowest)
        {
            lowest = lst[i];
            instr_lowest = i + ra;
        }
        i++;
    }
    return (instr_lowest);
}

int can_push(t_lnk lst_a, t_lnk lst_b)
{
    if (lst_a.rank < lst_b.rank && (lst_a.next).rank > lst_b.rank)
        return (1);
    return (0);
}

// return the best instr for reaching
int shortest_insert(t_lnk *lst_a, t_lnk *lst_b)
{
    int     results[6];
    int     instr;
    int     steps;
    t_lnk   *lst_a_init;
    t_lnk   *lst_b_init;

    instr = ra;
    while (instr <= rrr)
    {
        steps = 0;
        while (!can_push(*lst_a, *lst_b))
        {
            apply_instr(instr, lst_a, lst_b, 0);
            steps++;
        }
        results[instr - ra] = steps;
        lst_a = lst_a_init;
        lst_b = lst_b_init;
        instr++;
    }
    return (best_instr(results));
}

void    b_dump(t_lnk **lst_a, t_lnk **lst_b)
{
    int instr;

    while (lst_b)
    {
        instr = best_instr;
        while (!can_push(**lst_a, **lst_b))
        {
            apply_instr(instr, lst_a, lst_b, 1);
        }
        apply_instr(pa, lst_a, lst_b, 1);
}
