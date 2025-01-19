/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algobsolete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/01/19 00:41:22 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	can_push(t_lnk *lst_a, t_lnk *lst_b)
{
	if (lst_a->rank > lst_b->rank && (lst_a->prev)->rank < lst_b->rank)
		return (1);
	return (0);
}

void	itm_insert_loop(t_lnk *lst_a, t_lnk *lst_b, int instr, int *best_result)
{
	int	steps;

	steps = 0;
	while (!can_push(lst_a, lst_b))
	{
		apply_instr(instr, &lst_a, &lst_b, 0);
		if (steps >= best_result[1])
			break ;
		steps++;
	}
	if (steps < best_result[1])
	{
		best_result[0] = instr;
		best_result[1] = steps;
	}
}

int	*itm_insert(t_lnk *lst_a, t_lnk *lst_b)
{
	int		instr;
	t_lnk	*lst_a_init;
	t_lnk	*lst_b_init;
	int		*best_result;

	best_result = malloc(sizeof(int) * 2);
	if (!best_result)
		ft_errmsg("[itm_insert] did not malloc");
	best_result[1] = 2147483647;
	instr = ra;
	lst_a_init = lst_a;
	lst_b_init = lst_b;
	if (!can_push(lst_a, lst_b))
	{
		while (instr <= rrr)
		{
			itm_insert_loop(lst_a, lst_b, instr, best_result);
			lst_a = lst_a_init;
			lst_b = lst_b_init;
			instr++;
		}
	}
	return (best_result);
}

int	refresh_best_combs(int *best_comb, int instr, int steps, \
	int	*instr_steps_itm)
{
	int	steps_max;

	steps_max = best_comb[1] + best_comb[3];
	if (instr_steps_itm[1] + steps < steps_max)
	{
		best_comb[0] = instr;
		best_comb[1] = steps;
		best_comb[2] = instr_steps_itm[0];
		best_comb[3] = instr_steps_itm[1];
	}
	free(instr_steps_itm);
	return (best_comb[1] + best_comb[3]);
}

void	refresh_in_dir(t_lnk *lst_a, t_lnk *lst_b, int instr, \
	int *best_comb)
{
	int		steps;
	int		steps_max;
	int		*instr_steps_item;

	steps = 0;
	steps_max = best_comb[1] + best_comb[3];
	while (++steps < steps_max)
	{
		apply_instr(instr, &lst_a, &lst_b, 0);
		instr_steps_item = itm_insert(lst_a, lst_b);
		steps_max = refresh_best_combs(best_comb, instr, steps, \
			instr_steps_item);
	}
}
