/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:47:40 by supersko          #+#    #+#             */
/*   Updated: 2025/01/20 05:11:32 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lnk *reach_max(t_lnk *lst)
{
    int max;

    max = get_max(lst);
    reach_rank_lst_a_in_dir(&lst, NULL, max, ROTATE, QUIET);
    return (lst);
}

t_lnk *reach_min(t_lnk *lst)
{
    int min;

    min = get_min(lst);
    reach_rank_lst_a_in_dir(&lst, NULL, min, ROTATE, QUIET);
    return (lst);
}

int	get_softmax_in_a(t_lnk *lst)
{
    lst = reach_max(lst);
    while (lst->rank == lst->prev->rank + 1)
        lst = lst->prev;
    return (lst->rank);
}

int	get_softmax_in_b(t_lnk *lst)
{
    lst = reach_max(lst);
    while (lst->rank == lst->next->rank + 1)
        lst = lst->next;
    return (lst->rank);
}

int	get_softmin_in_a(t_lnk *lst)
{
    lst = reach_min(lst);
    while (lst->rank == lst->next->rank - 1)
        lst = lst->next;
    return (lst->rank);
}

int	get_softmin_in_b(t_lnk *lst)
{
    lst = reach_min(lst);
    while (lst->rank == lst->prev->rank - 1)
        lst = lst->prev;
    return (lst->rank);
}

// void	from_min_to_max(t_lnk **lst_a, t_lnk **lst_b, int to_print)
// {
//     t_lnk *ind_a;

//     ind_a = *lst_a;
//     while (ind_a->n != get_softmax(*lst_a))
// }