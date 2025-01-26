/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 21:16:34 by supersko          #+#    #+#             */
/*   Updated: 2025/01/26 22:54:37 by nidionis         ###   ########.fr       */
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

void set_softmax()
{
    if (!d.lst_a || d.lst_a->next == d.lst_a)
        d.softmax_a = UNSET;
    else 
        d.softmax_a = get_softmax(d.lst_a)->rank;
    if (!d.lst_b || d.lst_b->next == d.lst_b)
        d.softmax_b = UNSET;
    else 
        d.softmax_b = get_softmax(d.lst_b)->rank;
}

void set_softmin()
{
    if (!d.lst_a || d.lst_a->next == d.lst_a)
        d.softmin_a = UNSET;
    else 
        d.softmin_a = get_softmin(d.lst_a)->rank;
    if (!d.lst_b || d.lst_b->next == d.lst_b)
        d.softmin_b = UNSET;
    else 
        d.softmin_b = get_softmin(d.lst_b)->rank;
}

void    data_update()
{
    t_lnk   *tmp;
    tmp = get_max(d.lst_a);
    if (tmp)
        d.max_a = tmp->rank;
    else
        d.max_a = UNSET;
    tmp = get_max(d.lst_b);
    if (tmp)
        d.max_b = tmp->rank;
    else
        d.max_b = UNSET;
    tmp = get_min(d.lst_a);
    if (tmp)
        d.min_a = tmp->rank;
    else
        d.min_a = UNSET;
    tmp = get_min(d.lst_b);
    if (tmp)
        d.min_b = tmp->rank;
    else
        d.min_b = UNSET;
    set_softmax();
    set_softmin();
}

void set_data()
{
    data_update();
    d.rotate_instr[ROTATE][0] = ra;
    d.rotate_instr[ROTATE][1] = rr;
    d.rotate_instr[ROTATE][2] = rb;
    d.rotate_instr[ROTATE][3] = rrb;
    d.rotate_instr[RROTATE][0] = rra;
    d.rotate_instr[RROTATE][1] = rrr;
    d.rotate_instr[RROTATE][2] = rb;
    d.rotate_instr[RROTATE][3] = rrb;
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