/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 21:16:34 by supersko          #+#    #+#             */
/*   Updated: 2025/04/02 19:22:15 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	data_update(t_data *data, t_lnk **lst_a, t_lnk **lst_b)
{
	if (!data)
		return ;
	set_minmax(data, lst_a, lst_b);
	data->a.size = ft_dlstsize(*lst_a);
	data->b.size = ft_dlstsize(*lst_b);
	set_softmax(data, *lst_a, *lst_b);
	set_softmin(data, *lst_a, *lst_b);
}

void	data_update_r(t_data *data, t_lnk **lst_a, t_lnk **lst_b)
{
	data->a.lst = *lst_a;
	data->b.lst = *lst_b;
}

void	init_data(t_data *data, t_lnk **lst_a, t_lnk **lst_b)
{
	if (lst_a && *lst_a)
	{
		data->rank_max = get_max(*lst_a)->rank;
		if (lst_b && *lst_b)
			if (data->rank_max < get_max(*lst_b)->rank)
				data->rank_max = get_max(*lst_b)->rank;
	}
	data->a.size = ft_dlstsize(*lst_a);
	data->b.size = ft_dlstsize(*lst_b);
	data_update(data, lst_a, lst_b);
}
