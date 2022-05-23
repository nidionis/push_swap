/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/22 00:05:01 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_lnk	*last_lower(t_lnk	*lst, int instr_way, int relMinMax[2])
{
	t_lnk	*pivot;
	t_lnk	*last;

		pivot = lst;
		last = lst;
		while (lst->rank <= relMinMax[1] && lst->rank >= relMinMax[0])
	{
		if (lst->rank < pivot->rank)
		{
			last = lst;
			apply_instr(instr_way, &lst, NULL, 0);
		}
	}
	return (last);
}

t_lnk	*last_higher(t_lnk	*lst, int pivot, int instr_way, int *relMinMax)
{
	t_lnk	*ind_lst;
	t_lnk	*last;

	last = lst;
	if (lst)
	{
		ind_lst = lst;
		apply_instr(instr_way, &ind_lst, NULL, 0);
		while (lst->rank <= relMinMax[1] && lst->rank >= relMinMax[0] && ind_lst != lst)
		{
			if ((ind_lst)->rank < pivot)
			{
				last = ind_lst;
			}
			apply_instr(instr_way, &ind_lst, NULL, 0);
		}
	}
	return (last);
}

int last_to_push(t_lnk *lst_a, t_lnk *lst_b, int pivot, int inst_way, int relMinMax[2])
{
	t_lnk 	*ind;
	int		is_last;

	is_last = 1;
	ind = lst_b;
	if (inst_way == ra)
		ind = lst_a;
	while ((ind)->rank <= relMinMax[1] && (ind)->rank >= relMinMax[0])
	{
		apply_instr(inst_way, &ind, NULL, 0);
		if ((ind)->rank <= relMinMax[1] && (ind)->rank >= relMinMax[0])
		{
			if (ind->rank <= pivot)
			{
				is_last = 0;
				break;
			}
			if (ind == lst_a || ind == lst_b)
				break;
		}
	}
	return (is_last);
}

int median_split(t_lnk **lst_a, t_lnk **lst_b, int *relMinMax, int is_lst_b)
{
	int		pivot;
	int		lst_instr[2];

	pivot = (relMinMax[1] - relMinMax[0]) / 2;
	lst_instr[0] = ra;
	lst_instr[1] = pb;
	if (is_lst_b)
	{
		lst_instr[0] = rb;
		lst_instr[1] = pa;
	}
	while ((*lst_a)->rank <= relMinMax[1] && (*lst_a)->rank >= relMinMax[0])
	{
		if ((*lst_a)->rank <= pivot && (*lst_a)->rank >= relMinMax[0])
		{
			apply_instr(lst_instr[1], lst_a, lst_b, 1);
		}
		else if (!last_to_push(*lst_a, *lst_b, pivot, lst_instr[0], relMinMax))
		{
			apply_instr(lst_instr[0], lst_a, lst_b, 1);
		}
	}
	apply_instr(lst_instr[1], lst_a, lst_b, 1);
	return (0);
}

int stop_rec(int *relMinMax)
{
	if (relMinMax[0] == relMinMax[1] || relMinMax[0] == relMinMax[1] - 1)
		return (1);
	return (0);
}

void rec_median_split(t_lnk **lst_a, t_lnk **lst_b, int *relMinMax, int is_lst_b)
{
	int	tmp;
	int	pivot;
	int	lst_instr[2];

	lst_instr[0] = ra;
	lst_instr[1] = pb;
	if (is_lst_b)
	{
		lst_instr[0] = rb;
		lst_instr[1] = pa;
	}
	if (stop_rec(relMinMax))
	{
		if (is_lst_b)
		{
			if (relMinMax[1] == relMinMax[0] + 1)
				apply_instr(lst_instr[1], lst_b, lst_a, 1);
			apply_instr(lst_instr[1], lst_b, lst_a, 1);
		}
		if ((*lst_b)->rank > (*lst_b)->next->rank)
			apply_instr(lst_instr[0], lst_b, lst_a, 1);
	}
	else
	{ 
		median_split(lst_a, lst_b, relMinMax, is_lst_b);
		pivot = (relMinMax[1] - relMinMax[0]) / 2;
		tmp = relMinMax[1];
		relMinMax[1] = pivot;
		rec_median_split(lst_a, lst_b, relMinMax, !is_lst_b);
		relMinMax[0] = pivot + 1;
		relMinMax[1] = tmp;
		rec_median_split(lst_a, lst_b, relMinMax, !is_lst_b);
	}
}