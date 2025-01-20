/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reach.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:47:40 by supersko          #+#    #+#             */
/*   Updated: 2025/01/20 01:22:47 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

/*
    apres les? nexts_steps dans la boule while:
	//if (!found)
	//	ft_errmsg("[get_shortestway] rank not found");
	peut etre hacked by someone ?
*/
/*
	note: renvoit un negatif si le chemin le plus court est en reverse
*/
int	get_shortestway(t_lnk *lst, int rank)
{
	int		step_nb;
	t_lnk	*last_lnk;
	int		found;

	if (!lst)
		ft_errmsg("[get_shortestway] empty list passed");
	step_nb = 1;
	last_lnk = lst;
	found = 0;
	if (lst->rank == rank)
		return (0);
	lst = lst->next;
	while (lst != last_lnk && step_nb)
	{
		next_step(&lst, &step_nb, &found, rank);
		step_nb = inc_steps(step_nb);
	}
	step_nb = reverse_if_needed(step_nb, step_nb);
	return (step_nb);
}
