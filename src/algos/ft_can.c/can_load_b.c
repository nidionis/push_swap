/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:41:34 by nidionis          #+#    #+#             */
/*   Updated: 2025/02/03 00:10:14 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int can_range_sort(t_data *data)
{
    t_lst *a;
    t_lst *b;

    a = &data->a;
    b = &data->b;
    if (b->size <= 2)
        return (TRUE);
    if (head(b) == b->max)
        return (can_load_b(data));
    if (head(a) >= head(b) - b->sorting_range && head(a) <= head(b) + b->sorting_range)
        return (TRUE);
    return  (can_load_b(data));
}

int can_splitload(t_data *data)
{
    t_lst *a;
    t_lst *b;

    a = &data->a;
    b = &data->b;
    if (b->size <= 2)
        return (TRUE);
    if (head(b) == b->max)
        return (can_insert_at_max_b(data));
    if (head(a) >= b->pivot)
        return (head(b) >= b->pivot);
    if (head(a) < b->pivot)
        return (head(b) < b->pivot);
    return (can_load_b(data));
}

int can_first_load(t_data *data) {
    t_lst *a;
    t_lst *b;

    a = &data->a;
    b = &data->b;
    if (b->size > 2)
        if (head(a) == data->rank_max && prev(b) == b->min)
            return (TRUE);
    if (head(a) > data->rank_max / 2)
        return (FALSE);
    return (can_load_b(data));
}

int can_load_high(t_data *data) {
    t_lst *a;

    a = &data->a;
    if (head(a) < a->pivot)
        return (FALSE);
    if (head(a) >= a->softmax)
        return (FALSE);
    return (can_load_b(data));
}

int can_insert_at_max_b(t_data *data) {
    t_lst *a;
    t_lst *b;

    a = &data->a;
    b = &data->b;
    if (b->size)
        if (head(a) > b->max || head(a) < b->min)
            return (TRUE);
    return (FALSE);
}

int can_insert_to_b_between(t_data *data) {
    t_lst *a;
    t_lst *b;

    a = &data->a;
    b = &data->b;
    return (head(a) > head(b) && head(a) < prev(b));
}

int can_load_b(t_data *data) {
    t_lst *a = &data->a;
    t_lst *b = &data->b;
    int size_b;

    if (!a->lst)
        return (FALSE);
    if (!b->lst)
        return (TRUE);
    size_b = b->size;
    if (size_b == 1)
        return (TRUE);
    if (head(b) == b->max)
        return (can_insert_at_max_b(data));
    if (head(a) > b->max || head(a) < b->min)
        return (head(b) == b->max);
    //if (size_b == 2)
    //    return (head(a) > b->min && head(a) < b->max);
    return (can_insert_to_b_between(data));
}

int can_dump_b(t_data *data) {
    t_lst *a;
    t_lst *b;

    a = &data->a;
    b = &data->b;
    if (!a)
        return (TRUE);
    if (!b)
        return (FALSE);
    if (head(a) == a->softmax && head(b) == a->softmax - 1)
        return (TRUE);
    if (a->lst->prev->rank == a->softmin && head(b) == a->softmin + 1)
        return (TRUE);
    return (FALSE);
}
