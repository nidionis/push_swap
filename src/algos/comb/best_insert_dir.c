/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_insert_dir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/03/09 22:08:21 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <limits.h>

/* Forward declarations for helper functions */
static t_list *handle_best_comb_iterative(t_list **best_comb, t_list *instr_step_node, 
                                     int instr, int nb_instr);
static void handle_no_best_comb(t_list *first_intr_step_node, t_data *d_copy, int instr);
static void best_insert_loop(t_data *d_copy, int instr, int (*can_push)(t_data *), 
                        int *max_cost, t_list **best_comb);

/**
 * @brief Met à jour la meilleure combinaison trouvée (original version)
 *
 * @param best Structure contenant la meilleure combinaison et son coût
 * @param instr_step_node Nœud contenant l'instruction et son coût
 * @param instr Code de l'instruction
 * @param nb_instr Nombre d'instructions
 * @return t_list* La meilleure combinaison mise à jour
 */
t_list *handle_best_comb(t_best_comb *best, t_list *instr_step_node, int instr, int nb_instr)
{
	t_list *saved_first_instr;
	
	/* Libérer l'ancienne meilleure combinaison si elle existe */
	if (best->best_comb)
		ft_lstclear(&best->best_comb, free);
		
	/* Mettre à jour la meilleure combinaison */
	best->best_comb = instr_step_node;
	
	/* Ajouter l'instruction initiale avec son nombre d'exécutions */
	saved_first_instr = init_instr_step_node(instr, nb_instr);
	ft_lstadd_front(&best->best_comb, saved_first_instr);
	
	/* Mettre à jour le coût maximum */
	best->max_cost = ft_cost(best->best_comb);
	return (best->best_comb);
}

/**
 * @brief Gère le cas où une meilleure combinaison n'a pas été trouvée
 *
 * @param d_copy Copie des données
 * @param first_intr_step Première instruction
 * @param instr Code de l'instruction
 * @param instr_step_node Nœud à libérer
 */
void handle_else_case(t_data *d_copy, t_instr_step *first_intr_step, int instr, t_list *instr_step_node)
{
	/* Incrémenter le nombre d'instructions */
	first_intr_step->nb_instr++;
	
	/* Appliquer l'instruction */
	apply_instr(d_copy, instr, QUIET);
	
	/* Libérer le nœud */
	ft_lstclear(&instr_step_node, free);
}

/**
 * @brief Vérifie si la combinaison actuelle est meilleure que la meilleure connue
 *
 * @param best Structure contenant la meilleure combinaison et son coût
 * @param instr_step_node Nœud contenant l'instruction et son coût
 * @param nb_first_instr Nombre d'instructions de la première partie
 * @return int Vrai si la combinaison actuelle est meilleure
 */
int should_update(t_best_comb *best, t_list *instr_step_node, int nb_first_instr)
{
	return (nb_first_instr + get_steps(instr_step_node) < best->max_cost);
}
/* The recursive implementation has been completely removed in favor of the iterative approach */

/**
 * @brief Trouve la meilleure direction d'insertion
 *
 * @param d Structure de données contenant les listes
 * @param instr Code de l'instruction à appliquer
 * @param can_push Fonction vérifiant si l'état est atteint
 * @param max_cost Coût maximum acceptable
 * @return t_list* La meilleure combinaison trouvée
 */
t_list *best_insert_dir(t_data *d, int instr, int (*can_push)(t_data *), int max_cost)
{
	t_data d_copy;
	t_list *best_comb = NULL;

	/* Validate pointers first */
	if (!d || !can_push)
	{
		fprintf(stderr, "[best_insert_dir] Error: NULL pointer received\n");
		return NULL;
	}

	/* If cost is 0, break any further checks */
	if (max_cost == 0)
		return NULL;

	/* Always ensure max_cost is reasonable (at least MAX_INSTRUCTION) to avoid excessive warnings */
	if (max_cost < MAX_INSTRUCTION)
	{
		/* Only log a warning if max_cost is really small */
		if (max_cost <= 1) 
			fprintf(stderr, "[best_insert_dir] Warning: max_cost too small (%d), using default\n", max_cost);
		max_cost = MAX_INSTRUCTION; /* Set to the maximum instruction count */
	}

	/* Safely copy the data structure */
	ft_memset(&d_copy, 0, sizeof(t_data)); /* Initialize to zeros first */
	ft_memcpy(&d_copy, d, sizeof(t_data));
	
	/* Use the iterative approach instead of recursive */
	best_insert_loop(&d_copy, instr, can_push, &max_cost, &best_comb);
	
	return best_comb;
}


