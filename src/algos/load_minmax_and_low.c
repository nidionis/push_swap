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
	int nb_instr;
	int op_result;
	t_comb_operation comb_op;

	nb_instr = 0;
	if (can_push_b_strategic(data))
		nb_instr += apply_instr(data, pb, verbose);
	else
	{
		/* Initialize operation */
		comb_op = init_comb_operation(data->r_instr, 
			(int (*)(t_data *))can_push_b_strategic, NULL, verbose);
		
		/* Apply calculated best combination */
		op_result = apply_best_comb_operation(data, &comb_op);
		if (op_result == CANT_INSERT_ERROR)
			return (nb_instr);
		
		nb_instr += op_result;
	}
	return (nb_instr);
}

int reach_max_lst_b(t_data *data, int verbose)
{
	int nb_instr;
	int instr;

	nb_instr = 0;
	instr = rb;
	if (data->min_b != 0)
		if (get_shortestway(0, data->lst_b) == RROTATE)
			instr = rrb;
	while (data->lst_b->rank != 0)
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
    while (data->lst_b)
    {
        nb_instr = apply_instr(data, pa, verbose);
    }
	return (nb_instr);
}