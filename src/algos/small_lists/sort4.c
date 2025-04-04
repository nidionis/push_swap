/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/04/04 16:19:12 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

// int	sort_4_nb(t_data *d)
//{
//	int	nb_instr;
//	int	way;
//	int	r_instr;
//
//	nb_instr = 0;
//	if (is_sorted_a_n_nexts(d->a, 4))
//        return (reach_rank_a(d, 0, PRINT));
//	way = get_shortestway(4, d->a.lst);
//	r_instr = ra;
//	if (way == RROTATE)
//		r_instr = rra;
//	while (head(&d->a) != 4 && !is_sorted_a_n_nexts(d->a, 4))
//	{
//		if (should_swap_a(&d->a))
//			nb_instr = apply_instr(d, sa, PRINT);
//		if (head(&d->a) != 4 && !is_sorted_a_n_nexts(d->a, 4))
//			nb_instr = apply_instr(d, r_instr, PRINT);
//	}
//    nb_instr += reach_rank_a(d, 0, PRINT);
//	return (nb_instr);
//}

int	sort_4_nb(t_data *d)
{
	int	nb_instr;
	int	r_instr[12];

	nb_instr = 0;
	if (!is_sorted_a_n_nexts(d->a, 4))
	{
		if (should_swap_a(&d->b))
			nb_instr += apply_instr(d, sa, PRINT);
		if (!is_sorted_a_n_nexts(d->a, 4))
			nb_instr = apply_instr(d, pb, PRINT);
		nb_instr += sort_3_nexts_a(d);
	}
	rotate_a_instr(r_instr);
	nb_instr += dump_b_basic(d, r_instr, PRINT);
	reach_rank_a(d, 0, PRINT);
	return (nb_instr);
}
