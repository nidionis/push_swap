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
	while (can_push_b_strategic(data))
		nb_instr = apply_instr(data, pb, verbose);
	insertion_step = ft_best_comb(data, data->r_instr, 
		(int (*)(t_data *))can_push_b_strategic, SIZE_MAX);
	nb_instr = ft_nb_instr(insertion_step);
	if (apply_best_comb_and(break_when_minmax_loaded, data, insertion_step, verbose) == BREAK_BEST_COMB)
	{
		ft_lstclear(&insertion_step, free);
		return (BREAK_BEST_COMB);
	}
	ft_lstclear(&insertion_step, free);
	return (nb_instr);
}

int dump_setting_min_or_max(t_data *data, int verbose)
{
	int nb_instr;
	int instr;
	//t_list *best_steps;
	t_lnk *highest_below_pivot;

	nb_instr = 0;
	/* Trouver et positionner la valeur la plus haute sous le pivot */
	highest_below_pivot = find_highest_below_pivot(data);
	instr = (get_shortestway(highest_below_pivot->rank, data->lst_b) == ROTATE) ? rb : rrb;
	while (data->lst_b !=highest_below_pivot)
	{
		while (data->lst_b->rank != highest_below_pivot->rank)
			nb_instr += apply_instr(data, instr, verbose);
	}
	//printf("on pivot\n");
	//print_lst(data);
	while (data->max_b == data->rank_max || data->min_b == 0)
		nb_instr += apply_instr(data, pa, verbose);
	//while (data->lst_b)
	//{
	//	best_steps = ft_best_comb(data, data->r_instr, 
	//		(int (*)(t_data *))can_dump_b, SIZE_MAX);
	//	if (!best_steps)
	//		break;
	//	
	//	nb_instr += apply_best_comb_and(NULL, data, best_steps, verbose);
	//	ft_lstclear(&best_steps, free);
	//	nb_instr += apply_instr(data, pa, verbose);
	//}

	return (nb_instr);
}

/* Trouve la valeur la plus haute sous le pivot dans la pile B */
t_lnk *find_highest_below_pivot(t_data *data)
{
	t_lnk *highest_below_pivot;
	highest_below_pivot = NULL;
	
	if (data->lst_b)
	{
		t_lnk *current = data->lst_b;
		int highest_rank = -1;
		do {
			if (current->rank < data->pivot && current->rank > highest_rank)
			{
				highest_rank = current->rank;
				highest_below_pivot = current;
			}
			current = current->next;
		} while (current != data->lst_b);
	}
	
	return (highest_below_pivot);
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