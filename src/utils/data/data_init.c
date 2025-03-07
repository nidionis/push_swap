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
void	data_update(t_data *data, t_lnk **lst_a, t_lnk **lst_b)
{
	static t_lnk	*copy_a;
	static t_lnk	*copy_b;

	if (data->update == TRUE)
	{
		if (lst_a && *lst_a && lst_b)
		{
			copy_a = *lst_a;
			copy_b = *lst_b;
			data->mediane_a = set_mediane(lst_a);
			data->mediane_b = set_mediane(lst_b);
			set_softmax(data, *lst_a, *lst_b);
			set_softmin(data, *lst_a, *lst_b);
			if (data->lst_a && *data->lst_a && (lnk_lstlen(*data->lst_a) > 1))
				data->max_idx = (data->max_rank + 1) / 2;
			data->lst_len_a = lnk_lstlen(*lst_a);
			data->lst_len_b = lnk_lstlen(*lst_b);
			if (data->lst_len_b > 0)
			{
				data->best_to_push[0] = UNSET;
				data->best_to_push[1] = UNSET;
			}
		}
	}
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
	t_lnk	*lst_a_orig;

	lst_a_orig = *lst_a;
	data->print = TRUE;
	data->lst_a = lst_a;
	data->lst_b = lst_b;
	data->best_instr = UNSET;
	data->best_nb_instr = UNSET;
	data->lst_len = lnk_lstlen(*lst_a);
	data->max_rank = data->lst_len - 1;
	data->max_idx = data->lst_len / 2;
	data->min_idx = 0;
	data->update = TRUE;
	data->best_to_push[0] = UNSET;
	data->best_to_push[1] = UNSET;
}
