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
 * @brief Trouve récursivement la meilleure instruction dans un ensemble d'instructions
 * 
 * @param d_copy Copie de la structure de données pour éviter de modifier l'originale
 * @param lst_instr Tableau d'instructions possibles
 * @param can_push Fonction vérifiant si l'état est atteint
 * @param max_cost Coût maximum acceptable
 * @param idx Index courant dans le tableau d'instructions (pour la récursion)
 * @param best_instr Meilleure instruction trouvée jusque-là
 * @param best_cost Coût de la meilleure instruction trouvée jusque-là
 * @return t_instr_step* Structure contenant la meilleure instruction et son coût
 */
static t_instr_step *find_best_instr_recursive(t_data *d_copy, int lst_instr[], 
                                             int (*can_push)(t_data *), 
                                             int max_cost, int idx,
                                             int best_instr, int best_cost)
{
    int current_cost;
    t_instr_step *result;
    
    /* Cas de base : fin du tableau d'instructions */
    if (lst_instr[idx] == LOOP_END)
    {
        result = malloc(sizeof(t_instr_step));
        if (!result)
            return (NULL);
        result->instr = best_instr;
        result->nb_instr = best_cost;
        return (result);
    }
    
    /* Évaluer le coût de l'instruction courante */
    current_cost = count_instr(d_copy, lst_instr[idx], can_push, max_cost);
    
    /* Si l'instruction courante est meilleure, mettre à jour les paramètres */
    if (current_cost < best_cost)
    {
        best_instr = lst_instr[idx];
        best_cost = current_cost;
        max_cost = current_cost; /* Mise à jour du coût max pour les prochaines itérations */
    }
    
    /* Appel récursif pour l'instruction suivante */
    return find_best_instr_recursive(d_copy, lst_instr, can_push, max_cost, idx + 1, best_instr, best_cost);
}

/**
 * @brief Trouve la meilleure instruction pour atteindre un état donné
 * 
 * @param d Structure de données contenant les listes
 * @param lst_instr Tableau d'instructions possibles
 * @param can_push Fonction vérifiant si l'état est atteint
 * @param max_cost Coût maximum acceptable
 * @return t_list* Nœud contenant l'instruction et son coût
 */
t_list	*best_insert(t_data *d, int lst_instr[], int (*can_push)(t_data *), int max_cost)
{
	t_data d_copy;
	t_instr_step *instr_step;
	t_list *instr_step_node;
	
	/* Créer une copie des données pour éviter de modifier l'originale */
	ft_memcpy(&d_copy, d, sizeof(t_data));
	
	/* Si l'état est déjà atteint, retourner une instruction vide */
	if (can_push(&d_copy))
	{
		instr_step = malloc(sizeof(t_instr_step));
		if (!instr_step)
			return (NULL);
		instr_step->instr = lst_instr[0];
		instr_step->nb_instr = 0;
	}
	else
	{
		/* Rechercher récursivement la meilleure instruction */
		instr_step = find_best_instr_recursive(&d_copy, lst_instr, can_push, max_cost, 0, lst_instr[0], SIZE_MAX);
		if (!instr_step)
			return (NULL);
	}
	
	/* Créer le nœud de liste pour l'instruction */
	instr_step_node = ft_lstnew(instr_step);
	return (instr_step_node);
}

/**
 * @brief Obtient le nombre d'étapes d'un nœud d'instruction
 * 
 * @param instr_step_node Nœud d'instruction
 * @return int Nombre d'étapes
 */
int get_steps(t_list *instr_step_node)
{
	t_instr_step *instr_step;

	if (!instr_step_node)
		return (SIZE_MAX);
		
	instr_step = instr_step_node->content;
	return (instr_step->nb_instr);
}

/**
 * @brief Initialise un nouveau nœud d'instruction
 * 
 * @param instr Code de l'instruction
 * @param nb_instr_init Nombre d'instructions initial
 * @return t_list* Nœud créé
 */
t_list *init_instr_step_node(int instr, int nb_instr_init)
{
	t_instr_step *instr_step;
	t_list *instr_step_node;

	/* Allouer la mémoire pour la structure */
	instr_step = malloc(sizeof(t_instr_step));
	if (!instr_step)
		return (NULL);
		
	/* Initialiser les valeurs */
	instr_step->instr = instr;
	instr_step->nb_instr = nb_instr_init;
	
	/* Créer le nœud de liste */
	instr_step_node = ft_lstnew(instr_step);
	return (instr_step_node);
}




//void	explore_insert_paths(t_data *d, int lst_instr[], int first_instr_steps[], int (*can_push)(t_data *))
//{
//	int	*second_instr_steps;
//	int	j_instr = 0;
//
//	while (first_instr_steps[NB_INSTR]++ < ft_cost(d->best_comb))
//	{
//		apply_instr(d, lst_instr[j_instr], QUIET);
//		second_instr_steps = insert_target_to_list_steps(d, lst_instr, can_push, ft_cost(d->best_comb));
//		j_instr++;
//	}
//	//while (lst_instr[j_instr] != LOOP_END && first_instr_steps[NB_INSTR]++ < ft_cost(d->best_comb))
//	//{
//	//	apply_instr(d, lst_instr[j_instr], QUIET);
//	//	second_instr_steps = insert_target_to_list_steps(d, lst_instr, can_push, ft_cost(d->best_comb));
//	//	if (can_push(d))
//	//	{
//	//		update_best_comb(&d->best_comb, first_instr_steps, second_instr_steps);
//	//		d->best_cost_comb = ft_cost(d->best_comb);
//	//		free(second_instr_steps);
//	//		break;
//	//	}
//	//	else
//	//		free(second_instr_steps);
//	//	j_instr++;
//	//}
//}
//
