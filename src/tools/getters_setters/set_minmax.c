/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:49:48 by nidionis          #+#    #+#             */
/*   Updated: 2025/04/02 19:44:11 by nidionis         ###   ########.fr       */
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

void	set_maxs(t_data *data, t_lnk *lst_a, t_lnk *lst_b)
{
	if (lst_a)
		data->a.max = get_max(lst_a)->rank;
	else
		data->a.max = UNSET;
	if (lst_b)
		data->b.max = get_max(lst_b)->rank;
	else
		data->b.max = UNSET;
}

void	set_mins(t_data *data, t_lnk *lst_a, t_lnk *lst_b)
{
	if (lst_a)
		data->a.min = get_min(lst_a)->rank;
	else
		data->a.min = UNSET;
	if (lst_b)
		data->b.min = get_min(lst_b)->rank;
	else
		data->b.min = UNSET;
}

void	set_minmax(t_data *data, t_lnk **lst_a, t_lnk **lst_b)
{
	if (!data || !lst_a || !lst_b)
		return ;
	data->a.lst = *lst_a;
	data->b.lst = *lst_b;
	set_maxs(data, *lst_a, *lst_b);
	set_mins(data, *lst_a, *lst_b);
}
