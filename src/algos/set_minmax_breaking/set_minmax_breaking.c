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

int break_when_minmax_loaded(t_data *d, int instr)
{
	(void)instr;
	if (d->max_b == d->rank_max || d->min_b == 0)
	{
		if (d->lst_a->rank == d->rank_max || d->lst_a->rank == 0)
			return (BREAK_BEST_COMB);
	}
	return (TRUE);
}

int first_load_and_break_loop(t_data *data, int verbose)
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
		if (apply_best_comb_and(break_when_minmax_loaded, data, insertion_step, verbose) == BREAK_BEST_COMB)
			return (BREAK_BEST_COMB);
		ft_lstclear(&insertion_step, free);
	}
	return (nb_instr);
}

int dump_setting_min_or_max(t_data *data, int verbose)
{
	int nb_instr;
	int instr;

	nb_instr = 0;
	instr = rb;
	if (data->min_b == 0)
	{
		if (get_shortestway(0, data->lst_b) == RROTATE)
			instr = rrb;
	}
	else
	{
		if (get_shortestway(data->rank_max, data->lst_b) == ROTATE)
			instr = rr;
	}
	while (!(data->lst_b->rank == 0 || data->lst_b->rank == data->rank_max))
		nb_instr += apply_instr(data, instr, verbose);
	if (data->lst_a->rank == data->rank_max)
		nb_instr += apply_instr(data, ra, verbose);
	nb_instr += apply_instr(data, pa, verbose);
	while (data->lst_a->prev->rank != 0)
		nb_instr += apply_instr(data, ra, verbose);
	while (data->lst_b->rank != data->max_b)
		nb_instr += apply_instr(data, rb, verbose);
	while (data->lst_b)
		nb_instr += apply_instr(data, pa, verbose);
	return (nb_instr);
}

int load_breaking_min_or_max(t_data *data, int verbose)
{
	int nb_instr;
	int return_value;

	nb_instr = -1;
	while (TRUE)
	{
		return_value = first_load_and_break_loop(data, verbose);
		if (return_value == BREAK_BEST_COMB)
			break ;
		nb_instr += return_value;
	}
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
int set_minmax_breaking(t_data *data, int verbose)
{
	int instr_ls[7] = {ra, rb, rra, rrb, rr, rrr, LOOP_END};
	int nb_instr;

	data->r_instr = instr_ls;
	nb_instr = load_breaking_min_or_max(data, verbose);
	nb_instr += dump_setting_min_or_max(data, verbose);
	return (nb_instr);
}