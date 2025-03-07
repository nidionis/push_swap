/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 21:16:34 by supersko          #+#    #+#             */
/*   Updated: 2025/03/07 21:14:10 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/**
 * @brief Pousse un élément d'une liste à une autre
 * 
 * @param from_lst Liste source
 * @param to_lst Liste destination
 */
void	push(t_lnk **from_lst, t_lnk **to_lst)
{
	push_item(pop_item(from_lst), to_lst);
}

/**
 * @brief Ajoute un élément à une liste chaînée
 * 
 * @param lnk Élément à ajouter
 * @param lst Liste cible
 */
void	push_item(t_lnk *lnk, t_lnk **lst)
{
	if (lnk)
	{
		if (*lst == NULL)
			*lst = lnk_init(lnk);
		else
		{
			lnk->next = *lst;
			lnk->prev = (*lst)->prev;
			((*lst)->prev)->next = lnk;
			(*lst)->prev = lnk;
			(*lst) = lnk;
		}
	}
	if (!lnk)
		printf("[push item] pushing non existing link\n");
}

/**
 * @brief Extrait un élément d'une liste chaînée
 * 
 * @param lst Liste source
 * @return t_lnk* Élément extrait
 */
t_lnk	*pop_item(t_lnk **lst)
{
	t_lnk	*poped_item;

	poped_item = *lst;
	if (*lst == NULL)
		return (NULL);
	else if ((*lst)->next == *lst)
		*lst = NULL;
	else
	{
		(poped_item->prev)->next = poped_item->next;
		(poped_item->next)->prev = poped_item->prev;
		*lst = (*lst)->next;
	}
	return (lnk_init(poped_item));
}
