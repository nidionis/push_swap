/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_minmax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 21:16:34 by supersko          #+#    #+#             */
/*   Updated: 2025/03/07 21:17:40 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/**
 * @brief Trouve l'élément avec le rang le plus élevé dans la liste chaînée
 * 
 * @param lst Liste chaînée à analyser
 * @return t_lnk* Pointeur vers l'élément avec le rang maximum
 */
t_lnk	*get_max(t_lnk *lst)
{
	t_lnk	*tmp;
	t_lnk	*max;

	tmp = lst;
	max = lst;
	if (!lst)
		return (NULL);
	tmp = tmp->next;
	while (tmp != lst)
	{
		if (tmp->rank > max->rank)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

/**
 * @brief Trouve l'élément avec le rang le plus bas dans la liste chaînée
 * 
 * @param lst Liste chaînée à analyser
 * @return t_lnk* Pointeur vers l'élément avec le rang minimum
 */
t_lnk	*get_min(t_lnk *lst)
{
	t_lnk	*tmp;
	t_lnk	*min;

	tmp = lst;
	min = lst;
	if (!lst)
		return (NULL);
	tmp = tmp->next;
	while (tmp != lst)
	{
		if (tmp->rank < min->rank)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}
