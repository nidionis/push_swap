/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_refreshing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:42:45 by supersko          #+#    #+#             */
/*   Updated: 2022/04/18 20:14:28 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_max(t_lst *lst)
{
	t_lnk	*tmp;
	int		max;

	if (lst->size == 1)
		max = (lst->first)->nb;
	else
	{
		max = (lst->first)->nb;
		tmp = (lst->first)->next;
		while (tmp != lst->first)
		{
			if (max < tmp->nb)
				max = tmp->nb;
			tmp = tmp->next;
		}	
	}
	lst->max_val = max;
}

void	reset_min(t_lst *lst)
{
	t_lnk	*tmp;
	int		min;

	if (lst->size == 1)
		min = (lst->first)->nb;
	else
	{
		min = (lst->first)->nb;
		tmp = (lst->first)->next;
		while (tmp != lst->first)
		{
			if (min > tmp->nb)
				min = tmp->nb;
			tmp = tmp->next;
		}	
	}
	lst->min_val = min;
}