/**
 * Updates the best combination by clearing the old one and setting up the new one
 */
static t_list *handle_best_comb_iterative(t_list **best_comb, t_list *instr_step_node, int instr, int nb_instr)
{
	t_list *saved_first_instr;
	if (*best_comb)
		ft_lstclear(best_comb, free);
	*best_comb = instr_step_node;
	saved_first_instr = init_instr_step_node(instr, nb_instr);
	ft_lstadd_front(best_comb, saved_first_instr);
	return (*best_comb);
}

/**
 * Handles the case when no better combination is found
 */
static void handle_no_best_comb(t_list *first_intr_step_node, t_data *d_copy, int instr)
{
	t_instr_step *first_intr_step;
	
	/* Check for null pointers */
	if (!first_intr_step_node || !d_copy)
	{
		fprintf(stderr, "[handle_no_best_comb] Error: NULL pointer received\n");
		return;
	}
	
	first_intr_step = first_intr_step_node->content;
	if (!first_intr_step)
	{
		fprintf(stderr, "[handle_no_best_comb] Error: NULL first_intr_step content\n");
		return;
	}
	
	first_intr_step->nb_instr++;
	apply_instr(d_copy, instr, QUIET);
}

/**
 * Iterative implementation for finding the best insertion direction
 */
static void best_insert_loop(t_data *d_copy, int instr, int (*can_push)(t_data *), 
                         int *max_cost, t_list **best_comb)
{
	t_list *first_intr_step_node;
	t_instr_step *first_intr_step;
	int iterations = 0;
	const int MAX_ITERATIONS = 100; /* Set a maximum to prevent infinite loops */
	
	/* Check for NULL pointers */
	if (!d_copy || !can_push || !max_cost || !best_comb)
	{
		fprintf(stderr, "[best_insert_loop] Error: NULL pointer received\n");
		return;
	}
	
	/* Initialize the first instruction step */
	first_intr_step_node = init_instr_step_node(instr, 0);
	if (!first_intr_step_node)
	{
		fprintf(stderr, "[best_insert_loop] Error: Failed to initialize first instruction node\n");
		return;
	}
	
	first_intr_step = first_intr_step_node->content;
	if (!first_intr_step)
	{
		fprintf(stderr, "[best_insert_loop] Error: First instruction node has NULL content\n");
		ft_lstdelone(first_intr_step_node, free);
		return;
	}
	
	/* If cost is 0, break any further checks */
	if (*max_cost == 0)
	{
		ft_lstdelone(first_intr_step_node, free);
		return;
	}

	/* Ensure max_cost is at least a reasonable minimum value */
	if (*max_cost < MAX_INSTRUCTION)
	{
		*max_cost = MAX_INSTRUCTION; /* Set to maximum instruction count */
		/* Only log if the value was very small */
		if (*max_cost <= 1)
			fprintf(stderr, "[best_insert_loop] Setting minimum max_cost to %d\n", *max_cost);
	}
	
	while (first_intr_step->nb_instr < *max_cost && iterations < MAX_ITERATIONS)
	{
		iterations++;
		t_list *instr_step_node = best_insert(d_copy, d_copy->r_instr, can_push, *max_cost - first_intr_step->nb_instr);
		
		/* If we have a valid step node and it's better than current max cost */
		if (instr_step_node && first_intr_step->nb_instr + get_steps(instr_step_node) < *max_cost - 1)
		{
			*best_comb = handle_best_comb_iterative(best_comb, instr_step_node, instr, first_intr_step->nb_instr);
			*max_cost = ft_cost(*best_comb);
			break; /* Exit loop once we've found a good combination */
		}
		else
		{
			/* Apply the instruction and continue searching */
			handle_no_best_comb(first_intr_step_node, d_copy, instr);
			
			/* Clean up if step node exists but wasn't used */
			if (instr_step_node)
				ft_lstclear(&instr_step_node, free);
			
			/* Exit if we've reached max_cost operations or can't push anymore */
			if (first_intr_step->nb_instr >= *max_cost || !can_push(d_copy))
				break;
		}
	}
	
	/* If we hit max iterations without finding a solution, log a warning */
	if (iterations >= MAX_ITERATIONS)
		fprintf(stderr, "[best_insert_loop] Warning: Reached max iterations (%d)\n", MAX_ITERATIONS);
	
	ft_lstdelone(first_intr_step_node, free); /* Use lstdelone instead of lstclear */
}