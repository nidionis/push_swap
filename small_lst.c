/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/01/29 02:32:39 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	is_median(int max)
{
	if (d.lst_a->rank != 0 && d.lst_a->rank != max)
		return (1);
	return (0);
}

void	sort_2_nb()
{
	if ((d.lst_a)->rank > (d.lst_a)->next->rank)
		apply_instr(&d, &d.lst_a, &d.lst_b, sa, 1);
}

void	sort_3_nb(int max)
{
	if ((d.lst_a)->rank != 0)
	{
		if (is_median(max))
		{
			apply_instr(&d, &d.lst_a, &d.lst_b, sa, 1);
			apply_instr(&d, &d.lst_a, &d.lst_b, rra, 1);
		}
		else if (is_median(max))
			apply_instr(&d, &d.lst_a, &d.lst_b, ra, 1);
		else if ((d.lst_a)->prev->rank == max)
			apply_instr(&d, &d.lst_a, &d.lst_b, sa, 1);
		else
			apply_instr(&d, &d.lst_a, &d.lst_b, rra, 1);
	}
	else
	{
		if (!is_median(max))
		{
			apply_instr(&d, &d.lst_a, &d.lst_b, ra, 1);
			apply_instr(&d, &d.lst_a, &d.lst_b, sa, 1);
			apply_instr(&d, &d.lst_a, &d.lst_b, rra, 1);
		}
	}
}

void	sort_4_nb()
{
	int	i;

	i = 0;
	while (i++ < 4)
	{
		if ((d.lst_a)->rank > 1)
			apply_instr(&d, &d.lst_a, &d.lst_b, pb, 1);
		else
			apply_instr(&d, &d.lst_a, &d.lst_b, ra, 1);
	}
	if ((d.lst_a)->rank > (d.lst_a)->next->rank)
		apply_instr(&d, &d.lst_a, &d.lst_b, sa, 1);
	if ((d.lst_a)->rank < (d.lst_a)->next->rank)
		apply_instr(&d, &d.lst_a, &d.lst_b, sb, 1);
	apply_instr(&d, &d.lst_a, &d.lst_b, pa, 1);
	apply_instr(&d, &d.lst_a, &d.lst_b, pa, 1);
}

void	sort_5_nb()
{
	int	i;

	i = 0;
	while (i++ < 5)
	{
		if ((d.lst_a)->rank > 2)
			apply_instr(&d, &d.lst_a, &d.lst_b, pb, 1);
		else
			apply_instr(&d, &d.lst_a, &d.lst_b, ra, 1);
	}
	sort_3_nb(2);
	if ((d.lst_b)->rank < (d.lst_b)->next->rank)
		apply_instr(&d, &d.lst_a, &d.lst_b, sb, 1);
	apply_instr(&d, &d.lst_a, &d.lst_b, pa, 1);
	apply_instr(&d, &d.lst_a, &d.lst_b, pa, 1);
	apply_instr(&d, &d.lst_a, &d.lst_b, ra, 1);
	apply_instr(&d, &d.lst_a, &d.lst_b, ra, 1);
}
