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
	static int default_instr[7] = {rb, rr, rra, ra, rrb, rrr, LOOP_END};

	/* Provide a fallback instruction list if NULL is passed */
	if (!instr_list)
	{
		fprintf(stderr, "[init_comb_operation] Warning: NULL instruction list provided, using default\n");
		instr_list = default_instr;
	}

	/* Validate that the instruction list is properly terminated */
	int idx = 0;
	int valid = 0;
	while (idx < 100) /* Safety limit to prevent infinite loop */
	{
		if (instr_list[idx] == LOOP_END)
		{
			valid = 1;
			break;
		}
		idx++;
	}

	if (!valid)
	{
		fprintf(stderr, "[init_comb_operation] Warning: Instruction list not properly terminated with LOOP_END, using default\n");
		instr_list = default_instr;
	}

	comb_op.instr_list = instr_list;
	comb_op.can_fn = can_fn;
	comb_op.f_do = f_do;

	/* Use a reasonable max_cost - SIZE_MAX might cause integer overflow issues */
	comb_op.max_cost = 100; /* Reasonable default that should be sufficient for most operations */

	comb_op.verbose = verbose;
	return (comb_op);
}
