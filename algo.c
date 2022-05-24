/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/24 15:10:37 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int can_push(t_lnk *lst_a, t_lnk *lst_b)
{
    if (lst_a->rank > lst_b->rank && (lst_a->prev)->rank < lst_b->rank)
        return (1);
    return (0);
}

int *itm_insert(t_lnk *lst_a, t_lnk *lst_b)
{
    int     instr;
    int     steps;
    t_lnk   *lst_a_init;
    t_lnk   *lst_b_init;
	int		*best_result;

	best_result = malloc(sizeof(int) * 2);
	if (!best_result)
		error_msg("[itm_insert] did not malloc");
	best_result[1] = 2147483647; 
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

int	refresh_best_inst_steps(int *best_inst_step, int instr, int steps, int *instr_steps_itm, int steps_max)
{
	if (instr_steps_itm[1] + steps < steps_max)
	{
		best_inst_step[0] = instr;
		best_inst_step[1] = steps;
		best_inst_step[2] = instr_steps_itm[0];
		best_inst_step[3] = instr_steps_itm[1];
	}
	free(instr_steps_itm);
	return (best_inst_step[1] + best_inst_step[3]);
}

void	refresh_in_dir(t_lnk *lst_a, t_lnk *lst_b, int instr, int *best_inst_step)
{
	int		steps;
	int		steps_max;
	int		*instr_steps_item;

	steps = 0;
	steps_max = best_inst_step[1] + best_inst_step[3];
	while (++steps < steps_max)
	{
		apply_instr(instr, &lst_a, &lst_b, 0);
		instr_steps_item = itm_insert(lst_a, lst_b);
		steps_max = refresh_best_inst_steps(best_inst_step, instr, steps, instr_steps_item, steps_max);
	}
}

int *best_insert(t_lnk *lst_a, t_lnk *lst_b)
{
	int *best_inst_step;
	int *itm_insert_result;
	int instr;

	best_inst_step = malloc(sizeof(int) * 4);
	if (!best_inst_step)
		error_msg("[best_instert] did not malloc");
	itm_insert_result = itm_insert(lst_a, lst_b);
	best_inst_step[0] = 0;
	best_inst_step[1] = 0;
	best_inst_step[2] = itm_insert_result[0];
	best_inst_step[3] = itm_insert_result[1];
	free(itm_insert_result);
	instr = ra;
	while (instr <= rrr)
	{
		refresh_in_dir(lst_a, lst_b, instr++, best_inst_step);
	}
	return (best_inst_step);
}


void    b_dump(t_lnk **lst_a, t_lnk **lst_b)
{
    int *best_inst_step;

    while (*lst_b)
    {
		if (!can_push(*lst_a, *lst_b))
		{
			best_inst_step = best_insert(*lst_a, *lst_b);
			while (best_inst_step[1]--)
				apply_instr(best_inst_step[0], lst_a, lst_b, 1);
			while (best_inst_step[3]--)
				apply_instr(best_inst_step[2], lst_a, lst_b, 1);
		}
		apply_instr(pa, lst_a, lst_b, 1);
	}
	free(best_inst_step);
}