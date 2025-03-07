/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_basic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 21:16:34 by supersko          #+#    #+#             */
/*   Updated: 2025/03/07 21:12:30 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/**
 * @brief Effectue une rotation vers le haut d'une liste chaînée
 * 
 * @param lst Pointeur vers la liste à faire tourner
 */
void	rotate_lst(t_lnk **lst)
{
	if (*lst)
		*lst = (*lst)->next;
	else
		write(2, "[rotate] empty list\n", 20);
}

/**
 * @brief Effectue une rotation vers le bas d'une liste chaînée
 * 
 * @param lst Pointeur vers la liste à faire tourner
 */
void	rrotate_lst(t_lnk **lst)
{
	if (*lst)
		*lst = (*lst)->prev;
	else
		write(2, "[rotate] empty list\n", 20);
}

/**
 * @brief Effectue une rotation des deux piles simultanément
 * 
 * @param lst_a Pointeur vers la pile A
 * @param lst_b Pointeur vers la pile B
 */
void	rotate_both(t_lnk **lst_a, t_lnk **lst_b)
{
	if (*lst_a)
		rotate_lst(lst_a);
	if (*lst_b)
		rotate_lst(lst_b);
}

/**
 * @brief Effectue une rotation inverse des deux piles simultanément
 * 
 * @param lst_a Pointeur vers la pile A
 * @param lst_b Pointeur vers la pile B
 */
void	rrotate_both(t_lnk **lst_a, t_lnk **lst_b)
{
	if (*lst_a)
		rrotate_lst(lst_a);
	if (*lst_b)
		rrotate_lst(lst_b);
}
