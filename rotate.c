/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 21:16:34 by supersko          #+#    #+#             */
/*   Updated: 2022/05/12 18:44:47 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void    rotate_lst(t_lnk **lst)
{
    if (!(*lst))
        error_msg("[rotate_lst] rotate an empty list");
    *lst = (*lst)->next;
}

void    rrotate_lst(t_lnk **lst)
{
    if (!(*lst))
        error_msg("[rrotate_lst] reverse-rotate an empty list");
    *lst = (*lst)->prev;
}