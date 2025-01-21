/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/01/19 09:39:37 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	special_items(t_lnk *lst_a, int i1, int i2)
{
	if (lst_a->rank == i1)
		return (LOWEST);
	if (lst_a->rank == i2)
		return (MAX);
	return (MAYBE_A_WEAKNESS);
}

int	special_item(t_lnk *lst_a, int max)
{
	if (special_items(lst_a, 0, max) || lst_a->rank == max / 2)
	{
		if (lst_a->rank == max / 2)
			return (MEDIANE);
		else
			return (special_items(lst_a, 0, max));
	}
	return (MAYBE_A_WEAKNESS);
}

int get_dir(t_lnk *lst, int target_rk, int intermediate_target)
{
	int dir;

	dir = get_shortestway(lst, target_rk);
	dir += get_shortestway(lst, intermediate_target);
	return (dir);
}

int	opti_reach_by(t_lnk *lst, int target_rk, int intermediate_target)
{
	int dir;
	int steps;

	dir = get_dir(lst, target_rk, intermediate_target);
	steps = reach_rank(&lst, target_rk, dir, QUIET);
	return (steps);
}

int move_needed(t_lnk *lst_a, int target_rk, int intermediate_target)
{
	if (lst_a->rank == target_rk)
	{
		if (lst_a->next->rank == intermediate_target)
			return (FALSE);
		if (lst_a->prev->rank == intermediate_target)
			return (FALSE);
	}
	if (lst_a->rank == intermediate_target)
	{
		if (lst_a->next->rank == target_rk)
			return (FALSE);
		if (lst_a->prev->rank == target_rk)
			return (FALSE);
	}
	return (TRUE);
}

int reach_to_by(t_lnk **lst_a, int target_rk, int intermediate_target, int to_print)
{
	int dir;
	int cost;
	int instr;
	int target_;

	instr = ra;
	target_ = intermediate_target;
	if (move_needed(*lst_a, target_rk, intermediate_target))
		dir = reach_rank(lst_a, target_, ROTATE, PRINT);
	else 
		dir = opti_reach_by(*lst_a, target_rk, intermediate_target);
	if (dir < 0)
	{
		instr = INSTR_MIN;
		dir *= -1;
	}
	cost = dir;
	while (dir--)
		apply_instr(instr, lst_a, NULL, to_print);
	return (cost);
}

//void	load_b(t_lnk **lst_a, t_lnk **lst_b, int max)
//{
//	while (!is_sorted(*lst_a))
//	{
//		if (special_item(*lst_a, max))
//			apply_instr(ra, lst_a, lst_b, 1);
//		else
//		{
//			//reach_to_by(lst_a, 0, max, PRINT);
//			return ;
//		}
//	}
//}
//
