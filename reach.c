/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reach.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:47:40 by supersko          #+#    #+#             */
/*   Updated: 2025/01/31 02:38:03 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reach_rank_lst_b(t_lnk **lst, int rank, int direction)
{
	t_lnk	*first_lnk;
	int		instr;

	instr = rb;
	if (direction == RROTATE)
		instr = rrb;
	first_lnk = *lst;
	if (first_lnk->rank != rank)
	{
		apply_instr(&d, &d.lst_a, &d.lst_b, instr, QUIET);
		while ((*lst)->rank != rank && *lst != first_lnk)
			apply_instr(&d, &d.lst_a, &d.lst_b, instr, QUIET);
	}
}

void	reach_rank_lst_a(t_lnk **lst, int rank, int direction)
{
	t_lnk	*first_lnk;
	int		instr;

	instr = ra;
	if (direction < 0)
		instr = rra;
	first_lnk = *lst;
	if (first_lnk->rank != rank)
	{
		apply_instr(&d, &d.lst_a, &d.lst_b, instr, QUIET);
		while ((*lst)->rank != rank && *lst != first_lnk)
			apply_instr(&d, &d.lst_a, &d.lst_b, instr, QUIET);
	}
}

void	shortestway_fucking_norminette(t_lnk **lst, int *step_nb, \
	int *found, int *rank)
{
	if (!(*found))
		(*step_nb)++;
	if ((*lst)->rank == *rank)
		*found = 1;
	*lst = (*lst)->next;
}

// renvoit un negatif si le chemin le plus court est en reverse
int	get_shortestway(int rank, t_lnk *lst)
{
	int		step_nb;
	int		len;
	t_lnk	*last_lnk;
	int		found;

	if (!lst)
		error_msg("[get_shortestway] empty list passed");
	step_nb = 0;
	len = 1;
	last_lnk = lst;
	found = 0;
	if (lst->rank == rank)
		return (0);
	lst = lst->next;
	while (lst != last_lnk && len++)
		shortestway_fucking_norminette(&lst, &step_nb, &found, &rank);
	if (!found)
		error_msg("[get_shortestway] rank not found");
	if (step_nb > len / 2)
		return (ROTATE);
	return (RROTATE);
}
