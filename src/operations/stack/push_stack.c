/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 21:16:34 by supersko          #+#    #+#             */
/*   Updated: 2025/03/07 21:14:40 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/**
 * @brief Pousse un élément de la pile B vers la pile A
 * 
 * @param lst_a Pointeur vers la pile A
 * @param lst_b Pointeur vers la pile B
 */
void	push_a(t_lnk **lst_a, t_lnk **lst_b)
{
	if (*lst_b)
		push(lst_b, lst_a);
}

/**
 * @brief Pousse un élément de la pile A vers la pile B
 * 
 * @param lst_a Pointeur vers la pile A
 * @param lst_b Pointeur vers la pile B
 */
void	push_b(t_lnk **lst_a, t_lnk **lst_b)
{
	if (*lst_a)
		push(lst_a, lst_b);
}
