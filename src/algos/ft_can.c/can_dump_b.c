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

/*
int	can_insert_at_max_a(t_data *data)
{
	t_lnk *b;

	b = data->b.lst;
	if (b->rank < data->a.max || b->rank > data->a.min)
		return (TRUE);
	return (FALSE);
}

int	can_insert_to_b_between(t_data *data)
{
	t_lnk *a;
	t_lnk *b;

	a = data->a.lst;
	b = data->b.lst;
	return (b->rank > a->rank && a->rank < b->prev->rank);
}

int	can_insert_at_min_b(t_data *data)
{
	t_lnk *a;

	a = data->a.lst;
	return (a->rank < data->b.min || a->rank > data->b.max);
}

int	can_load_b(t_data *data)
{
	t_lnk *lst_a = data->a.lst;
	t_lnk *lst_b = data->b.lst;

	if (!lst_a)
		return (FALSE);
	if (!lst_b)
		return (TRUE);
	if (data->b.size == 1)
		return (TRUE);
	if (data->b.size == 2)
	{
		if (lst_b->rank == data->b.max)
		{
			if (lst_a->rank > data->b.max || lst_a->rank < data->b.min)
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
		else if (lst_b->rank == data->b.min)
		{
			if (lst_b->next->rank != data->b.max)
				return (lst_a->rank < data->b.min);
			else
				return (can_insert_to_b_between(data));
		}
		else if (can_insert_to_b_between(data))
			return (TRUE);
	}
	return (FALSE);
}
*/