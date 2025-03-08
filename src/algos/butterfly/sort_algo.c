/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 23:40:00 by nidionis          #+#    #+#             */
/*   Updated: 2025/03/07 23:40:00 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/**
 * @brief Vérifie si un élément est sur le minimum ou le maximum d'une pile
 * 
 * @param data Structure de données
 * @param lst Pile à vérifier
 * @return int TRUE si l'élément est sur le min ou le max, FALSE sinon
 */
int	is_on_min_or_max(t_data *data, t_lnk *lst)
{
	if (lst == data->lst_a)
	{
		if (data->max_a == lst->rank || data->min_a == lst->rank)
			return (TRUE);
	}
	else if (lst == data->lst_b)
	{
		if (data->max_b == lst->rank || data->min_b == lst->rank)
			return (TRUE);
	}
	return (FALSE);
}

/**
 * @brief Applique un échange sur la pile B si nécessaire
 * 
 * @param data Structure de données
 * @param nb_instr Nombre d'instructions déjà effectuées
 * @param mediane Médiane pour déterminer s'il faut échanger
 * @param verbose Mode verbeux (1) ou silencieux (0)
 * @return int Nombre total d'instructions effectuées
 */
static int	apply_swap_if_needed(t_data *data, int nb_instr, int mediane, int verbose)
{
	if (data->lst_b && should_swap_b(data->lst_b, mediane))
		nb_instr += apply_instr(data, sb, verbose);
	return (nb_instr);
}

/**
 * @brief Charge les éléments dans la pile B selon la stratégie papillon
 * 
 * Cette fonction utilise une approche récursive pour trouver la meilleure séquence
 * d'instructions à appliquer pour organiser correctement les piles.
 * 
 * @param data Structure de données contenant les piles
 * @param can_do Pointeur vers la fonction qui vérifie si un élément peut être déplacé
 * @param verbose Mode verbeux (1) ou silencieux (0)
 * @return int Nombre d'instructions effectuées ou code d'erreur
 */
int	load_butterfly(t_data *data, int (*can_do)(t_data *data), int verbose)
{
	t_list	*insertion_step;
	int		nb_instr;
	int		mediane;

	/* Initialisation des variables */
	nb_instr = -1;
	mediane = get_kinda_mediane(data, data->lst_a);
	data->max_to_load = data->rank_max;
	data->min_to_load = 0;

	/* Cas simple : on peut directement pousser vers B */
	if (can_do(data))
	{
		nb_instr = apply_instr(data, pb, verbose);
		nb_instr = apply_swap_if_needed(data, nb_instr, mediane, verbose);
	}
	/* Cas complexe : recherche d'une séquence d'instructions optimale */
	else
	{
		/* Réinitialisation des bornes pour la recherche */
		data->min_to_load = 0;
		data->max_to_load = data->rank_max;
		
		/* Recherche récursive de la meilleure combinaison */
		insertion_step = ft_best_comb(data, data->r_instr, can_do, SIZE_MAX);
		if (!insertion_step)
			return (-1);
		
		/* Application de la combinaison trouvée */
		nb_instr = ft_nb_instr(insertion_step);
		if (apply_best_comb_and(NULL, data, insertion_step, verbose) == BREAK_BEST_COMB)
		{
			ft_lstclear(&insertion_step, free);
			return (BREAK_BEST_COMB);
		}
		
		ft_lstclear(&insertion_step, free);
	}
	
	return (nb_instr);
}

/**
 * @brief Algorithme de tri récursif principal
 * 
 * @param data Structure de données contenant les piles
 * @param can_do Fonction qui détermine si un élément peut être déplacé
 * @param verbose Mode verbeux
 */
void	sort_recursive(t_data *data, int (*can_do)(t_data *), int verbose)
{
	int	r_instr[] = {ra, rb, rra, rrb, rr, rrr, LOOP_END};
	
	/* Condition d'arrêt de la récursion */
	if (!data->lst_a)
		return;
	
	/* Initialisation des paramètres pour cette itération */
	data->r_instr = r_instr;
	data->softmax_a = data->rank_max;
	data->softmin_a = 0;
	data->max_to_load = data->rank_max;
	data->min_to_load = 0;
	
	/* Appliquer une étape de tri */
	load_butterfly(data, can_do, verbose);
	
	/* Appel récursif pour continuer le tri */
	sort_recursive(data, can_do, verbose);
}

/**
 * @brief Pousse tous les éléments de B vers A
 * 
 * @param data Structure de données
 * @param verbose Mode verbeux ou silencieux
 * @return int Nombre d'instructions exécutées
 */
static int	dump_all_b_to_a(t_data *data, int verbose)
{
	int	nb_instr;

	nb_instr = 0;
	while (data->lst_b)
	{
		nb_instr += apply_instr(data, pa, verbose);
	}
	return (nb_instr);
}



/**
 * @brief Algorithme principal de tri optimisé
 *
 * Cette fonction implémente l'algorithme principal non récursif qui:
 * 1. Pousse les éléments de A vers B en utilisant la meilleure combinaison d'instructions
 * 2. Pousse tous les éléments de B vers A de manière optimale
 *
 * @param data Structure de données
 * @param verbose Mode verbeux (1) ou silencieux (0)
 * @return int Nombre d'instructions exécutées
 */
int	main_algo(t_data *data, int verbose)
{
	int	nb_instr;
	t_list *best_steps;
	int	rotation_instrs[7] = {ra, rb, rra, rrb, rr, rrr, LOOP_END};
	int	max_cost;

	nb_instr = 0;
	max_cost = 500; // Coût maximum acceptable pour une séquence d'instructions

	/* Étape 1: Pousser tous les éléments de A vers B de manière optimale */
	while (data->lst_a)
	{
		/* Si l'élément actuel peut être poussé directement */
		if (can_push_b(data))
		{
			nb_instr += apply_instr(data, pb, verbose);
			continue;
		}
		
		/* Sinon, trouver la meilleure combinaison d'instructions pour amener le bon élément au sommet */
		best_steps = ft_best_comb(data, rotation_instrs, can_push_b, max_cost);
		
		if (best_steps)
		{
			/* Appliquer la séquence d'instructions */
			nb_instr += apply_best_comb_and(NULL, data, best_steps, verbose);
			
			/* Libérer la mémoire utilisée */
			ft_lstclear(&best_steps, free);
			
			/* Push l'élément vers B puisqu'il est maintenant au bon endroit */
			nb_instr += apply_instr(data, pb, verbose);
		}
	}
	
	/* Étape 2: Pousser tous les éléments de B vers A */
	nb_instr += dump_all_b_to_a(data, verbose);

	return (nb_instr);
}
