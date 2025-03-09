/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/02/09 16:30:59 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <limits.h>

/**
 * @brief Met à jour la meilleure combinaison trouvée
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
/**
 * @brief Recherche récursivement la meilleure combinaison d'instructions
 *
 * @param d_copy Copie des données pour éviter de modifier l'originale
 * @param instr Code de l'instruction
 * @param can_push Fonction vérifiant si l'état est atteint
 * @param best Structure contenant la meilleure combinaison et son coût
 * @param nb_instr Nombre d'instructions appliquées (pour la récursion)
 * @return t_list* La meilleure combinaison trouvée
 */
static t_list *best_insert_dir_recursive(t_data *d_copy, int instr, 
                                        int (*can_push)(t_data *), 
                                        t_best_comb *best, 
                                        int nb_instr)
{
	t_list *instr_step_node;
	
	/* Cas de base: le nombre d'instructions dépasse déjà le coût maximum */
	if (nb_instr > best->max_cost)
		return (best->best_comb);
	
	/* If max_cost is COST_NOT_SET (0), return nb_instr to avoid infinite loop */
	if (best->max_cost == COST_NOT_SET)
		return ((t_list *)(size_t)nb_instr); /* Cast nb_instr to t_list pointer to return it */
		
	/* Rechercher la meilleure instruction suivante */
	instr_step_node = best_insert(d_copy, d_copy->r_instr, can_push, best->max_cost - nb_instr);
	
	/* Cas d'erreur */
	if (!instr_step_node)
	{
		ft_errmsg("[best_insert_dir_recursive] best_insert returned NULL");
		return (best->best_comb);
	}
	
	/* Si la combinaison actuelle est meilleure, mettre à jour */
	if (should_update(best, instr_step_node, nb_instr))
		best->best_comb = handle_best_comb(best, instr_step_node, instr, nb_instr);
	else
	{
		/* Sinon, appliquer l'instruction et continuer récursivement */
		apply_instr(d_copy, instr, QUIET);
		ft_lstclear(&instr_step_node, free);
		return best_insert_dir_recursive(d_copy, instr, can_push, best, nb_instr + 1);
	}
	
	return (best->best_comb);
}

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
	t_best_comb best = {NULL, max_cost};

	/* Créer une copie des données pour éviter de modifier l'originale */
	ft_memcpy(&d_copy, d, sizeof(t_data));
	
	/* Appeler la fonction récursive */
	t_list *result = best_insert_dir_recursive(&d_copy, instr, can_push, &best, 0);
	
	/* Check if result is actually an int value (indicating nb_instr when max_cost is COST_NOT_SET) */
	if (best.max_cost == COST_NOT_SET && (size_t)result <= INT_MAX) {
		/* This is a special case return - the result is actually an integer */
		fprintf(stderr, "Warning: COST_NOT_SET used, got nb_instr = %zu instead of a t_list\n", (size_t)result);
		return NULL; /* Return NULL to indicate no valid path found */
	}
	
	return result;
}


/*
t_list *handle_best_comb(t_list **best_comb, t_list *instr_step_node, int instr, int nb_instr)
{
	t_list *saved_first_instr;
	if (*best_comb)
		ft_lstclear(best_comb, free);
	*best_comb = instr_step_node;
	saved_first_instr = init_instr_step_node(instr, nb_instr);
	ft_lstadd_front(best_comb, saved_first_instr);
	return (*best_comb);
}

void handle_no_best_comb(t_list *first_intr_step_node, t_data *d_copy, int instr)
{
	t_instr_step *first_intr_step;
	first_intr_step = first_intr_step_node->content;
	first_intr_step->nb_instr++;
	apply_instr(d_copy, instr, QUIET);
}

void best_insert_loop(t_data *d_copy, int instr, int (*can_push)(t_data *), int *max_cost, t_list **best_comb)
{
	t_list *first_intr_step_node = init_instr_step_node(instr, 0);
	t_instr_step *first_intr_step = first_intr_step_node->content;
	while (first_intr_step->nb_instr < *max_cost)
	{
		t_list *instr_step_node = best_insert(d_copy, d_copy->r_instr, can_push, *max_cost);
		if (instr_step_node && first_intr_step->nb_instr + get_steps(instr_step_node) < *max_cost - 1)
		{
			*best_comb = handle_best_comb(best_comb, instr_step_node, instr, first_intr_step->nb_instr);
			*max_cost = ft_cost(*best_comb);
		}
		else
		{
			handle_no_best_comb(first_intr_step_node, d_copy, instr);
			ft_lstclear(&instr_step_node, free);
		}
	}
	ft_lstclear(&first_intr_step_node, free);
}

t_list *best_insert_dir(t_data *d, int instr, int (*can_push)(t_data *), int max_cost)
{
	t_data d_copy;
	t_list *best_comb = NULL;

	ft_memcpy(&d_copy, d, sizeof(t_data));
	best_insert_loop(&d_copy, instr, can_push, &max_cost, &best_comb);
	return (best_comb);
}
*/