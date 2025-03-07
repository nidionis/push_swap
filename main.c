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

//void	select_algo(int ind_max)
//{
//	if (ind_max == 1)
//		sort_2_nb(1);
//	else if (ind_max == 2)
//		sort_3_nb(2);
//	else if (ind_max == 3)
//		sort_4_nb(3);
//	else if (ind_max == 4)
//		sort_5_nb(4);
//	else
//	{
//		printf("Error\n");
//	}
//}

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
static int apply_swap_if_needed(t_data *data, int nb_instr, int mediane, int verbose)
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
	t_list *insertion_step;
	int nb_instr;
	int	mediane;

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
static void sort_recursive(t_data *data, int (*can_do)(t_data *), int verbose)
{
    int r_instr[] = {ra, rb, rra, rrb, rr, rrr, LOOP_END};
    
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
 * @brief Fonction principale
 * 
 * @param argc Nombre d'arguments
 * @param argv Tableau d'arguments
 * @return int Code de retour
 */
int	main(int argc, char **argv)
{
	t_data d;

	/* Initialisation de la structure de données */
	ft_bzero(&d, sizeof(t_data));
	
	/* Vérification des arguments */
	if (argc < 2)
	{
		ft_errmsg(NULL);
		exit(0);
	}
	
	/* Lecture des arguments et initialisation des piles */
	d.lst_a = get_args(&d, argc, argv);
	d.rank_max = lst_init_ranks(&d.lst_a);
	d.lst_b = NULL;
	
	/* Vérification des duplications */
	if (!ft_no_duplicate(d.lst_a))
		ft_errmsg("Error: duplicated items");
	
	/* Initialisation des structures de données */
	init_data(&d, &d.lst_a, &d.lst_b);
	d.instr_map = init_instr_map();
	
	/* Tri récursif des piles */
	sort_recursive(&d, can_butterfly_inc, PRINT);
	
	/* Libération de la mémoire */
	del_lst(&d.lst_a);
	del_lst(&d.lst_b);
	free(d.instr_map);
	
	return (0);
}
