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
    t_lst *a;
    t_lst *b;

    a = &data->a;
    b = &data->b;
	if (b->size > 2)
		if (a->lst->rank == data->rank_max && b->lst->prev->rank == b->min)
			return (TRUE);
	if (a->lst->rank > data->rank_max / 2)
		return (FALSE);
	return (can_load_b(data));
}

int	can_load_high(t_data *data)
{
    t_lst *a;

    a = &data->a;
	if (a->lst->rank < a->pivot)
		return (FALSE);
	if (a->lst->rank >= a->softmax)
		return (FALSE);
	return (can_load_b(data));
}

int	can_insert_at_max_b(t_data *data)
{
	t_lst *a;
	t_lst *b;

	a = &data->a;
	b = &data->b;
	if (a->lst->rank > b->max || a->lst->rank < b->min)
		return (TRUE);
	return (FALSE);
}

int	can_insert_to_b_between(t_data *data)
{
	t_lst *a;
	t_lst *b;

	a = &data->a;
	b = &data->b;
	return (a->lst->rank > b->lst->rank && a->lst->rank < b->lst->prev->rank);
}

int	can_insert_at_min_b(t_data *data)
{
	t_lst *a;
	t_lst *b;

	a = &data->a;
	b = &data->b;
	return (a->lst->rank < b->min || a->lst->rank > b->max);
}

int	can_load_b(t_data *data)
{
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
	if (size_b == 2)
	{
		if (b->lst->rank == b->max)
		{
			if (a->lst->rank > b->max || a->lst->rank < b->min)
				return (TRUE);
		}
		else if (b->lst->rank == b->min)
		{
			if (a->lst->rank < b->min || a->lst->rank > b->max)
				return (TRUE);
		}
		else
			return (can_insert_to_b_between(data));
	}
	else
	{
		if (b->lst->rank == b->max)
		{
		 	if (can_insert_at_max_b(data))
				return (TRUE);
		}
		else if (b->lst->rank == b->min)
		{
			if (b->lst->next->rank != b->max)
				return (a->lst->rank < b->min);
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
    t_lst *a;
    t_lst *b;

    a = &data->a;
    b = &data->b;
	if (!a)
		return (TRUE);
	if (!b)
		return (FALSE);
	if (a->lst->rank == a->softmax && b->lst->rank == a->softmax - 1)
		return (TRUE);
	if (a->lst->prev->rank == a->softmin && b->lst->rank == a->softmin + 1)
		return (TRUE);
	return (FALSE);
}
