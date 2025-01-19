/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/01/19 06:10:24 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	special_item(t_lnk *lst_a, int max)
{
	if (lst_a->rank == 0 || lst_a->rank == max || lst_a->rank == max / 2)
		return (1);
	return (0);
}

int get_dir(t_lnk *lst, int target_rank, int intermediate_target)
{
	int dir;

	dir = get_shortestway(lst, target_rank);
	dir += get_shortestway(lst, intermediate_target);
	return (dir);
}

int	opti_reach_by(t_lnk *lst, int target_rank, int intermediate_target)
{
	int dir;
	int steps;

	dir = get_dir(lst, target_rank, intermediate_target);
	steps = reach_rank(&lst, target_rank, dir, QUIET);
	return (steps);
}

int reach_to_by(t_lnk **lst_a, int target_rank, int intermediate_target, int to_print)
{
	int dir;
	int cost;
	int instr;

	instr = ra;
	dir = opti_reach_by(*lst_a, target_rank, intermediate_target);
	if (dir < 0)
	{
		instr = rra;
		dir *= -1;
	}
	cost = dir;
	while (dir--)
		apply_instr(instr, lst_a, NULL, to_print);
	return (cost);
}

void	load_b(t_lnk **lst_a, t_lnk **lst_b, int max)
{
	while (!is_sorted(*lst_a))
	{
		if (special_item(*lst_a, max))
			apply_instr(ra, lst_a, lst_b, 1);
		else
		{
			reach_to_by(lst_a, 0, max, PRINT);
			return ;
		}
	}
}
