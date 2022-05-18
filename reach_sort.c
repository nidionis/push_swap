/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reach_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:47:40 by supersko          #+#    #+#             */
/*   Updated: 2022/05/18 14:52:20 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void	reachsort_step(t_lnk **lst, int ascend, int way, char lst_name)
{
	if (ascend < 0 && (*lst)->nb < ((*lst)->next)->nb && ft_printf("s%c\n", lst_name))
		apply_instr(sa, lst, NULL, 0);
	else if (ascend > -1 && (*lst)->nb > ((*lst)->next)->nb && ft_printf("s%c\n", lst_name))
		apply_instr(sa, lst, NULL, 0);
	else if ((*lst)->next != (*lst)->prev)
	{
		if (way < 0 && ft_printf("rr%c\n", lst_name))
			apply_instr(rra, lst, NULL, 0);
		else
		{
			apply_instr(ra, lst, NULL, 0);
			ft_printf("r%c\n", lst_name);
		}
	}
}
*/

void	shortestway_fucking_norminette(t_lnk **lst, int *step_nb, int *found, int *rank)
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
	int found;

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
		return (step_nb - len);
	return (step_nb);
}
