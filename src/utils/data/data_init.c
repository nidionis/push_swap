/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 21:16:34 by supersko          #+#    #+#             */
/*   Updated: 2025/03/07 21:17:40 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/**
 * @brief Met à jour les données du programme en fonction de l'état des piles
 * 
 * @param data Structure de données à mettre à jour
 * @param lst_a Pile A
 * @param lst_b Pile B
 */
/**
 * @brief Updates all data fields after each operation
 * Updates min/max values, softmin/softmax, and medians for both stacks
 * 
 * @param data Main data structure
 * @param lst_a Pointer to stack A
 * @param lst_b Pointer to stack B
 */
void	data_update(t_data *data, t_lnk **lst_a, t_lnk **lst_b)
{
	if (!data || !lst_a || !lst_b)
		return;
	
	/* Update pointers to the current stacks */
	data->lst_a = *lst_a;
	data->lst_b = *lst_b;
	
	/* Update median values */
	data->mediane_a = *lst_a ? set_mediane(lst_a) : 0;
	data->mediane_b = *lst_b ? set_mediane(lst_b) : 0;
	
	/* Update min/max values for stack A */
	if (*lst_a)
	{
		t_lnk *max_a_elem = get_max(*lst_a);
		t_lnk *min_a_elem = get_min(*lst_a);
		data->max_a = max_a_elem ? max_a_elem->rank : 0;
		data->min_a = min_a_elem ? min_a_elem->rank : 0;
	}
	else
	{
		data->max_a = 0;
		data->min_a = 0;
	}
	
	/* Update min/max values for stack B */
	if (*lst_b)
	{
		t_lnk *max_b_elem = get_max(*lst_b);
		t_lnk *min_b_elem = get_min(*lst_b);
		data->max_b = max_b_elem ? max_b_elem->rank : 0;
		data->min_b = min_b_elem ? min_b_elem->rank : 0;
	}
	else
	{
		data->max_b = 0;
		data->min_b = 0;
	}
	
	/* Update softmin/softmax values */
	set_softmax(data, *lst_a, *lst_b);
	set_softmin(data, *lst_a, *lst_b);
}

/**
 * @brief Initialise les données du programme
 * 
 * @param data Structure de données à initialiser
 * @param lst_a Pile A
 * @param lst_b Pile B
 */
void	init_data(t_data *data, t_lnk **lst_a, t_lnk **lst_b)
{
	if (!data || !lst_a || !lst_b)
		return;

	data->lst_a = *lst_a;
	data->lst_b = *lst_b;
	data->max_a = 0;
	data->min_a = 0;
	data->max_b = 0;
	data->min_b = 0;
	data->softmax_a = 0;
	data->softmin_a = 0;
	data->softmax_b = 0;
	data->softmin_b = 0;
	data->mediane_a = 0;
	data->mediane_b = 0;
}
