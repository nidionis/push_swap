/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dumping_fts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/19 01:03:40 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	dump_relMax(t_lnk **lst_a, t_lnk **lst_b) 
{
 	while (*lst_b)
	 {
		if ((*lst_b)->rank < (*lst_a)->prev->rank)
		{
			while ((*lst_b)->rank < (*lst_a)->prev->rank && (*lst_b)->rank)
				apply_instr(rra, lst_a, lst_b, 1);
		}
		apply_instr(pa, lst_a, lst_b, 1);
	 }
}

//void	dump_relMin(t_lnk **lst_a, t_lnk **lst_b) 
//{
// 	while (*lst_b)
//	 {
//		if ((*lst_b)->rank > (*lst_a)->next->rank)
//			while ((*lst_b)->rank > (*lst_a)->next->rank)
//				apply_instr(ra, lst_a, lst_b, 1);
//		apply_instr(pa, lst_a, lst_b, 1);
//	 }
//}