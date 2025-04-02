/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_comb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:41:34 by nidionis          #+#    #+#             */
/*   Updated: 2025/04/02 22:04:16 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_best_comb(t_data *d, int *instr_ls, int (*can_push)(t_data *),
		int max_cost)
{
	t_list		*best_comb_in_dir;
	t_list		*best_comb;
	int			i_instr;

	d->r_instr = instr_ls;
	i_instr = 0;
	best_comb = NULL;
	while (instr_ls[i_instr] != LOOP_END)
	{
		best_comb_in_dir = best_insert_dir(d, instr_ls[i_instr], can_push,
				max_cost);
		if (ft_cost(best_comb_in_dir) < ft_cost(best_comb))
		{
			if (best_comb)
				ft_lstclear(&best_comb, free);
			best_comb = best_comb_in_dir;
		}
		else
			ft_lstclear(&best_comb_in_dir, free);
		i_instr++;
	}
	return (best_comb);
}
