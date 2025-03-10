/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:49:48 by nidionis          #+#    #+#             */
/*   Updated: 2025/02/09 16:33:19 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/**
 * @brief Forward declaration of best_insert_dir to use it in best_insert
 */
t_list *best_insert_dir(t_data *d, int instr, int (*can_push)(t_data *), int max_cost);

/**
 * @brief Finds the best instruction to reach a given state
 * 
 * @param d Data structure containing the lists
 * @param lst_instr Array of possible instructions
 * @param can_push Function verifying if the state is reached
 * @param max_cost Maximum acceptable cost
 * @return t_list* Node containing the instruction and its cost
 */
t_list	*best_insert(t_data *d, int lst_instr[], int (*can_push)(t_data *), int max_cost)
{
	t_data *d_copy;
	t_instr_step *instr_step;
	t_list *instr_step_node;
	t_list *best_dir_result;
	
	/* Validate pointers first */
	if (!d || !lst_instr || !can_push)
	{
		fprintf(stderr, "[best_insert] Error: NULL pointer received\n");
		return NULL;
	}
	
	/* If cost is 0, break any further checks */
	if (max_cost == 0)
		return NULL;

	/* Ensure max_cost is at least a reasonable minimum value */
	if (max_cost < MAX_INSTRUCTION && max_cost != 0)
	{
		max_cost = MAX_INSTRUCTION; /* Use constant for max instruction count */
	}
	
	/* Allocate memory for the data copy */
	d_copy = (t_data *)malloc(sizeof(t_data));
	if (!d_copy)
	{
		fprintf(stderr, "[best_insert] Error: Failed to allocate memory for data copy\n");
		return NULL;
	}
	
	/* Create a copy of the data to avoid modifying the original */
	ft_memset(d_copy, 0, sizeof(t_data)); /* Initialize to zeros first */
	ft_memcpy(d_copy, d, sizeof(t_data));
	
	/* If the condition is already met, return an empty instruction */
	if (can_push(d_copy))
	{
		instr_step = malloc(sizeof(t_instr_step));
		if (!instr_step)
		{
			free(d_copy);
			return (NULL);
		}
		instr_step->instr = lst_instr[0];
		instr_step->nb_instr = 0;
		instr_step_node = ft_lstnew(instr_step);
		free(d_copy); /* Free memory before returning */
		return instr_step_node;
	}
	
	/* Use best_insert_dir instead of recursive approach */
	best_dir_result = NULL;
	
	/* Try each instruction in the list */
	int i = 0;
	while (lst_instr[i] != LOOP_END && lst_instr[i] != 0)
	{
		/* Use best_insert_dir for this instruction */
		best_dir_result = best_insert_dir(d_copy, lst_instr[i], can_push, max_cost);
		
		/* If we found a valid result, convert it to instr_step format */
		if (best_dir_result)
		{
			/* Extract info from best_dir_result */
			t_instr_step *dir_instr_step = (t_instr_step *)best_dir_result->content;
			
			/* Create new instr_step with the found instruction */
			instr_step = malloc(sizeof(t_instr_step));
			if (!instr_step)
			{
				ft_lstclear(&best_dir_result, free);
				free(d_copy);
				return NULL;
			}
			
			/* Copy the instruction and steps */
			instr_step->instr = lst_instr[i];
			instr_step->nb_instr = dir_instr_step->nb_instr;
			
			/* Clean up the best_dir_result */
			ft_lstclear(&best_dir_result, free);
			
			/* Create a new node for the result */
			instr_step_node = ft_lstnew(instr_step);
			free(d_copy); /* Free memory before returning */
			return instr_step_node;
		}
		
		i++;
	}
	
	/* If we couldn't find a valid instruction, use NO_MOVE */
	instr_step = malloc(sizeof(t_instr_step));
	if (!instr_step)
	{
		free(d_copy);
		return NULL;
	}
	
	instr_step->instr = NO_MOVE;
	instr_step->nb_instr = SIZE_MAX; /* Use max value to indicate no valid instruction found */
	
	instr_step_node = ft_lstnew(instr_step);
	free(d_copy); /* Free memory before returning */
	return instr_step_node;
}

/**
 * @brief Gets the number of steps in an instruction node
 * 
 * @param instr_step_node Instruction node
 * @return int Number of steps
 */
int get_steps(t_list *instr_step_node)
{
	t_instr_step *instr_step;

	if (!instr_step_node)
		return (SIZE_MAX);
	instr_step = (t_instr_step *)instr_step_node->content;
	if (!instr_step)
		return (SIZE_MAX);
	return (instr_step->nb_instr);
}

/**
 * @brief Initializes a new instruction node
 * 
 * @param instr Instruction code
 * @param nb_instr_init Initial number of instructions
 * @return t_list* Created node
 */
t_list	*init_instr_step_node(int instr, int nb_instr_init)
{
	t_instr_step	*instr_step;
	t_list			*instr_step_node;

	instr_step = malloc(sizeof(t_instr_step));
	if (!instr_step)
		return (NULL);
	instr_step->instr = instr;
	instr_step->nb_instr = nb_instr_init;
	instr_step_node = ft_lstnew(instr_step);
	if (!instr_step_node)
	{
		free(instr_step);
		return (NULL);
	}
	return (instr_step_node);
}
