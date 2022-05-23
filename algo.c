/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/23 13:03:10 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int can_push(t_lnk *lst_a, t_lnk *lst_b)
{
    if (lst_a->rank > lst_b->rank && (lst_a->prev)->rank < lst_b->rank)
        return (1);
    return (0);
}

// return the best instr for reaching
int *shortest_insert(t_lnk *lst_a, t_lnk *lst_b, int *best_result)
{
    int     instr;
    int     steps;
    t_lnk   *lst_a_init;
    t_lnk   *lst_b_init;

    instr = ra;
	lst_a_init = lst_a;
	lst_b_init = lst_b;
    best_result[1] = 2147483647;
    while (instr <= rrr)
    {
        steps = 0;
        while (!can_push(lst_a, lst_b))
        {
            apply_instr(instr, &lst_a, &lst_b, 0);
            if (steps > best_result[1])
                break;
            steps++;
        }
        if (steps < best_result[1])
        {
            best_result[0] = instr;
            best_result[1] = steps;
        }
        lst_a = lst_a_init;
        lst_b = lst_b_init;
        instr++;
    }
    return (best_result);
}

void    b_dump(t_lnk **lst_a, t_lnk **lst_b)
{
    int *instr;

	instr = malloc(2 * sizeof(int));
	if (!instr)
		error_msg("[b_dump] error malloc");
    while (*lst_b)
    {
        instr = shortest_insert(*lst_a, *lst_b, instr);
        while (!can_push(*lst_a, *lst_b))
        {
            apply_instr(instr[0], lst_a, lst_b, 1);
        }
        apply_instr(pa, lst_a, lst_b, 1);
	}
	free(instr);
}