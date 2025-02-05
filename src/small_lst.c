/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/02/01 22:08:38 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
void	sort_2_nb()
{
	if ((d.lst_a)->rank > (d.lst_a)->next->rank)
		apply_instr(&d, sa, 1);
}

void	sort_3_nb(int max)
{
	if ((d.lst_a)->rank != 0)
	{
		if (is_median(max))
		{
			apply_instr(&d, sa, 1);
			apply_instr(&d, rra, 1);
		}
		else if (is_median(max))
			apply_instr(&d, ra, 1);
		else if ((d.lst_a)->prev->rank == max)
			apply_instr(&d, sa, 1);
		else
			apply_instr(&d, rra, 1);
	}
	else
	{
		if (!is_median(max))
		{
			apply_instr(&d, ra, 1);
			apply_instr(&d, sa, 1);
			apply_instr(&d, rra, 1);
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
			apply_instr(&d, pb, 1);
		else
			apply_instr(&d, ra, 1);
	}
	if ((d.lst_a)->rank > (d.lst_a)->next->rank)
		apply_instr(&d, sa, 1);
	if ((d.lst_a)->rank < (d.lst_a)->next->rank)
		apply_instr(&d, sb, 1);
	apply_instr(&d, pa, 1);
	apply_instr(&d, pa, 1);
}

void	sort_5_nb()
{
	int	i;

	i = 0;
	while (i++ < 5)
	{
		if ((d.lst_a)->rank > 2)
			apply_instr(&d, pb, 1);
		else
			apply_instr(&d, ra, 1);
	}
	sort_3_nb(2);
	if ((d.lst_b)->rank < (d.lst_b)->next->rank)
		apply_instr(&d, sb, 1);
	apply_instr(&d, pa, 1);
	apply_instr(&d, pa, 1);
	apply_instr(&d, ra, 1);
	apply_instr(&d, ra, 1);
}
*/