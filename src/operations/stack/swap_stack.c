/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/03/07 21:16:30 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/**
 * @brief Échange les deux premiers éléments de la pile A
 * 
 * @param lst_a Pointeur vers la pile A
 * @param lst_b Pointeur vers la pile B (non utilisé)
 */
void	swap_a(t_lnk **lst_a, t_lnk **lst_b)
{
	(void)lst_b;
	swap_lst(lst_a);
}

/**
 * @brief Échange les deux premiers éléments de la pile B
 * 
 * @param lst_a Pointeur vers la pile A (non utilisé)
 * @param lst_b Pointeur vers la pile B
 */
void	swap_b(t_lnk **lst_a, t_lnk **lst_b)
{
	(void)lst_a;
	swap_lst(lst_b);
}
