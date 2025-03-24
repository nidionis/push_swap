/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 21:16:34 by supersko          #+#    #+#             */
/*   Updated: 2025/02/02 21:32:43 by nidionis         ###   ########.fr       */
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
        data->a.softmax = UNSET;
    else if (lst_a->next == lst_a)
        data->a.softmax = lst_a->rank;
    else 
        data->a.softmax = get_softmax(lst_a)->rank;
    if (!lst_b)
        data->b.softmax = UNSET;
    else if (lst_b->next == lst_b)
        data->b.softmax = lst_b->rank;
    else 
        data->b.softmax = get_softmax(lst_b)->rank;
}

void	set_softmin(t_data *data, t_lnk*lst_a, t_lnk *lst_b)
{
    if (!lst_a)
        data->a.softmin = UNSET;
    else if (lst_a->next == lst_a)
        data->a.softmin = lst_a->rank;
    else 
        data->a.softmin = get_softmin(lst_a)->rank;
    if (!lst_b)
        data->b.softmax = UNSET;
    else if (lst_b->next == lst_b)
        data->b.softmax = lst_b->rank;
    else 
        data->b.softmin = get_softmin(lst_b)->rank;
}

void	data_update(t_data *data, t_lnk **lst_a, t_lnk **lst_b)
{
    t_lnk   *tmp;

    if (!data)
        return ;
    data->a.lst = *lst_a;
    data->b.lst = *lst_b;
    tmp = get_max(*lst_a);
    if (tmp)
        data->a.max = tmp->rank;
    else
        data->a.max = UNSET;
    tmp = get_max(*lst_b);
    if (tmp)
        data->b.max = tmp->rank;
    else
        data->b.max = UNSET;
    tmp = get_min(*lst_a);
    if (tmp)
        data->a.min = tmp->rank;
    else
        data->a.min = UNSET;
    tmp = get_min(*lst_b);
    if (tmp)
        data->b.min = tmp->rank;
    else
        data->b.min = UNSET;
    set_softmax(data, *lst_a, *lst_b);
    set_softmin(data, *lst_a, *lst_b);
    data->a.pivot = (data->a.softmax - data->a.softmin) / 2 + data->a.softmin;
    data->b.pivot = (data->b.softmax - data->b.softmin) / 2 + data->b.softmin;
}

void init_data(t_data *data, t_lnk **lst_a, t_lnk **lst_b)
{
    data_update(data, lst_a, lst_b);
    if (lst_a && *lst_a)
    {
        data->rank_max = get_max(*lst_a)->rank;
        if (lst_b && *lst_b)
            if (data->rank_max < get_max(*lst_b)->rank)
                data->rank_max = get_max(*lst_b)->rank;
    }
    data->a.size = ft_dlstsize(*lst_a);
    data->b.size = ft_dlstsize(*lst_b);
    //data->best_instr_step = NULL;
    //data->best_inst_step[NB_FIRST_INSTR] = INT_MAX;
    //data->best_cost_instr = SIZE_MAX;
    //data->best_cost_comb = SIZE_MAX;
    //data->r_instr[0] = rr;
    //data->r_instr[1] = rrr;
    //data->r_instr[2] = ra;
    //data->r_instr[3] = rb;
    //data->r_instr[4] = rra;
    //data->r_instr[5] = rrb;
    //data->r_instr[6] = LOOP_END;
    //init_instr_map(data->instr_map);
}

#include <stdio.h>
void print_data(t_data *d)
{
    printf("max_a: %d\n", d->a.max);
    printf("max_b: %d\n", d->b.max);
    printf("min_a: %d\n", d->a.min);
    printf("min_b: %d\n", d->b.min);
    printf("softmax_a: %d\n", d->a.softmax);
    printf("softmax_b: %d\n", d->b.softmax);
    printf("softmin_a: %d\n", d->a.softmin);
    printf("softmin_b: %d\n", d->b.softmin);
    printf("rank_max: %d\n", d->rank_max);
    //printf("best_cost_comb: %d\n", d->best_cost_comb);
}