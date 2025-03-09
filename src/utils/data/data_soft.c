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
/**
 * @brief Sets the soft max values for both stacks
 * The softmax is the maximum rank element that's considered "sorted"
 * 
 * @param data Data structure to update
 * @param lst_a Stack A
 * @param lst_b Stack B
 */
void	set_softmax(t_data *data, t_lnk *lst_a, t_lnk *lst_b)
{
	if (!data)
		return;
	
	/* Update softmax_a if stack A exists */
	if (lst_a)
	{
		t_lnk *softmax_a = get_softmax(lst_a);
		if (softmax_a)
			data->softmax_a = softmax_a->rank;
		else
			data->softmax_a = -1;
	}
	else
		data->softmax_a = -1;
	
	/* Update softmax_b if stack B exists */
	if (lst_b)
	{
		t_lnk *softmax_b = get_softmax(lst_b);
		if (softmax_b)
			data->softmax_b = softmax_b->rank;
		else
			data->softmax_b = -1;
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
/**
 * @brief Sets the soft min values for both stacks
 * The softmin is the minimum rank element that's considered "sorted"
 * 
 * @param data Data structure to update
 * @param lst_a Stack A
 * @param lst_b Stack B
 */
void	set_softmin(t_data *data, t_lnk *lst_a, t_lnk *lst_b)
{
	if (!data)
		return;
	
	/* Update softmin_a if stack A exists */
	if (lst_a)
	{
		t_lnk *softmin_a = get_softmin(lst_a);
		if (softmin_a)
			data->softmin_a = softmin_a->rank;
		else
			data->softmin_a = -1;
	}
	else
		data->softmin_a = -1;
	
	/* Update softmin_b if stack B exists */
	if (lst_b)
	{
		t_lnk *softmin_b = get_softmin(lst_b);
		if (softmin_b)
			data->softmin_b = softmin_b->rank;
		else
			data->softmin_b = -1;
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
