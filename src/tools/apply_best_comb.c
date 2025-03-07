/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_best_comb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 01:31:51 by nidionis          #+#    #+#             */
/*   Updated: 2025/02/03 01:39:29 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/**
 * @brief Applique une étape d'instruction avec une fonction optionnelle de post-traitement
 * 
 * @param f_do Fonction à appliquer après chaque instruction (peut être NULL)
 * @param data Structure de données contenant les listes
 * @param instr_step Étape d'instruction à appliquer
 * @param verbose Mode verbeux (1) ou silencieux (0)
 * @return int Status de l'opération
 */
int apply_set_and(int (*f_do)(t_data *d, int instr), t_data *data, t_instr_step *instr_step, int verbose)
{
    int count;
    int status;
    
    if (instr_step->instr == NO_INSTR)
        return (NO_INSTR);
    if (instr_step->nb_instr == CANT_INSERT || instr_step->nb_instr == SIZE_MAX || instr_step->nb_instr == 0)
        return (instr_step->nb_instr);
        
    count = instr_step->nb_instr;
    while (count--)
    {
        apply_instr(data, instr_step->instr, verbose);
        if (f_do && (status = f_do(data, instr_step->instr)) == BREAK_BEST_COMB)
            return (BREAK_BEST_COMB);
    }
    return (TRUE);
}

/**
 * @brief Applique récursivement une combinaison d'instructions
 * 
 * @param f_do Fonction à appliquer après chaque instruction (peut être NULL)
 * @param data Structure de données contenant les listes
 * @param best_comb Liste des étapes d'instructions à appliquer
 * @param verbose Mode verbeux (1) ou silencieux (0)
 * @return int Status de l'opération
 */
static int apply_best_comb_recursive(int (*f_do)(t_data *d, int instr), t_data *data, t_list *best_comb, int verbose)
{
    int status;
    
    if (!best_comb)
        return (TRUE);
        
    status = apply_set_and(f_do, data, best_comb->content, verbose);
    if (status != TRUE && status != 0)
        return (status);
        
    return (apply_best_comb_recursive(f_do, data, best_comb->next, verbose));
}

/**
 * @brief Applique une combinaison d'instructions avec une fonction optionnelle
 * 
 * @param f_do Fonction à appliquer après chaque instruction (peut être NULL)
 * @param data Structure de données contenant les listes
 * @param best_comb Liste des étapes d'instructions à appliquer
 * @param verbose Mode verbeux (1) ou silencieux (0)
 * @return int Status de l'opération
 */
int apply_best_comb_and(int (*f_do)(t_data *d, int instr), t_data *data, t_list *best_comb, int verbose)
{
    return apply_best_comb_recursive(f_do, data, best_comb, verbose);
}