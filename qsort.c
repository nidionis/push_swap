/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/21 19:58:14 by supersko         ###   ########.fr       */
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

	ind_lst = lst;
	last = lst;
	apply_instr(instr_way, &ind_lst, NULL, 0);
	while (lst->rank <= relMinMax[1] && lst->rank >= relMinMax[0] && ind_lst != lst)
	{
		if ((ind_lst)->rank < pivot)
		{
			last = ind_lst;
		}
		apply_instr(instr_way, &ind_lst, NULL, 0);
	}
	return (last);
}

//for each (unsorted) partition
//
//set first element as pivot
//
//  storeIndex = pivotIndex+1
//
//  for i = pivotIndex+1 to rightmostIndex
//
//    if ((a[i] < a[pivot]) or (equal but 50% lucky))
//
//      swap(i, storeIndex); ++storeIndex
//
//  swap(pivot, storeIndex-1)

int median_split(t_lnk **lst, t_lnk **lst_loaded, int relMinMax)
{
	int	pivot;

	pivot = (relMinMax[1] - relMinMax[0] / 2;
	while (*lst != last_higher(*lst, pivot, ra, relMinMax))
	{
		if ((*lst)->rank < pivot)
		{
			apply_instr(pb, lst, lst_loaded, 1);
		}
		apply_instr(ra, lst, lst_loaded, 1);
	}
}

void rec_median_split(t_lnk **lst, t_lnk **lst_loaded, int pivot, t_lnk **relMinMax)
{
	int	pivot;

	pivot = (relMinMax[1] - relMinMax[0] / 2;
	relMinMax[1] = pivot + relMinMax[0];
	median_split(lst, lst_loaded, relMinMax);
}