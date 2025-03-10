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
 * @return int Number of operations performed or CANT_INSERT_ERROR if not possible
 */
int	apply_best_comb_operation(t_data *data, t_comb_operation *comb_op)
{
	t_list	*best_steps;
	int		nb_instr;

	/* Validate input parameters */
	if (!data || !comb_op)
	{
		fprintf(stderr, "[apply_best_comb_operation] Error: NULL data or operation\n");
		return (CANT_INSERT_ERROR);
	}

	/* Ensure the can_fn function is set */
	if (!comb_op->can_fn)
	{
		fprintf(stderr, "[apply_best_comb_operation] Error: NULL can_fn function\n");
		return (CANT_INSERT_ERROR);
	}

	nb_instr = 0;
	/* Get the best instruction combination */
	best_steps = ft_best_comb(data, comb_op->instr_list, 
		comb_op->can_fn, comb_op->max_cost);

	/* Apply the best steps if found */
	if (best_steps)
		nb_instr = apply_best_comb_and(comb_op->f_do, data, best_steps, comb_op->verbose);

	/* Clean up memory */
	ft_lstclear(&best_steps, free);
	return (nb_instr);
}
