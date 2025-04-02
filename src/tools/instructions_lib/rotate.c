/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 21:16:34 by supersko          #+#    #+#             */
/*   Updated: 2025/04/02 16:51:24 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_lst(t_lnk **lst)
{
	if (*lst)
		*lst = (*lst)->next;
	else
		write(2, "[rotate] empty list\n", 20);
}

void	rotate_both(t_lnk **lst_a, t_lnk **lst_b)
{
	if (*lst_a)
		rotate_lst(lst_a);
	if (*lst_b)
		rotate_lst(lst_b);
}

void	rrotate_lst(t_lnk **lst)
{
	if (*lst)
		*lst = (*lst)->prev;
	else
		write(2, "[rotate] empty list\n", 20);
}

void	rotate_a(t_lnk **lst_a, t_lnk **lst_b)
{
	(void)lst_b;
	if (*lst_a)
		*lst_a = (*lst_a)->next;
}

void	rotate_b(t_lnk **lst_a, t_lnk **lst_b)
{
	(void)lst_a;
	if (*lst_b)
		*lst_b = (*lst_b)->next;
}
