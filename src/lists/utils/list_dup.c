/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_dup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 00:50:00 by nidionis          #+#    #+#             */
/*   Updated: 2025/03/08 00:50:00 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/**
 * @brief Duplique un nœud de liste chaînée
 * 
 * @param node Nœud à dupliquer
 * @return t_lnk* Nouveau nœud
 */
t_lnk	*ft_dlstnewdup(t_lnk *node)
{
	t_lnk	*new;

	if (!node)
		return (NULL);
	new = (t_lnk *)malloc(sizeof(t_lnk));
	if (!new)
		return (NULL);
	new->rank = node->rank;
	new->ind = node->ind;  /* Conserver ind pour la cohérence */
	new->nb = 0;          /* nb n'est pas utilisé après le parsing */
	new->next = new;
	new->prev = new;
	return (new);
}

/**
 * @brief Duplique une liste chaînée circulaire doublement liée
 * 
 * @param lst Liste à dupliquer
 * @return t_lnk* Nouvelle liste
 */
t_lnk	*ft_dlstdup(t_lnk *lst)
{
	t_lnk	*new_list;
	t_lnk	*current;
	t_lnk	*new_node;
	t_lnk	*temp;

	if (!lst)
		return (NULL);
	
	// Créer le premier nœud
	new_list = ft_dlstnewdup(lst);
	if (!new_list)
		return (NULL);
	
	// Parcourir le reste de la liste
	current = lst->next;
	temp = new_list;
	
	while (current != lst)
	{
		new_node = ft_dlstnewdup(current);
		if (!new_node)
		{
			ft_dlstclear(&new_list);
			return (NULL);
		}
		
		// Insérer le nouveau nœud à la fin de la nouvelle liste
		new_node->prev = temp;
		new_node->next = new_list;
		temp->next = new_node;
		new_list->prev = new_node;
		
		temp = new_node;
		current = current->next;
	}
	
	return (new_list);
}

/**
 * @brief Libère une liste chaînée circulaire
 * 
 * @param lst Pointeur vers la liste à libérer
 */
void	ft_dlstclear(t_lnk **lst)
{
	t_lnk	*current;
	t_lnk	*next;
	t_lnk	*start;

	if (!lst || !*lst)
		return;
	
	start = *lst;
	current = start;
	
	// Parcourir la liste circulaire
	do {
		next = current->next;
		free(current);
		current = next;
	} while (current != start);
	
	*lst = NULL;
}
