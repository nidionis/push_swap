/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_soft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 21:16:34 by supersko          #+#    #+#             */
/*   Updated: 2025/03/07 21:17:40 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/**
 * @brief Retourne le maximum "soft" - c'est-à-dire en ignorant certains éléments
 * 
 * @param lst Liste chaînée à analyser
 * @return t_lnk* Élément avec le rang maximum selon critères
 */
t_lnk	*get_softmax(t_lnk *lst)
{
	return (get_max(lst));
}

/**
 * @brief Retourne le minimum "soft" - c'est-à-dire en ignorant certains éléments
 * 
 * @param lst Liste chaînée à analyser
 * @return t_lnk* Élément avec le rang minimum selon critères
 */
t_lnk	*get_softmin(t_lnk *lst)
{
	return (get_min(lst));
}

/**
 * @brief Configure le maximum "soft" dans la structure de données
 * 
 * @param data Structure de données à mettre à jour
 * @param lst_a Liste A
 * @param lst_b Liste B
 */
void	set_softmax(t_data *data, t_lnk *lst_a, t_lnk *lst_b)
{
	(void)lst_a;
	if (!lst_b)
		return ;
	data->softmax = get_softmax(lst_b);
	if (data->softmax)
	{
		data->softmax_b = data->softmax->rank;
		data->softmax_b_pos = get_shortestway(data, data->softmax->rank, B);
	}
	else
		data->softmax_b = -1;
}

/**
 * @brief Configure le minimum "soft" dans la structure de données
 * 
 * @param data Structure de données à mettre à jour
 * @param lst_a Liste A
 * @param lst_b Liste B
 */
void	set_softmin(t_data *data, t_lnk *lst_a, t_lnk *lst_b)
{
	(void)lst_a;
	if (!lst_b)
		return ;
	data->softmin = get_softmin(lst_b);
	if (data->softmin)
	{
		data->softmin_b = data->softmin->rank;
		data->softmin_b_pos = get_shortestway(data, data->softmin->rank, B);
	}
	else
		data->softmin_b = -1;
}

/**
 * @brief Affiche les informations contenues dans la structure de données
 * 
 * @param d Structure de données à afficher
 */
void	print_data(t_data *d)
{
	if (!d)
		printf("data = NULL\n");
	else
	{
		printf("data ={\n");
		printf("\tmin_idx : %d\n", d->min_idx);
		printf("\tmax_idx : %d\n", d->max_idx);
		printf("\tmax_rank : %d\n", d->max_rank);
		printf("\tlst_len_a : %d\n", d->lst_len_a);
		printf("\tlst_len_b : %d\n", d->lst_len_b);
		printf("}\n");
	}
}
