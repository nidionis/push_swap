/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reach.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:47:40 by supersko          #+#    #+#             */
/*   Updated: 2025/02/01 22:15:44 by nidionis         ###   ########.fr       */
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
		apply_instr(&d, &d.lst_a, &d.lst_b, instr, 1);
		while ((*lst)->rank != rank && *lst != first_lnk)
			apply_instr(&d, &d.lst_a, &d.lst_b, instr, 1);
	}
}

void	reach_rank_lst_a(t_lnk **lst, int rank, int direction, int verbose)
{
	t_lnk	*first_lnk;
	int		instr;

	instr = ra;
	if (direction < 0)
		instr = rra;
	first_lnk = *lst;
	if (first_lnk->rank != rank)
	{
		apply_instr(&d, &d.lst_a, &d.lst_b, instr, verbose);
		while ((*lst)->rank != rank && *lst != first_lnk)
			apply_instr(&d, &d.lst_a, &d.lst_b, instr, verbose);
	}
}

t_lnk	*reach_rank(t_lnk *lst, int rank)
{
	t_lnk	*first_lnk;

	first_lnk = lst;
	if (first_lnk->rank != rank)
	{
		apply_instr(NULL, &lst, NULL, ra, QUIET);
		while (lst->rank != rank && lst != first_lnk)
			apply_instr(NULL, &lst, NULL, ra, QUIET);
	}
	return (lst);
}
