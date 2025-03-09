/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_comb_operation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:17:15 by nidionis          #+#    #+#             */
/*   Updated: 2025/03/09 15:17:15 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/**
 * Initialize a t_comb_operation structure with the given parameters.
 * Sets max_cost to SIZE_MAX by default.
 * 
 * @param instr_list Array of instruction indices
 * @param can_fn Function to check if operation is possible
 * @param f_do Function to execute after each step or NULL
 * @param verbose Verbosity flag
 * @return Initialized t_comb_operation structure
 */
t_comb_operation	init_comb_operation(int *instr_list, int (*can_fn)(t_data *),
		int (*f_do)(t_data *, int), int verbose)
{
	t_comb_operation	comb_op;

	comb_op.instr_list = instr_list;
	comb_op.can_fn = can_fn;
	comb_op.f_do = f_do;
	comb_op.max_cost = SIZE_MAX;
	comb_op.verbose = verbose;
	return (comb_op);
}
