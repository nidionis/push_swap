/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_or_dump_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:42:47 by nidionis          #+#    #+#             */
/*   Updated: 2025/03/09 15:42:47 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/**
 * @brief Tests and applies either load_b or dump_b operation, choosing the best
 * 
 * This function duplicates the data structure to test both load_b (pushing from
 * A to B) and dump_b (pushing from B to A) operations separately, and then 
 * applies the operation that requires fewer instructions. The original data
 * remains unchanged until the best operation is determined.
 * 
 * @param data Structure containing stacks and state
 * @param verbose Flag to control output verbosity
 * @return int Number of operations performed or CANT_INSERT if neither is possible
 */
/**
 * @brief Safely try either load or dump operation, choosing the better one
 * 
 * @param data Original data structure
 * @param verbose Verbosity flag
 * @return int Result code from the chosen operation
 */
int	load_or_dump_b(t_data *data, int verbose)
{
	t_comb_operation	load_op;
	t_comb_operation	dump_op;
	int				result;
	t_data			data_copy;
	
	ft_memcpy(&data_copy, data, sizeof(t_data));
	load_op = init_comb_operation(data->r_instr, &can_load_b_but_softminmax, NULL, QUIET);
	dump_op = init_comb_operation(data->r_instr, &can_dump_b, NULL, QUIET);
	if (apply_best_comb_operation(&data_copy, &load_op) < apply_best_comb_operation(&data_copy, &dump_op))
	{
		load_op.verbose = verbose;
		result = apply_best_comb_operation(data, &load_op);
	}
	else
	{
		dump_op.verbose = verbose;
		result = apply_best_comb_operation(data, &dump_op);
	}
	return (result);
}
