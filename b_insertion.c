/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_insertion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:47:42 by supersko          #+#    #+#             */
/*   Updated: 2022/05/21 16:36:21 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>


int	can_insert(t_lnk *lst_a, t_lnk *lst_b, t_lnk *brelMax)
{
	if (!lst_b || lst_b == lst_b->next)
		return (1);
	if (lst_a->rank > lst_b->rank)
	{
		if (lst_a->rank < lst_b->prev->rank || lst_b == brelMax)
			return (1);
	}
	if (lst_b == brelMax && lst_a->rank < lst_b->prev->rank)
		return (1);
	return (0);
}

int	b_insert(t_lnk **lst_a, t_lnk **lst_b, t_lnk *brelMax, int print)
{
	int	way;
	int	steps;
	t_lnk **lst_b_cpy;
	t_lnk *first_item;

	steps = 0;
	lst_b_cpy = lst_b;	
	way = rb;
	first_item = *lst_b;
	if ((*lst_a)->rank > (*lst_b)->rank)
		way = rrb;
	while (!can_insert(*lst_a, *lst_b_cpy, brelMax))
	{
		if (*lst_b_cpy == first_item && steps != 0)
			break;
		apply_instr(way, lst_a, lst_b_cpy, print);
		steps += 1;
	}
	if (print)
	{
		*lst_b = *lst_b_cpy;
		apply_instr(pb, lst_a, lst_b_cpy, print);
	}
	return (steps);
}

static int	lstMin(int min_step[], int len)
{
	int min_ind;
	int min;
	int i;

	i = 1;
	min = min_step[0];
	min_ind = 0;
	while (i < len)
	{
		if (min_step[i] < min)
		{
			min = min_step[i];
			min_ind = i;
		}
		i++;
	}
	return (min_ind);
}

t_lnk	*smart_load_loop(t_lnk **lst_a, t_lnk **lst_b, int way_instr, int nb_raMax, t_lnk *brelMax)
{
	int		i;
	int		min_steps[nb_raMax];
	t_lnk	*lst_b_cpy;
	t_lnk	*lst_a_cpy;

	i = 0;
	lst_b_cpy = *lst_b;
	lst_a_cpy = *lst_a;
	while (i < nb_raMax) // arbitraire
	{
		min_steps[i] = b_insert(&lst_a_cpy, &lst_b_cpy, brelMax, 0);
		apply_instr(way_instr , &lst_a_cpy, NULL, 0);
		i++;
	}
	i = lstMin(min_steps, nb_raMax);
	while (i--)
		apply_instr(way_instr , lst_a, lst_b, 1);	
	b_insert(lst_a, lst_b, brelMax, 1);
	return (brelMax);
}