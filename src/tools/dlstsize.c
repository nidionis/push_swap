/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:49:48 by nidionis          #+#    #+#             */
/*   Updated: 2025/04/02 16:53:33 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_dlstsize(t_lnk *lst)
{
    int		i;
    t_lnk	*lnk;

    i = 1;
    lnk = lst;
    if (!lnk)
        return (0);
    while (lnk->next != lst)
    {
        i++;
        lnk = lnk->next;
    }
    return (i);
}
