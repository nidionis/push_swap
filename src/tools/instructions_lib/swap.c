/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/02/02 17:47:34 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_lst(t_lnk **lst)
{
	t_lnk	*sec;

	if (*lst && (*lst)->next != *lst)
	{	
		sec = (*lst)->next;
		if (sec->next != *lst)
		{
			((*lst)->prev)->next = sec;
			(sec->next)->prev = *lst;
			sec->prev = (*lst)->prev;
			(*lst)->prev = sec;
			(*lst)->next = sec->next;
			sec->next = *lst;
			*lst = sec;
		}
		else
			rotate_lst(lst);
	}
}

void	swap_a(t_lnk **lst_a, t_lnk **lst_b)
{
	(void)lst_b;
	swap_lst(lst_a);
}

void	swap_b(t_lnk **lst_a, t_lnk **lst_b)
{
	(void)lst_a;
	swap_lst(lst_b);
}

void	swap_both(t_lnk **lst_a, t_lnk **lst_b)
{
	swap_lst(lst_a);
	swap_lst(lst_b);
}
