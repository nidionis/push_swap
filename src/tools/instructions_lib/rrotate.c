/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:49:48 by nidionis          #+#    #+#             */
/*   Updated: 2025/04/02 16:49:38 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate_both(t_lnk **lst_a, t_lnk **lst_b)
{
	if (*lst_a)
		rrotate_lst(lst_a);
	if (*lst_b)
		rrotate_lst(lst_b);
}

void	rrotate_a(t_lnk **lst_a, t_lnk **lst_b)
{
	(void)lst_b;
	if (*lst_a)
		*lst_a = (*lst_a)->prev;
}

void	rrotate_b(t_lnk **lst_a, t_lnk **lst_b)
{
	(void)lst_a;
	if (*lst_b)
		*lst_b = (*lst_b)->prev;
}
