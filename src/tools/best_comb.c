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
 * @brief Trouve récursivement la meilleure combinaison d'instructions
 * 
 * Cette fonction utilise la récursion pour trouver la meilleure combinaison
 * d'instructions pour atteindre l'état souhaité
 * 
 * @param d Structure de données contenant les listes et paramètres
 * @param instr_ls Tableau d'instructions possibles
 * @param can_push Fonction qui vérifie si l'état est atteint
 * @param max_cost Coût maximum acceptable
 * @param idx Index de l'instruction dans instr_ls (pour la récursion)
 * @return t_list* Liste chaînée des instructions à appliquer
 */
static t_list *ft_best_comb_recursive(t_data *d, int *instr_ls, 
                                    int (*can_push)(t_data *), 
                                    int max_cost, int idx)
{
    t_list *best_comb_in_dir;
    t_list *best_from_next;
    t_list *result;

    if (instr_ls[idx] == LOOP_END)
        return (NULL);

    best_comb_in_dir = best_insert_dir(d, instr_ls[idx], can_push, max_cost);
    best_from_next = ft_best_comb_recursive(d, instr_ls, can_push, max_cost, idx + 1);

    if (ft_cost(best_comb_in_dir) < ft_cost(best_from_next))
    {
        if (best_from_next)
            ft_lstclear(&best_from_next, free);
        result = best_comb_in_dir;
    }
    else
    {
        if (best_comb_in_dir)
            ft_lstclear(&best_comb_in_dir, free);
        result = best_from_next;
    }
    
    return (result);
}

/**
 * @brief Trouve la meilleure combinaison d'instructions
 * 
 * Point d'entrée principal qui appelle la fonction récursive
 * 
 * @param d Structure de données contenant les listes et paramètres
 * @param instr_ls Tableau d'instructions possibles
 * @param can_push Fonction qui vérifie si l'état est atteint
 * @param max_cost Coût maximum acceptable 
 * @return t_list* Liste chaînée des instructions à appliquer
 */
t_list *ft_best_comb(t_data *d, int *instr_ls, int (*can_push)(t_data *), int max_cost)
{
    d->r_instr = instr_ls;
    return (ft_best_comb_recursive(d, instr_ls, can_push, max_cost, 0));
}