/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/23 22:54:05 by supersko         ###   ########.fr       */
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
int *itm_insert(t_lnk *lst_a, t_lnk *lst_b, int *best_result)
{
    int     instr;
    int     steps;
    t_lnk   *lst_a_init;
    t_lnk   *lst_b_init;

    instr = ra;
	lst_a_init = lst_a;
	lst_b_init = lst_b;
	if (!can_push(lst_a, lst_b))
	{
    	while (instr <= rrr)
    	{
    	    steps = 0;
    	    while (!can_push(lst_a, lst_b))
    	    {
    	        apply_instr(instr, &lst_a, &lst_b, 0);
    	        if (steps >= best_result[1])
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
	}
	return (best_result);
}

int	min_in_dir(t_lnk *lst_a, t_lnk *lst_b, int instr, int *best_inst_step)
{
    t_lnk	**lst_a_cpy;
    t_lnk	**lst_b_cpy;
	int		steps;
	int 	*best_at_step;

	lst_a_cpy = &lst_a;
	lst_b_cpy = &lst_b;
	best_at_step = malloc(sizeof(int) * 3);
	if (!best_at_step)
		error_msg("[min_in_dir] malloc error");
	best_at_step[2] = best_inst_step[1];
	steps = 1;
	while (steps < best_at_step[2])
	{
		apply_instr(instr, lst_b_cpy, lst_b_cpy, 0);
		best_at_step = itm_insert(*lst_b_cpy, *lst_b_cpy, best_at_step);
		if (best_at_step[1] < best_inst_step[1] - steps)
		{
			best_at_step[2] = best_at_step[1] + steps;
		}
		steps++;
	}
	if (best_at_step[2] < best_inst_step[1])
		best_inst_step[1] = best_at_step[2];
	free(best_at_step);
	return (steps);
}

void    b_dump(t_lnk **lst_a, t_lnk **lst_b)
{
    int *best_instr_step;
    int min;
    int instr;

	best_instr_step = malloc(2 * sizeof(int));
	if (!best_instr_step)
		error_msg("[b_dump] error malloc");
    while (*lst_b)
    {
		best_instr_step[1] = 0;
		if (!can_push(*lst_a, *lst_b))
		{
			best_instr_step[1] = 2147483647;
  	    	best_instr_step = itm_insert(*lst_a, *lst_b, best_instr_step);
			instr = ra;
			min = 2147483647;
			while (instr <= rrr)
			{
				min_in_dir(*lst_a, *lst_b, instr, best_instr_step);
				min = best_instr_step[1];
				if (best_instr_step[1] > min)
				{
					best_instr_step[0] = instr;
					best_instr_step[1] = min;
				}
				instr++;
			}
			while (--best_instr_step[1])
			{
				apply_instr(best_instr_step[0], lst_a, lst_b, 1);
			}
			if (!can_push(*lst_a, *lst_b))
			{
				best_instr_step[1] = 2147483647;
				best_instr_step = itm_insert(*lst_a, *lst_b, best_instr_step);
				while (!can_push(*lst_a, *lst_b))
					apply_instr(best_instr_step[0], lst_a, lst_b, 1);
			}
		}
		apply_instr(pa, lst_a, lst_b, 1);
	}
	free(best_instr_step);
}