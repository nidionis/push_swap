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
		if (a->rank == data->rank_max && b->prev->rank == data->min_b)
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
	if (a->rank < data->mediane_a)
		return (FALSE);
	if (a->rank >= data->softmax_a)
		return (FALSE);
	return (can_load_b(data));
}

int	can_insert_at_max_b(t_data *data)
{
	t_lnk *a;

	a = data->lst_a;
	if (a->rank > data->max_b || a->rank < data->min_b)
		return (TRUE);
	return (FALSE);
}

int	can_insert_between(t_data *data)
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
			return (can_insert_between(data));
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
				return (can_insert_between(data));
		}
		else if (can_insert_between(data))
			return (TRUE);
	}
	return (FALSE);
}

//int	can_load_b(t_data *data)
//{

//    t_lnk *a;
//    t_lnk *b;
//	int	size_b;
//
//    a = data->lst_a;
//    b = data->lst_b;
//	if (!a)
//		return (FALSE);
//	if (!b)
//		return (TRUE);
//	size_b = ft_dlstsize(b);
//	if (size_b == 1)
//		return (TRUE);
//	if (size_b == 2)
//	{
//		if (b->rank == data->max_b)
//		{
//			if (a->rank > data->max_b || a->rank < data->min_b)
//				return (TRUE);
//		}
//		else if (a->rank > b->rank && b->prev->rank > a->rank)
//			return (TRUE);
//	}
//	else
//	{
//		if (b->rank == data->max_b)
//		{
//			if (a->rank > data->max_b)
//				return (TRUE);
//			if (a->rank < data->min_b)
//				return (TRUE);
//		}
//		else if (b->prev->rank == data->min_b)
//		{
//			if (a->rank < data->min_b)
//				return (TRUE);
//			if (a->rank > data->max_b)
//				return (TRUE);
//		}
//		else if (a->rank > b->rank && a->rank < b->prev->rank)
//			return (TRUE);
//	}
//	return (FALSE);
//}

int	can_dump(t_data *data)
{
    t_lnk *a;
    t_lnk *b;

    a = data->lst_a;
    b = data->lst_b;
	if (!a)
		return (TRUE);
	if (!b)
		return (FALSE);
	if (a->rank == data->softmax_a && b->rank == data->softmax_a - 1)
		return (TRUE);
	if (a->prev->rank == data->softmin_a && b->rank == data->softmin_a + 1)
		return (TRUE);
	return (FALSE);
}