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

int first_load_low_and_minmax(t_data *data, int verbose)
{
	t_list *insertion_step;
	int nb_instr;

	nb_instr = -1;
	if (can_load_b(data))
		apply_instr(data, pb, verbose);
	else
	{
		insertion_step = ft_best_comb(data, data->r_instr, can_first_load, SIZE_MAX);
		if (!insertion_step)
			return (-1);
		nb_instr = ft_nb_instr(insertion_step);
		if (apply_best_comb_and(NULL, data, insertion_step, verbose) == BREAK_BEST_COMB)
			return (BREAK_BEST_COMB);
		ft_lstclear(&insertion_step, free);
	}
	return (nb_instr);
}

int reach_max_lst_b(t_data *data, int verbose)
{
	int nb_instr;
	int instr;
	t_lst	*b;

	nb_instr = 0;
	b = &data->b;
	instr = rb;
	if (b->min != 0)
		if (get_shortestway(0, b->lst) == RROTATE)
			instr = rrb;
	while (b->lst->rank != 0)
		nb_instr += apply_instr(data, instr, verbose);
	return (nb_instr);
}

/*
250209-23:42:56-nidionis@k1r2p7.42mulhouse.fr-~/push_swap-
=> ./complexity 500 200
Démarrage du test : 500 éléments, 200 itérations (seed 3859599866)
Pire = 3396 instructions
Moyenne = 1622 instructions
Meilleur = 57 instructionsss
Écart-type = 789.6 instructions
Objectif = entrez un nombre en troisième argument
Précision = entrez un testeur en quatrième argument
100 % effectué
Complexity 1.7.1 (2024-11-12)
*/
int set_minmax_load_low(t_data *data, int verbose)
{
	int instr_ls[7] = {ra, rb, rra, rrb, rr, rrr, LOOP_END};
	int nb_instr;
	int ret;

	data->r_instr = instr_ls;
    ret = 54;
    nb_instr = 0;
    while (ret != BREAK_BEST_COMB)
    {
        ret = first_load_low_and_minmax(data, verbose);
        if (ret != BREAK_BEST_COMB)
            nb_instr += ret;
    }
    nb_instr += reach_max_lst_b(data, verbose);
    while (data->b.lst)
    {
        nb_instr = apply_instr(data, pa, verbose);
    }
	return (nb_instr);
}