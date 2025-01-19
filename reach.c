/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reach.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:47:40 by supersko          #+#    #+#             */
/*   Updated: 2025/01/19 06:12:43 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reach_and_push(t_lnk **lst, int rank, int direction)
{
	t_lnk	*first_lnk;
	int		instr;

	instr = ra;
	if (direction < 0)
		instr = rra;
	first_lnk = *lst;
	if (first_lnk->rank != rank)
	{
		apply_instr(instr, lst, NULL, PRINT);
		while ((*lst)->rank != rank && *lst != first_lnk)
			apply_instr(instr, lst, NULL, PRINT);
	}
}

int	reach_rank(t_lnk **lst, int rank, int direction, int to_print)
{
	t_lnk	*first_lnk;
	int		instr;
	int		nb_instr;

	instr = ra;
	if (direction < 0)
		instr = rra;
	first_lnk = *lst;
	nb_instr = 0;
	if (first_lnk->rank != rank)
	{
		apply_instr(instr, lst, NULL, to_print);
		nb_instr++;
		while ((*lst)->rank != rank && *lst != first_lnk)
		{
			apply_instr(instr, lst, NULL, to_print);
			nb_instr++;
		}
	}
	return (nb_instr);
}

int	next_step(t_lnk **lst, int *steps, int *is_found, int target_rank)
{
	//if (!(*is_found))
	(*steps)++;
	*lst = (*lst)->next;
	if ((*lst)->rank == target_rank)
		*is_found = TRUE;
	return (*steps);
}

// renvoit un negatif si le chemin le plus court est en reverse
int	get_shortestway(t_lnk *lst, int rank)
{
	int		step_nb;
	int		len;
	t_lnk	*last_lnk;
	int		found;

	if (!lst)
		ft_errmsg("[get_shortestway] empty list passed");
	step_nb = 0;
	len = 1;
	last_lnk = lst;
	found = 0;
	if (lst->rank == rank)
		return (0);
	lst = lst->next;
	while (lst != last_lnk && len++)
		next_step(&lst, &step_nb, &found, rank);
	if (!found)
		ft_errmsg("[get_shortestway] rank not found");
	if (step_nb > len / 2)
		return (step_nb - len);
	return (step_nb);
}
