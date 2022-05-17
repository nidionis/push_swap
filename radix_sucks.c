/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sucks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/17 15:07:33 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

// reach rank 0 
int	get_RelMax(t_lnk *lst, int rankMax)
{
	t_lnk	*first_lnk;

	if (!lst || rankMax < 1)
		return (0);
	first_lnk = lst;
	if (lst->rank != rankMax)
	{
		lst = lst->next;
		while (lst->rank != rankMax && lst != first_lnk)
			lst = lst->next;
	}
	while (lst->rank == (lst->prev)->rank + 1)
		lst = lst->prev;
	return (lst->rank);
}

int	get_RelMin(t_lnk *lst)
{
	t_lnk	*first_lnk;

	if (!lst)
		return (0);
	first_lnk = lst;
	if (lst->rank != 0)
	{
		lst = lst->next;
		while (lst->rank != 0 && lst != first_lnk)
			lst = lst->next;
	}
	while (lst->rank == (lst->next)->rank - 1)
		lst = lst->next;
	return (lst->rank);
}

void	reach_rank(t_lnk **lst, int rank, int direction)
{
	t_lnk	*first_lnk;
	int		instr;

	instr = ra;
	if (direction < 0)
		instr = rra;
	first_lnk = *lst;
	if (first_lnk->rank != rank)
	{
		apply_instr(instr, lst, NULL, 1);
		while ((*lst)->rank != rank && *lst != first_lnk)
			apply_instr(instr, lst, NULL, 1);
	}
}
//
//void	loop(t_lnk **lst_a, t_lnk **lst_b, int relMin, int RelMax)
//{
	//t_lnk	first_lnk;
	//int		direction;
//
	//first_lnk = *lst_a;
	//direction = get_shortestway(relMin, *lst_a);
	//if (direction > 0)
	//{
//
	//}
//}
