/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/01/19 03:22:21 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/* 

premiere version franchement potable

int	special_item(t_lnk *lst_a, int max)
{
	if (lst_a->rank == 0 || lst_a->rank == max || lst_a->rank == max / 2)
		return (1);
	return (0);
}

void	load_b(t_lnk **lst_a, t_lnk **lst_b, int max)
{
	int	i;

	i = max + 1;
	while (i--)
	{
		if (special_item(*lst_a, max))
			apply_instr(ra, lst_a, lst_b, 1);
		else
		{
			if ((*lst_a)->rank > max / 2)
				apply_instr(pb, lst_a, lst_b, 1);
			else
			{
				apply_instr(pb, lst_a, lst_b, 1);
				apply_instr(rb, lst_a, lst_b, 1);
			}
		}
	}
	sort_3_nb(lst_a, max);
}
*/