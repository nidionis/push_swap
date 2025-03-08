/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/03/07 23:45:59 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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
	
	/* Définition des instructions de rotation */
	int rotation_instrs[7] = {ra, rb, rra, rrb, rr, rrr, LOOP_END};

	/* Lancement de l'algorithme ultra-optimisé */
	optimized_algo(&d, can_load_legacy, rotation_instrs, PRINT);
	
	/* Libération de la mémoire */
	del_lst(&d.lst_a);
	del_lst(&d.lst_b);
	free(d.instr_map);
	
	return (0);
}
