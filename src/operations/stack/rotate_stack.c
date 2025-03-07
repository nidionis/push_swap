/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 21:16:34 by supersko          #+#    #+#             */
/*   Updated: 2025/03/07 21:13:20 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/**
 * @brief Effectue une rotation de la pile A uniquement
 * 
 * @param lst_a Pointeur vers la pile A
 * @param lst_b Pointeur vers la pile B (non utilisé)
 */
void	rotate_a(t_lnk **lst_a, t_lnk **lst_b)
{
	(void)lst_b;
	if (*lst_a)
		*lst_a = (*lst_a)->next;
}

/**
 * @brief Effectue une rotation de la pile B uniquement
 * 
 * @param lst_a Pointeur vers la pile A (non utilisé)
 * @param lst_b Pointeur vers la pile B
 */
void	rotate_b(t_lnk **lst_a, t_lnk **lst_b)
{
	(void)lst_a;
	if (*lst_b)
		*lst_b = (*lst_b)->next;
}

/**
 * @brief Effectue une rotation inverse de la pile A uniquement
 * 
 * @param lst_a Pointeur vers la pile A
 * @param lst_b Pointeur vers la pile B (non utilisé)
 */
void	rrotate_a(t_lnk **lst_a, t_lnk **lst_b)
{
	(void)lst_b;
	if (*lst_a)
		*lst_a = (*lst_a)->prev;
}

/**
 * @brief Effectue une rotation inverse de la pile B uniquement
 * 
 * @param lst_a Pointeur vers la pile A (non utilisé)
 * @param lst_b Pointeur vers la pile B
 */
void	rrotate_b(t_lnk **lst_a, t_lnk **lst_b)
{
	(void)lst_a;
	if (*lst_b)
		*lst_b = (*lst_b)->prev;
}
