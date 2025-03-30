/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reach.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:47:40 by supersko          #+#    #+#             */
/*   Updated: 2025/02/01 22:15:44 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    get_kinda_mediane(t_data *data, t_lnk *lst)
{
    int min;
    int max;

    min = 0;
    max = data->rank_max;
    if (data->min_to_load != UNSET &&
            data->max_to_load != UNSET)
    {
        min = data->min_to_load;
        max = data->max_to_load;
    }
    else if (lst)
        if (!max || max == UNSET)
        {
            min = get_softmin(lst)->rank;
            max = get_softmax(lst)->rank;
        }
    return ((max - min) / 2 + min);
}

/* write get_ntil(t_lnk *lst, min, max), which count the number of elements in this range (exclude) */
int get_ntil(t_lnk *lst, int min, int max)
{
    t_lnk *tmp;
    int count;

    tmp = lst;
    count = 0;
    while (tmp != lst)
    {
        if (tmp->rank > min && tmp->rank < max)
            count++;
        tmp = tmp->next;
    }
    return (count);
}