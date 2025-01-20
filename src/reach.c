/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reach.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:47:40 by supersko          #+#    #+#             */
/*   Updated: 2025/01/20 19:07:06 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reach_rank_lst_a(t_lnk **lst_a, t_lnk **lst_b, int rank, int to_print)
{
	int direction;
	int steps;

	direction = get_shortestway(*lst_a, rank);
	steps = reach_rank_lst_a_in_dir(lst_a, lst_b, rank, direction, to_print);
	return (steps);	
}

int	reach_rank_lst_b(t_lnk **lst_a, t_lnk **lst_b, int rank, int to_print)
{
	int direction;
	int steps;

	steps = 0;
	if (!*lst_b || (*lst_b)->rank == rank)
		return (steps);
	direction = get_shortestway(*lst_b, rank);
	steps = reach_rank_lst_b_in_dir(lst_a, lst_b, rank, direction, to_print);
	return (steps);
}

int	reach_rank_lst_a_in_dir(t_lnk **lst_a, t_lnk **lst_b, int rank, int direction, int to_print)
{
	t_lnk	*first_lnk;
	int		instr;
	int		nb_instr;

	(void)lst_b;
	instr = rra;
	if (direction == ROTATE)
		instr = ra;
	else if (direction != REVERSE_ROTATE)
		ft_errmsg("[reach_rank_lst_b_in_dir] direction not set");
	if (!*lst_a)
		return (0);
	first_lnk = *lst_a;
	nb_instr = 0;
	if (first_lnk->rank != rank)
	{
		apply_instr(instr, lst_a, lst_b, to_print);
		nb_instr++;
		while ((*lst_a)->rank != rank && *lst_a != first_lnk)
		{
			apply_instr(instr, lst_a, lst_b, to_print);
			nb_instr++;
		}
	}
	return (nb_instr);
}

int	reach_rank_lst_b_in_dir(t_lnk **lst_a, t_lnk **lst_b, int rank, int direction, int to_print)
{
	t_lnk	*first_lnk;
	int		instr;
	int		nb_instr;

	(void)lst_a;
	instr = rrb;
	if (direction == ROTATE)
		instr = rb;
	else if (direction != REVERSE_ROTATE)
		ft_errmsg("[reach_rank_lst_b_in_dir] direction not set");
	if (!*lst_b)
		return (0);
	first_lnk = *lst_b;
	nb_instr = 0;
	if (first_lnk->rank != rank)
	{
		apply_instr(instr, lst_a, lst_b, to_print);
		nb_instr++;
		while ((*lst_b)->rank != rank && *lst_b != first_lnk)
		{
			apply_instr(instr, lst_a, lst_b, to_print);
			nb_instr++;
		}
	}
	return (nb_instr);
}

int	next_step(t_lnk **lst, int *steps, int *is_found, int target_rk)
{
	*steps = *steps;
	*lst = (*lst)->next;
	if ((*lst)->rank == target_rk)
		*is_found = TRUE;
	return (*steps);
}

int	reverse_if_needed(int step_nb, int len)
{
	if (step_nb < 0)
		return (step_nb + len);
	return (step_nb);
}

int inc_steps(int steps)
{
	if (steps < 0)
		return (steps + 1);
	if (steps == 0)
		ft_errmsg("[inc_steps] steps == 0");
	return (steps - 1);
}

int	get_shortestway(t_lnk *lst, int rank)
{
	int		step_nb;
	t_lnk	*first_lnk;

	if (!lst)
		return (MAYBE_A_WEAKNESS);
	//if (lst == lst->next)
	//	return (ROTATE);
	step_nb = 0;
	first_lnk = lst->prev;
	while (lst->rank != rank && lst != first_lnk)
	{
		step_nb++;
		lst = lst->next;
	}
	if (step_nb <= get_size(lst) / 2)
		return (ROTATE);
	return (REVERSE_ROTATE);
}
