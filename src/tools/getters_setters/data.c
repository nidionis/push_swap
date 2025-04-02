/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 21:16:34 by supersko          #+#    #+#             */
/*   Updated: 2025/04/02 18:18:16 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	set_softmin(t_data *data, t_lnk *lst_a, t_lnk *lst_b)
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

void set_minmax(t_data *data, t_lnk **lst_a, t_lnk **lst_b)
{
    t_lnk *tmp;

    if (!data || !lst_a || !lst_b)
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
}

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
