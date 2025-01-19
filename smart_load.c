/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/01/19 01:31:09 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	special_item(t_lnk *lst_a, int max)
{
	if (lst_a->rank == 0 || lst_a->rank == max || lst_a->rank == max / 2)
		return (1);
	return (0);
}

void	load_b(t_lnk **lst_a, t_lnk **lst_b, int max)
{
	//int	i;

	while (!is_sorted(*lst_a))
	{
		if (special_item(*lst_a, max))
			apply_instr(ra, lst_a, lst_b, 1);
		else
		{
			//reach_load_ncile(lst_a, lst_b, max_ncile);
			return ;
		}
	}
}
