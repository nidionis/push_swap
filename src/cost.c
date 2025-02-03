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

int	ft_cost(int *best_comb)
{
	int	cost;

	cost = SIZE_MAX;
	if (best_comb[FIRST_INSTR] != NO_INSTR
		&& best_comb[FIRST_INSTR] != CANT_INSERT)
		cost = best_comb[NB_FIRST_INSTR];
	if (best_comb[SECOND_INSTR] != NO_INSTR
		&& best_comb[SECOND_INSTR] != CANT_INSERT)
		cost += best_comb[NB_SECOND_INSTR];
	return (cost);
}