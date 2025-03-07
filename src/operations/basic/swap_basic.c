/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/03/07 21:15:20 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/**
 * @brief Échange les deux premiers éléments d'une liste chaînée
 * 
 * @param lst Liste à modifier
 */
void	swap_lst(t_lnk **lst)
{
	t_lnk	*sec;

	if (*lst && (*lst)->next != *lst)
	{	
		sec = (*lst)->next;
		if (sec->next != *lst)
		{
			((*lst)->prev)->next = sec;
			(sec->next)->prev = *lst;
			sec->prev = (*lst)->prev;
			(*lst)->prev = sec;
			(*lst)->next = sec->next;
			sec->next = *lst;
			*lst = sec;
		}
		else
			rotate_lst(lst);
	}
}

/**
 * @brief Échange les deux premiers éléments des deux piles simultanément
 * 
 * @param lst_a Pointeur vers la pile A
 * @param lst_b Pointeur vers la pile B
 */
void	swap_both(t_lnk **lst_a, t_lnk **lst_b)
{
	swap_lst(lst_a);
	swap_lst(lst_b);
}
