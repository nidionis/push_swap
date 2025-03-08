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
 * @brief Charge un élément dans la pile B en utilisant la meilleure séquence d'instructions
 * 
 * Cette fonction trouve et applique la meilleure séquence d'instructions pour
 * positionner et pousser un élément de A vers B de manière optimale.
 * 
 * @param data Structure de données contenant les piles
 * @param can_do Pointeur vers la fonction qui vérifie si un élément peut être déplacé
 * @param verbose Mode verbeux (1) ou silencieux (0)
 * @return int Nombre d'instructions effectuées ou code d'erreur
 */
int	optimized_push_to_b(t_data *data, int (*can_do)(t_data *data), int verbose)
{
	t_list	*insertion_step;
	int		nb_instr;
	int		mediane;

	nb_instr = -1;
	mediane = get_kinda_mediane(data, data->lst_a);
	data->max_to_load = data->rank_max;
	data->min_to_load = 0;

	if (can_do(data))
	{
		nb_instr = apply_instr(data, pb, verbose);
		nb_instr = apply_swap_if_needed(data, nb_instr, mediane, verbose);
	}
	else
	{
		data->min_to_load = 0;
		data->max_to_load = data->rank_max;
		
		insertion_step = ft_best_comb(data, data->r_instr, can_do, SIZE_MAX);
		if (!insertion_step)
			return (-1);
		
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

/* Cette fonction sort_recursive a été supprimée car remplacée par l'algorithme itératif main_algo */

/**
 * @brief Pousse tous les éléments de B vers A
 * 
 * @param data Structure de données
 * @param verbose Mode verbeux ou silencieux
 * @return int Nombre d'instructions exécutées
 */
int	dump_all_b_to_a(t_data *data, int verbose)
{
	int	nb_instr;

	nb_instr = 0;
	while (data->lst_b)
	{
		nb_instr += apply_instr(data, pa, verbose);
	}
	return (nb_instr);
}
int process_stack(t_data *data, int (*can_func)(t_data *), int *instrs, int verbose,
			int push_instr, int max_cost, int push_after_comb)
{
	int nb_instr;
	t_list *best_steps;

	nb_instr = 0;
	while ((push_instr == pb && data->lst_a) || (push_instr == pa && data->lst_b))
	{
		if (can_func(data))
		{
			nb_instr += apply_instr(data, push_instr, verbose);
			continue;
		}
		if (max_cost == 0)
			return (nb_instr);

		best_steps = ft_best_comb(data, instrs, can_func, max_cost);
		if (!best_steps)
			return (nb_instr);

		nb_instr += apply_best_comb_and(NULL, data, best_steps, verbose);
		ft_lstclear(&best_steps, free);

		if (push_after_comb)
			nb_instr += apply_instr(data, push_instr, verbose);
	}
	return (nb_instr);
}

int optimized_algo(t_data *data, int (*f_can)(t_data *), int *instrs, int verbose)
{
	int nb_instr;

	nb_instr = 0;
	data->r_instr = instrs;

	nb_instr += process_stack(data, f_can, instrs, verbose, pb, SIZE_MAX, 1);
	nb_instr += process_stack(data, can_dump_b, instrs, verbose, pa, SIZE_MAX, 1);

	return (nb_instr);
}

int main_algo(t_data *data, int verbose)
{
	int nb_instr;
	int rotation_instrs[7] = {ra, rb, rra, rrb, rr, rrr, LOOP_END};
	int max_cost;

	nb_instr = 0;
	max_cost = 500;

	nb_instr += process_stack(data, can_push_b, rotation_instrs, verbose, pb, max_cost, 0);
	nb_instr += process_stack(data, can_dump_b, rotation_instrs, verbose, pa, max_cost, 1);

	return (nb_instr);
}
