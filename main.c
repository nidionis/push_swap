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
	
	init_data(&d, &d.lst_a, &d.lst_b);
	d.instr_map = init_instr_map();
	
	int rotation_instrs[7] = {rb, rr, ra, rra, rrb, rrr, LOOP_END};
	d.r_instr = rotation_instrs;
	d.pivot = d.rank_max / 2;
	while (!d.lst_b ||(get_min(d.lst_b)->rank != 0 || get_max(d.lst_b)->rank != d.rank_max))
	{
		first_load_and_break_loop(&d, PRINT);
	}
	//print_lst(&d);
	dump_setting_min_or_max(&d, PRINT);
	//optimized_algo(&d, can_push_b_strategic, rotation_instrs, PRINT);
	
	/* Libération de la mémoire */
	del_lst(&d.lst_a);
	del_lst(&d.lst_b);
	free(d.instr_map);
	
	return (0);
}
