/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_best_comb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 01:31:51 by nidionis          #+#    #+#             */
/*   Updated: 2025/02/03 01:39:29 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

//int	get_min(t_lnk *lst)
//{
//  t_lnk   *tmp;
//  int     min;
//
//  tmp = lst;
//  if (!lst)
//    return (EMPTY_LST);
//  min = INT_MAX;
//  while (tmp->next != lst)
//  {
//    if (tmp->rank < min)
//      min = tmp->rank;
//    tmp = tmp->next;
//  }
//  return (min);
//}
//
//int get_max(t_lnk *lst)
//{
//  t_lnk *tmp;
//  int     max;
//
//  tmp = lst;
//  if (!lst)
//    return (EMPTY_LST);
//  max = INT_MIN;
//  while (tmp->next != lst)
//  {
//    if (tmp->rank > max)
//      max = tmp->rank;
//    tmp = tmp->next;
//  }
//  return (max);
//}