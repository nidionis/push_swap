/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/04/04 14:29:06 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int should_swap_b(t_lst *b)
{
    if (head(b) == b->min)
    {
        if (b->lst->next->next->rank == b->max)
            return (TRUE);
    }
    else if (head(b) < next(b))
        return (TRUE);
    return (FALSE);
}

int should_swap_a(t_lst *a)
{
    if (head(a) == a->max)
    {
        if (a->lst->next->next->rank == a->min)
            return (TRUE);
    }
    else if (head(a) > next(a))
        return (TRUE);
    return (FALSE);
}