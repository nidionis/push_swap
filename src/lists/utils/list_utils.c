/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:19:58 by supersko          #+#    #+#             */
/*   Updated: 2025/03/07 21:34:15 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/**
 * @brief Calcule la taille d'une liste chaînée circulaire doublement liée
 * 
 * @param lst Liste à mesurer
 * @return int Nombre d'éléments
 */
int	ft_dlstsize(t_lnk *lst)
{
	int		i;
	t_lnk	*lnk;

	i = 1;
	lnk = lst;
	if (!lnk)
		return (0);
	while (lnk->next != lst)
	{
		i++;
		lnk = lnk->next;
	}
	return (i);
}

/**
 * @brief Alias de ft_dlstsize pour la cohérence avec le reste du code
 * 
 * @param lst Liste à mesurer
 * @return int Nombre d'éléments
 */
int	lnk_lstlen(t_lnk *lst)
{
	return (ft_dlstsize(lst));
}
