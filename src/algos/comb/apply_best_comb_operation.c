/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_best_comb_operation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:57:06 by nidionis          #+#    #+#             */
/*   Updated: 2025/03/09 14:57:06 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/**
 * @brief Apply the best combination operation, calculate and apply the best steps
 * 
 * @param data Structure of data containing stacks
 * @param comb_op Structure containing operation parameters
 * @return int Number of operations performed or CANT_INSERT if not possible
 */
int	apply_best_comb_operation(t_data *data, t_comb_operation *comb_op)
{
	t_list	*best_steps;
	int		nb_instr;

	nb_instr = 0;
	best_steps = ft_best_comb(data, comb_op->instr_list, 
		comb_op->can_fn, comb_op->max_cost);
	if (best_steps)
		nb_instr = apply_best_comb_and(comb_op->f_do, data, best_steps, comb_op->verbose);
	ft_lstclear(&best_steps, free);
	return (nb_instr);
}
