/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 21:16:34 by supersko          #+#    #+#             */
/*   Updated: 2022/05/24 18:27:02 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	rotate_lst(t_lnk **lst)
{
	if (*lst)
		*lst = (*lst)->next;
}

void	rrotate_lst(t_lnk **lst)
{
	if (*lst)
		*lst = (*lst)->prev;
}
