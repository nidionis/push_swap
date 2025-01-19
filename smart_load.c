/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/01/19 11:38:13 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	special_item(t_lnk *lst_a, int i1, int i2)
{
	if (lst_a->rank == i1)
		return (LOWEST);
	if (lst_a->rank == i2)
		return (MAX);
	return (MAYBE_A_WEAKNESS);
}

int	special_items(t_lnk *lst_a, int max)
{
	if (special_item(lst_a, 0, max) || lst_a->rank == max / 2)
	{
		if (lst_a->rank == max / 2)
			return (MEDIANE);
		else
			return (special_item(lst_a, 0, max));
	}
	return (MAYBE_A_WEAKNESS);
}

int get_dir(t_lnk *lst, int target_rk, int intermediate_target)
{
	int dir;

	dir = get_shortestway(lst, target_rk);
	dir -= get_shortestway(lst, intermediate_target);
	return (dir);
}

int get_softmin(t_lnk *lst)
{
	int max;
	t_lnk *l_ind;

	if (!lst)
		return (INT_MIN);
	l_ind = lst->prev;
	max = get_max(lst);
	reach_rank(&l_ind, max, REVERSE_ROTATE, QUIET);
	while (lst->rank == max--)
		lst = lst->prev;
	return (max);
}


int get_softmax(t_lnk *lst)
{
	int min;
	t_lnk *l_ind;

	if (!lst)
		return (INT_MIN);
	l_ind = lst->next;
	min = get_min(lst);
	reach_rank(&l_ind, min, ROTATE, QUIET);
	while (lst->rank == min++)
		lst = lst->next;
	return (min);
}


int get_max(t_lnk *lst)
{
	t_lnk	*lnk;
	int max;

	max = INT_MIN;
	lnk = lst->next;
	while (lnk != lst)
	{
		if (lnk->rank > max)
			max = lnk->rank;
		lnk = lnk->next;
	}
	return (max);
}

int get_min(t_lnk *lst)
{
	t_lnk	*lnk;
	int min;

	min = INT_MAX;
	lnk = lst->next;
	while (lnk != lst)
	{
		if (lnk->rank < min)
			min = lnk->rank;
		lnk = lnk->next;
	}
	return (min);
}

int move_needed(t_lnk *lst_a, int target_rk, int intermediate_target)
{
	//int max_in_list;

	//max_in_list = get_max(lst_a);
	if (!lst_a)
		return (FALSE);
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

int push_a_to_by(t_lnk **lst_a, t_lnk **lst_b, int target_rk, int intermediate_target)
{
	int dir;
	int cost;
	int instr;
	int target_;

	instr = ra;
	target_ = get_max(*lst_a);
	if (!move_needed(*lst_a, target_rk, intermediate_target))
	{
		while (!move_needed(*lst_a, target_rk, intermediate_target))
			apply_instr(pb, lst_a, lst_b, PRINT);
		 = get_max(*lst_a);
	}
	if (move_needed(*lst_a, target_rk, intermediate_target))
	{

	}
		dir = reach_rank(*lst_a, target_rk, intermediate_target);
	if (dir < 0)
	{
		instr = INSTR_MIN;
		dir *= -1;
	}
	cost = dir;
	while (dir--)
		apply_instr(instr, lst_a, lst_b, PRINT);
	return (cost);
}

int reach_to_by(t_lnk **lst_a, t_lnk **lst_b, int target_rk, int intermediate_target, int to_print)
{
	int dir;
	int cost;
	int instr;
	int target_;

	instr = ROTATE_MIN;
	target_ = intermediate_target;
	if (move_needed(*lst_a, target_rk, intermediate_target))
	{
		dir = reach_rank(lst_a, target_, ROTATE, to_print);
		apply_instr(instr, lst_a, lst_b, to_print);
	}
	else 
	{
		apply_instr(instr, lst_a, lst_b, to_print);
	}
	if (dir < 0)
	{
		instr = INSTR_MINmax;
		dir *= -1;
	}
	cost = dir;
	while (dir--)
		apply_instr(instr, lst_a, NULL, to_print);
	return (cost);
}

int pushb_to_by(t_lnk **lst_a, t_lnk **lst_b, int target_rk, int intermediate_target, int to_print)
{
	int dir;
	int cost;
	int instr;
	int target_;

	instr = ROTATE_MIN;
	target_ = intermediate_target;
	if (!move_needed(*lst_a, target_rk, intermediate_target))
		while (!move_needed(*lst_a, target_rk, intermediate_target))
			apply_instr(pb, lst_a, lst_b, to_print);
	if (move_needed(*lst_a, target_rk, intermediate_target))
	{
		dir = reach_rank(lst_a, target_, 1, to_print);
		apply_instr(instr, lst_a, lst_b, to_print);
	}
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