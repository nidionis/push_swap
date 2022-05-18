/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gather_min_and_max.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/18 23:13:44 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

//gather min and max
void	first_parse(t_lnk **lst_a, t_lnk **lst_b, int ind_max, t_lnk *RelMinMax[2])
{
	int	instr_way;

	instr_way = ra;
	reach_rank(lst_a, 0, get_shortestway(0, *lst_a));
	ft_is_sorted(*lst_a);
	if (get_shortestway(ind_max, *lst_a) < 0)
		instr_way = rra;
	apply_instr(pb, lst_a, lst_b, 1);
	reach_push(lst_a, lst_b, ind_max, instr_way, RelMinMax);
	apply_instr(pb, lst_a, lst_b, 1);
	apply_instr(rrb, lst_a, lst_b, 1);
	apply_instr(pa, lst_a, lst_b, 1);
	apply_instr(pa, lst_a, lst_b, 1);
	dump_relMax(lst_a, lst_b);
	while (*lst_b)
		apply_instr(pa, lst_a, lst_b, 1);
}