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

#include "push_swap.h"

int	get_shortestway(int target_rank, t_lnk *list)
{
	  t_lnk *last;
    int   step;

    last = list;
    step = 0;
    while (list != last)
    {
      if (list->rank == target_rank)
        break ;
      list = list->next;
      step++;
    }
    if (step > ft_dlstsize(list) / 2)
      return (RROTATE);
    return (ROTATE);
}