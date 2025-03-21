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

int	can_first_load(t_data *data)
{
    t_lnk *a;
    t_lnk *b;

    a = data->lst_a;
    b = data->lst_b;
	if (ft_dlstsize(b) > 2)
		if (a->rank == data->rank_max && b->prev->rank == b.min)
			return (TRUE);
	if (a->rank > data->rank_max / 2)
		return (FALSE);
	return (can_load_b(data));
}

int	can_load_high(t_data *data)
{
    t_lnk *a;
    t_lnk *b;

    a = data->lst_a;
    b = data->lst_b;
	if (a->rank < a.mediane)
		return (FALSE);
	if (a->rank >= a.softmax)
		return (FALSE);
	return (can_load_b(data));
}

int	can_insert_at_max_b(t_data *data)
{
	t_lnk *a;

	a = data->lst_a;
	if (a->rank > b.max || a->rank < b.min)
		return (TRUE);
	return (FALSE);
}

int	can_insert_to_b_between(t_data *data)
{
	t_lnk *a;
	t_lnk *b;

	a = data->lst_a;
	b = data->lst_b;
	return (a->rank > b->rank && a->rank < b->prev->rank);
}

int	can_insert_at_min_b(t_data *data)
{
	t_lnk *a;

	a = data->lst_a;
	return (a->rank < b.min || a->rank > b.max);
}

int	can_load_b(t_data *data)
{
	t_lnk *lst_a = data->lst_a;
	t_lnk *lst_b = data->lst_b;
	int size_b;

	if (!lst_a)
		return (FALSE);
	if (!lst_b)
		return (TRUE);
	size_b = ft_dlstsize(lst_b);
	if (size_b == 1)
		return (TRUE);
	if (size_b == 2)
	{
		if (lst_b->rank == b.max)
		{
			if (lst_a->rank > b.max || lst_a->rank < b.min)
				return (TRUE);
		}
		else
			return (can_insert_to_b_between(data));
	}
	else
	{
		if (lst_b->rank == data->b.max)
		{
		 	if (can_insert_at_max_b(data))
				return (TRUE);
		}
		else if (lst_b->rank == b.min)
		{
			if (lst_b->next->rank != b.max)
				return (lst_a->rank < b.min);
			else
				return (can_insert_to_b_between(data));
		}
		else if (can_insert_to_b_between(data))
			return (TRUE);
	}
	return (FALSE);
}

int	can_dump_b(t_data *data)
{
    t_lnk *a;
    t_lnk *b;

    a = data->lst_a;
    b = data->lst_b;
	if (!a)
		return (TRUE);
	if (!b)
		return (FALSE);
	if (a->rank == a.softmax && b->rank == a.softmax - 1)
		return (TRUE);
	if (a->prev->rank == a.softmin && b->rank == a.softmin + 1)
		return (TRUE);
	return (FALSE);
}
