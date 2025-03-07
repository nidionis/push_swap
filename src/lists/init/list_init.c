/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:19:58 by supersko          #+#    #+#             */
/*   Updated: 2025/03/07 21:32:40 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/**
 * @brief Initialise une liste chaînée circulaire
 * 
 * @param lnk Élément à initialiser
 * @return t_lnk* Élément initialisé
 */
t_lnk	*lnk_init(t_lnk *lnk)
{
	if (lnk)
	{
		lnk->next = lnk;
		lnk->prev = lnk;
	}
	else
		ft_errmsg("[lnk_init] NULL passed in params");
	return (lnk);
}

/**
 * @brief Crée un nouvel élément de liste chaînée
 * 
 * @param nb Valeur
 * @param ind Index
 * @param rank Rang
 * @return t_lnk* Nouvel élément
 */
t_lnk	*ft_new_lnk(int nb, int ind, int rank)
{
	t_lnk		*lnk;

	lnk = (t_lnk *) malloc(sizeof(t_lnk));
	if (!lnk)
		ft_errmsg("Error creating a new link\n");
	lnk->nb = nb;
	lnk->ind = ind;
	lnk->rank = rank;
	lnk_init(lnk);
	return (lnk);
}

/**
 * @brief Supprime une liste chaînée et libère la mémoire
 * 
 * @param lst Liste à supprimer
 */
void	del_lst(t_lnk **lst)
{
	t_lnk	*next_lnk;
	t_lnk	*first_lnk;

	if (*lst && (*lst)->next != *lst)
	{
		first_lnk = *lst;
		while ((*lst)->next != first_lnk)
		{
			next_lnk = (*lst)->next;
			free(*lst);
			*lst = next_lnk;
		}
	}
	if (*lst)
	{
		free(*lst);
		*lst = NULL;
	}
}
