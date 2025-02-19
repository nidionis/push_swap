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

	b = data->lst_b;
	if (b->rank < data->max_a || b->rank > data->min_a)
		return (TRUE);
	return (FALSE);
}

int	can_insert_to_b_between(t_data *data)
{
	t_lnk *a;
	t_lnk *b;

	a = data->lst_a;
	b = data->lst_b;
	return (b->rank > a->rank && a->rank < b->prev->rank);
}

int	can_insert_at_min_b(t_data *data)
{
	t_lnk *a;

	a = data->lst_a;
	return (a->rank < data->min_b || a->rank > data->max_b);
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
		if (lst_b->rank == data->max_b)
		{
			if (lst_a->rank > data->max_b || lst_a->rank < data->min_b)
				return (TRUE);
		}
		else
			return (can_insert_to_b_between(data));
	}
	else
	{
		if (lst_b->rank == data->max_b)
		{
		 	if (can_insert_at_max_b(data))
				return (TRUE);
		}
		else if (lst_b->rank == data->min_b)
		{
			if (lst_b->next->rank != data->max_b)
				return (lst_a->rank < data->min_b);
			else
				return (can_insert_to_b_between(data));
		}
		else if (can_insert_to_b_between(data))
			return (TRUE);
	}
	return (FALSE);
}
*/