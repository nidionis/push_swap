/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reach_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */

/*   Created: 2022/04/07 19:47:40 by supersko          #+#    #+#             */
/*   Updated: 2022/05/19 22:13:45 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//static t_lnk	**parse_down_loop(t_lnk **lst_a, t_lnk **lst_b, t_lnk **relMinMax)
//{
//	if ((*lst_a)->next->rank < (*lst_a)->rank)
//	{
//		apply_instr(sa, lst_a, lst_b, 1);
//		if ((*lst_a)->next->next == relMinMax[1])
//		{
//			relMinMax = refresh_RelMinMax(relMinMax);
//			if ((*lst_a)->rank > relMinMax[1]->rank || (*lst_a)->rank < relMinMax[0]->rank)
//				recentrer(lst_a, relMinMax);
//		}
//	}
//	else if (!(*lst_b))
//		apply_instr(pb, lst_a, lst_b, 1);
//	else if ((*lst_a)->rank > (*lst_b)->rank)
//		apply_instr(pb, lst_a, lst_b, 1);
//	else if ((*lst_b)->next != *lst_b && (*lst_a)->rank < (*lst_b)->prev->rank)
//	{
//		apply_instr(pb, lst_a, lst_b, 1);
//		if ((*lst_b)->next->rank > (*lst_b)->rank)
//			apply_instr(rb, lst_a, lst_b, 1);
//	}
//	else
//		apply_instr(ra, lst_a, lst_b, 1);
//	return (relMinMax);
//}
//
//static t_lnk **amorce_parse_down_loop(t_lnk **lst_a, t_lnk **lst_b, t_lnk **relMinMax)
//{
//	if ((*lst_a)->next->rank < (*lst_a)->rank)
//	{
//		apply_instr(sa, lst_a, lst_b, 1);
//		if ((*lst_a)->next->next == relMinMax[1])
//		{
//			relMinMax = refresh_RelMinMax(relMinMax);
//			if ((*lst_a)->rank > relMinMax[1]->rank || (*lst_a)->rank < relMinMax[0]->rank)
//				recentrer(lst_a, relMinMax);
//		}
//	}
//	else if (!(*lst_b) || (*lst_a)->rank > (*lst_b)->rank)
//    {
//		apply_instr(pb, lst_a, lst_b, 1);
//        relMinMax = recentrer(lst_a, relMinMax);
//    }
//	else if ((*lst_a) != relMinMax[1])
//		apply_instr(ra, lst_a, lst_b, 1);
//	return (relMinMax);
//}

// start on relMax lst_b empty
t_lnk	**parse_up(t_lnk **lst_a, t_lnk **lst_b, t_lnk	*relMinMax[2])
{
    relMinMax = recentrer(lst_a, relMinMax);
    dump_relMax(lst_a, lst_b);
	return (relMinMax);
}