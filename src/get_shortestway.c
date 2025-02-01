/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shortestway.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 22:13:50 by nidionis          #+#    #+#             */
/*   Updated: 2025/02/01 22:14:47 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	initialize_search(int *steps_forward, int *list_length, int *found, t_lnk *list, int target_rank)
{
	*steps_forward = 0;
	*list_length = 1;
	*found = (list->rank == target_rank);
}

void	search_target_rank(t_lnk *list, int target_rank, int *steps_forward, int *list_length, int *found)
{
	t_lnk	*current;

	current = list->next;
	while (current != list)
	{
		(*steps_forward)++;
		(*list_length)++;
		if (current->rank == target_rank)
		{
			*found = 1;
			break;
		}
		current = current->next;
	}
}

int	get_shortestway(int target_rank, t_lnk *list)
{
	int	steps_forward;
	int	list_length;
	int	found;

	if (!list)
	{
		ft_errmsg("[get_shortestway] empty list passed");
		return (0);
	}
	initialize_search(&steps_forward, &list_length, &found, list, target_rank);
	if (found)
		return (0);
	search_target_rank(list, target_rank, &steps_forward, &list_length, &found);
	if (!found)
	{
		ft_errmsg("[get_shortestway] rank not found");
		return (0);
	}
	if (steps_forward > list_length / 2)
		return (RROTATE);
	return (ROTATE);
}