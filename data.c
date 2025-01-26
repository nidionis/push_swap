/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 21:16:34 by supersko          #+#    #+#             */
/*   Updated: 2025/01/26 19:33:56 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_lnk     *get_max(t_lnk *lst)
{
    t_lnk   *tmp;
    t_lnk    *max;

    tmp = lst;
    max = lst;
    if (!lst)
        return (NULL);
    tmp = tmp->next;
    while (tmp != lst)
    {
        if (tmp->rank > max->rank)
            max = tmp;
        tmp = tmp->next;
    }
    return (max);
}

t_lnk *get_min(t_lnk *lst)
{
    t_lnk   *tmp;
    t_lnk    *min;

    tmp = lst;
    min = lst;
    if (!lst)
        return (NULL);
    tmp = tmp->next;
    while (tmp != lst)
    {
        if (tmp->rank < min->rank)
            min = tmp;
        tmp = tmp->next;
    }
    return (min);
}

t_lnk *get_softmax(t_lnk *lst)
{
    t_lnk   *tmp;

    if (!lst || lst->next == lst)
        return (NULL);
    tmp = get_max(lst);
    if (tmp->rank == tmp->prev->rank + 1)
        while (tmp->rank == tmp->prev->rank + 1)
            rrotate_lst(&tmp);
    return (tmp);
}

t_lnk *get_softmin(t_lnk *lst)
{
    t_lnk   *tmp;

    if (!lst || lst->next == lst)
        return (NULL);
    tmp = get_min(lst);
    if (tmp->rank == tmp->next->rank - 1)
        while (tmp->rank == tmp->next->rank - 1)
            rotate_lst(&tmp);
    return (tmp);
}

void set_softmax(t_data *d, t_lnk *lst_a, t_lnk *lst_b)
{
    if (!lst_a || lst_a->next == lst_a)
        d->softmax_a = UNSET;
    else 
        d->softmax_a = get_softmax(lst_a)->rank;
    if (!lst_b || lst_b->next == lst_b)
        d->softmax_b = UNSET;
    else 
        d->softmax_b = get_softmax(lst_b)->rank;
}

void set_softmin(t_data *d, t_lnk *lst_a, t_lnk *lst_b)
{
    if (!lst_a || lst_a->next == lst_a)
        d->softmin_a = UNSET;
    else 
        d->softmin_a = get_softmin(lst_a)->rank;
    if (!lst_b || lst_b->next == lst_b)
        d->softmin_b = UNSET;
    else 
        d->softmin_b = get_softmin(lst_b)->rank;
}

void    data_update(t_data *d, t_lnk *lst_a, t_lnk *lst_b)
{
    t_lnk   *tmp;
    tmp = get_max(lst_a);
    if (tmp)
        d->max_a = tmp->rank;
    else
        d->max_a = UNSET;
    tmp = get_max(lst_b);
    if (tmp)
        d->max_b = tmp->rank;
    else
        d->max_b = UNSET;
    tmp = get_min(lst_a);
    if (tmp)
        d->min_a = tmp->rank;
    else
        d->min_a = UNSET;
    tmp = get_min(lst_b);
    if (tmp)
        d->min_b = tmp->rank;
    else
        d->min_b = UNSET;
    set_softmax(d, lst_a, lst_b);
    set_softmin(d, lst_a, lst_b);
}

void set_data(t_data *d, t_lnk *lst_a, t_lnk *lst_b)
{
    t_lnk   *tmp;

    tmp = lst_a;
    while (tmp->next != lst_a)
    {
        tmp->d = d;
        tmp = tmp->next;
    }
    tmp->d = d;
    data_update(d, lst_a, lst_b);
}

#include <stdio.h>
void print_data(t_data *d)
{
    printf("max_a: %d\n", d->max_a);
    printf("max_b: %d\n", d->max_b);
    printf("min_a: %d\n", d->min_a);
    printf("min_b: %d\n", d->min_b);
    printf("softmax_a: %d\n", d->softmax_a);
    printf("softmax_b: %d\n", d->softmax_b);
    printf("softmin_a: %d\n", d->softmin_a);
    printf("softmin_b: %d\n", d->softmin_b);
}