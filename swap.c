/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/15 22:33:51 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swap_lst(t_lnk **lst)
{
	t_lnk	*sec;

	sec = (*lst)->next;
	if (*lst && (*lst)->next != *lst)
	{	
		((*lst)->prev)->next = sec;
		(sec->next)->prev = *lst;
		sec->prev = (*lst)->prev;
		(*lst)->prev = sec;
		(*lst)->next = sec->next;
		sec->next = *lst;
		*lst = sec;
	}
}
