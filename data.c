/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 21:16:34 by supersko          #+#    #+#             */
/*   Updated: 2025/01/30 20:28:01 by nidionis         ###   ########.fr       */
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

void	set_softmax(t_data *data, t_lnk *lst_a, t_lnk *lst_b)
{
    if (!lst_a)
        data->softmax_a = UNSET;
    else if (lst_a->next == lst_a)
        data->softmax_a = lst_a->rank;
    else 
        data->softmax_a = get_softmax(lst_a)->rank;
    if (!lst_b || lst_b->next == lst_b)
        data->softmax_b = UNSET;
    else 
        data->softmax_b = get_softmax(lst_b)->rank;
}

void	set_softmin(t_data *data, t_lnk*lst_a, t_lnk *lst_b)
{
    if (!lst_a)
        data->softmin_a = UNSET;
    else if (lst_a->next == lst_a)
        data->softmin_a = lst_a->rank;
    else 
        data->softmin_a = get_softmin(lst_a)->rank;
    if (!lst_b || lst_b->next == lst_b)
        data->softmin_b = UNSET;
    else 
        data->softmin_b = get_softmin(lst_b)->rank;
}

void	data_update(t_data *data, t_lnk **lst_a, t_lnk **lst_b)
{
    t_lnk   *tmp;

    tmp = get_max(*lst_a);
    if (tmp)
        data->max_a = tmp->rank;
    else
        data->max_a = UNSET;
    tmp = get_max(*lst_b);
    if (tmp)
        data->max_b = tmp->rank;
    else
        data->max_b = UNSET;
    tmp = get_min(*lst_a);
    if (tmp)
        data->min_a = tmp->rank;
    else
        data->min_a = UNSET;
    tmp = get_min(*lst_b);
    if (tmp)
        data->min_b = tmp->rank;
    else
        data->min_b = UNSET;
    set_softmax(data, *lst_a, *lst_b);
    set_softmin(data, *lst_a, *lst_b);
}

void set_data(t_data *data, t_lnk **lst_a, t_lnk **lst_b)
{
    data_update(data, lst_a, lst_b);
    if (lst_a && *lst_a)
    {
        data->rank_max = get_max(*lst_a)->rank;
        if (lst_b && *lst_b)
            if (data->rank_max < get_max(*lst_b)->rank)
                data->rank_max = get_max(*lst_b)->rank;
    }
    data->best_inst_step[NB_FIRST_INSTR] = INT_MAX;
    //data->best_cost_instr = SIZE_MAX;
    data->best_cost_comb = SIZE_MAX;
    data->full_instr[0] = rr;
    data->full_instr[1] = rrr;
    data->full_instr[2] = ra;
    data->full_instr[3] = rb;
    data->full_instr[4] = rra;
    data->full_instr[5] = rrb;
    data->full_instr[6] = LOOP_END;
    data->b_only_instr[0] = rb;
    data->b_only_instr[1] = rrb;
    data->b_only_instr[2] = LOOP_END;
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
    printf("rank_max: %d\n", d->rank_max);
    printf("best_cost_comb: %d\n", d->best_cost_comb);
}