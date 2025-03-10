/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:41:34 by nidionis          #+#    #+#             */
/*   Updated: 2025/02/03 00:10:14 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/**
 * @brief Trouve itérativement la meilleure combinaison d'instructions efficace
 * 
 * Cette fonction utilise une approche itérative pour trouver la meilleure combinaison
 * d'instructions pour atteindre l'état souhaité, ce qui évite la récursion et
 * améliore considérablement les performances
 * 
 * @param d Structure de données contenant les listes et paramètres
 * @param instr_ls Tableau d'instructions possibles
 * @param can_push Fonction qui vérifie si l'état est atteint
 * @param max_cost Coût maximum acceptable
 * @return t_list* Liste chaînée des instructions à appliquer
 */
static t_list *ft_best_comb_optimized(t_data *d, int *instr_ls, 
                                 int (*can_push)(t_data *), 
                                 int max_cost)
{
    t_list *best_overall = NULL;
    t_list *current_comb;
    int idx;
    int best_cost = SIZE_MAX;
    int current_cost;

//    /* Ensure max_cost is at least a reasonable minimum value */
//    if (max_cost <= COST_NOT_SET || max_cost <= 1)
//    {
//        max_cost = 10; /* Set a reasonable default if max_cost is too small */
//        fprintf(stderr, "[ft_best_comb_optimized] Warning: max_cost too small, set to %d\n", max_cost);
//    }

    /* Safety check for NULL pointers */
    if (!can_push)
    {
        fprintf(stderr, "[ft_best_comb_optimized] Error: NULL can_push function pointer\n");
        return (NULL);
    }

    /* Check if instruction list is NULL */
    if (!instr_ls)
    {
        fprintf(stderr, "[ft_best_comb_optimized] Error: NULL instruction list\n");
        return (NULL);
    }
    
    /* Validate data structure */
    if (!d)
    {
        fprintf(stderr, "[ft_best_comb_optimized] Error: NULL data pointer\n");
        return (NULL);
    }

    /* Parcourir toutes les instructions possibles (with safety limits) */
    idx = 0;
    while (instr_ls[idx] != LOOP_END) /* Add upper limit to prevent infinite loop */
    {
        /* Validate instruction code */
        if (instr_ls[idx] < INSTR_MIN || instr_ls[idx] > INSTR_MAX)
        {
            fprintf(stderr, "[ft_best_comb_optimized] Invalid instruction code: %d at index %d\n", instr_ls[idx], idx);
            idx++;
            continue;
        }
        
        /* Trouver la meilleure combinaison pour cette direction */
        current_comb = best_insert_dir(d, instr_ls[idx], can_push, max_cost);
        current_cost = ft_cost(current_comb);
        
        /* Si nous avons trouvé une meilleure combinaison */
        if (current_comb && current_cost < best_cost)
        {
            /* Libérer l'ancienne meilleure combinaison */
            if (best_overall)
                ft_lstclear(&best_overall, free);
            
            /* Mettre à jour la meilleure combinaison */
            best_overall = current_comb;
            best_cost = current_cost;
            
            /* Mise à jour du coût maximum pour optimiser les recherches futures */
            max_cost = best_cost;
        }
        else if (current_comb)
        {
            /* Libérer une combinaison qui n'est pas la meilleure */
            ft_lstclear(&current_comb, free);
        }
        
        idx++;
    }
    
    return (best_overall);
}

/**
 * @brief Trouve la meilleure combinaison d'instructions
 * 
 * Point d'entrée principal qui appelle la fonction optimisée non récursive
 * 
 * @param d Structure de données contenant les listes et paramètres
 * @param instr_ls Tableau d'instructions possibles
 * @param can_push Fonction qui vérifie si l'état est atteint
 * @param max_cost Coût maximum acceptable 
 * @return t_list* Liste chaînée des instructions à appliquer
 */
t_list *ft_best_comb(t_data *d, int *instr_ls, int (*can_push)(t_data *), int max_cost)
{
    return (ft_best_comb_optimized(d, instr_ls, can_push, max_cost));
}
