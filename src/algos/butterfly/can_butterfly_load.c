/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/02/09 16:30:59 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	can_butterfly_load(t_data *data)
{
    int mediane;
    t_lnk *a;
    t_lnk *b;
    static set_on_high;

    a = data->lst_a;
    b = data->lst_b;
	if (a->rank < data->min_to_load || a->rank > data->max_to_load)
		return (FALSE);
    if (ft_dlstsize(b) < 5)
        return (can_load_b(data));
    mediane = (data->max_to_load - data->min_to_load) / 2 + data->min_to_load;

	return (can_load_b(data));
}