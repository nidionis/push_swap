/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ranks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:19:58 by supersko          #+#    #+#             */
/*   Updated: 2025/03/07 21:33:10 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/**
 * @brief Boucle auxiliaire pour l'initialisation des rangs
 * 
 * @param lnk Élément courant
 * @param l_i Élément d'itération
 * @param max Pointeur vers le rang maximum
 */
void	loop(t_lnk *lnk, t_lnk *l_i, int *max)
{
	if (lnk->nb > l_i->nb)
	{
		(lnk->rank)++;
		if (*max < lnk->rank)
			*max = lnk->rank;
	}
	l_i = l_i->next;
	while (l_i != lnk)
	{
		if (lnk->nb > l_i->nb)
		{
			(lnk->rank)++;
			if (*max < lnk->rank)
				*max = lnk->rank;
		}
		l_i = l_i->next;
	}
}

/**
 * @brief Initialise les rangs dans une liste chaînée
 * 
 * @param lst Liste à initialiser
 * @return int Rang maximum
 */
int	lst_init_ranks(t_lnk **lst)
{
	t_lnk	*lnk;
	t_lnk	*l_i;
	int		max;

	lnk = *lst;
	max = 0;
	l_i = lnk;
	loop(lnk, l_i, &max);
	lnk = lnk->next;
	while (lnk != *lst)
	{
		l_i = lnk;
		loop(lnk, l_i, &max);
		lnk = lnk->next;
	}
	return (max);
}
