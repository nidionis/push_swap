/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_dump_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:41:34 by nidionis          #+#    #+#             */
/*   Updated: 2025/04/01 18:39:20 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int can_insert_at_min_a(t_data *data) {
    t_lst *a;
    t_lst *b;

    a = &data->a;
    b = &data->b;
    if (a->size)
        return (head(b) > a->max || head(b) < a->min);
    return (FALSE);
}

int can_insert_to_a_between(t_data *data) {
    t_lst *a;
    t_lst *b;

    a = &data->a;
    b = &data->b;
    return (head(b) < head(a) && head(b) > prev(a));
}

int can_dump_b(t_data *data) {
    t_lst *a = &data->a;
    t_lst *b = &data->b;

    if (!a->lst)
        return (TRUE);
    if (!b->lst)
        return (FALSE);
    if (head(b) < a->min || head(b) > a->max)
        return (head(a) == a->min);
    if (head(a) == a->min)
        return (can_insert_at_min_a(data));
    return (can_insert_to_a_between(data));
}

int can_dump_new_softs(t_data *data) {
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
