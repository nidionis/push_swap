/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/03/30 23:01:19 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int can_splitload(t_data *data)
{
    t_lst *a;
    t_lst *b;

    a = &data->a;
    b = &data->b;
	if (!a->size)
		return (FALSE);
    if (b->size <= 2)
        return (TRUE);
    //if (head(a) > b->max || head(a) < b->min)
    //    return (head(b) == b->max);
    //if (head(b) == b->max)
    //    return (can_insert_at_max_b(data));
    if (head(a) >= b->pivot)
        return (head(b) >= b->pivot);
    if (head(a) < b->pivot)
        return (head(b) < b->pivot);
    return (FALSE);
}

int can_splitload_but_medium(t_data *data)
{
    t_lst *a;
    t_lst *b;

    a = &data->a;
    b = &data->b;
    if (b->size <= 2)
	{
        return (TRUE);
	}
	if (head(a) < data->rank_max / 3 || head(a) > data->rank_max * 2 / 3)
		return (can_splitload(data));
	return (FALSE);
}

int can_splitload_but_softs(t_data *data)
{
    t_lst *a;

    a = &data->a;
	if (head(a) <= a->softmin || head(a) >= a->softmax)
		return (FALSE);
	return (can_splitload(data));
}

//set data->min_to_load and data->max_to_load
int can_slpitload_but_range_and_softs(t_data *data) {
    t_lst *a;

    a = &data->a;
    if (head(a) <= a->softmin || head(a) >= a->softmax)
        return (FALSE);
    if (head(a) > data->max_to_load || head(a) < data->min_to_load)
        return (FALSE);
    return (can_splitload(data));
}

//set data->min_to_load and data->max_to_load
int can_first_splitload(t_data *data)
{
    t_lst *a;
    t_lst *b;

    a = &data->a;
    b = &data->b;
    if (!a->size)
        return (FALSE);
    if (b->size <= 2)
        return (TRUE);
    if (head(a) > data->max_to_load || head(a) < data->min_to_load)
        if (head(a) != 0 && head(a) != data->rank_max)
            return (FALSE);
    if (head(a) < b->min || head(a) > b->max)
        return (head(b) == b->max);
    if (head(a) == b->softmin + 1 || head(a) == b->softmax - 1)
        return (can_load_b(data));
    return (can_splitload(data));
}