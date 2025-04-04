/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/04/04 15:42:02 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	sort_4_nb(t_data *d)
{
	int	nb_instr;
	int	way;
	int	r_instr;

	nb_instr = 0;
	if (is_sorted_a_n_nexts(d->a, 4))
		return (0);
	way = get_shortestway(4, d->a.lst);
	r_instr = ra;
	if (way == RROTATE)
		r_instr = rra;
	while (head(&d->a) != 4 && !is_sorted_a_n_nexts(d->a, 4))
	{
		if (should_swap_a(&d->a))
			nb_instr = apply_instr(d, sa, PRINT);
		if (head(&d->a) != 4 && !is_sorted_a_n_nexts(d->a, 4))
			nb_instr = apply_instr(d, r_instr, PRINT);
	}
	return (nb_instr);
}
