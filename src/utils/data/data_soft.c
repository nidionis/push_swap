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
	t_lnk *softmax = get_softmax(lst_b);
	if (softmax)
	{
		data->softmax_b = softmax->rank;
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
	t_lnk *softmin = get_softmin(lst_b);
	if (softmin)
	{
		data->softmin_b = softmin->rank;
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
		printf("\tmin_a : %d\n", d->min_a);
		printf("\tmax_a : %d\n", d->max_a);
		printf("\tmediane_a : %d\n", d->mediane_a);
		printf("\tsoftmin_a : %d\n", d->softmin_a);
		printf("\tsoftmax_a : %d\n", d->softmax_a);
		printf("\tmin_b : %d\n", d->min_b);
		printf("\tmax_b : %d\n", d->max_b);
		printf("\tmediane_b : %d\n", d->mediane_b);
		printf("\tsoftmin_b : %d\n", d->softmin_b);
		printf("\tsoftmax_b : %d\n", d->softmax_b);
		printf("}\n");
	}
}
