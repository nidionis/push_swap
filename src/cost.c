/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 01:38:58 by nidionis          #+#    #+#             */
/*   Updated: 2025/02/03 01:39:12 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	ft_cost(t_list *best_comb)
{
	int	cost;
	t_instr_step *instr_step;

	cost = 0;
	if (best_comb)
		while (best_comb)
		{
			instr_step = best_comb->content;
			if (instr_step->instr == NO_INSTR)
				break ;
			if (instr_step->nb_instr == CANT_INSERT)
				return (SIZE_MAX);
			cost += instr_step->nb_instr;
			best_comb = best_comb->next;
		}
	return (cost);
}