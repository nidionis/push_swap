/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algobsolete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/01/20 13:02:26 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	can_push_a(t_lnk *lst_a, t_lnk *lst_b)
{
	if (lst_a->rank > lst_b->rank && (lst_a->prev)->rank < lst_b->rank)
		return (TRUE);
	return (FALSE);
}

int is_rotate_instr(int instr)
{
	if (instr == ra || instr == rra || instr == rr)
		return (TRUE);
	if (instr == rb || instr == rrb || instr == rrr)
		return (TRUE);
	return (FALSE);
}

int	can_push_b(t_lnk *lst_a, t_lnk *lst_b)
{

	if (lst_a->rank > lst_b->rank && (lst_a->prev)->rank < lst_b->rank)
		return (TRUE);
	return (FALSE);
}

void	itm_insert_loop(t_lnk *lst_a, t_lnk *lst_b, int instr, int *best_result)
{
	int	steps;

	steps = 0;
	while (!can_push_b(lst_a, lst_b))
	{
		if (is_rotate_instr(instr))
			apply_instr(instr, &lst_a, &lst_b, QUIET);
		if (steps >= best_result[NB_FIRST_INSTR])
			break ;
		steps++;
	}
	if (steps < best_result[NB_FIRST_INSTR])
	{
		best_result[NB_FIRST_INSTR] = instr;
		best_result[FIRST_INSTR] = steps;
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
	best_result[NB_FIRST_INSTR] = 2147483647;
	instr = ROTATE_MIN;
	lst_a_init = lst_a;
	lst_b_init = lst_b;
	if (!can_push_b(lst_a, lst_b))
	{
		while (instr <= ROTATE_MAX)
		{
			if (is_rotate_instr(instr))
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

	steps_max = best_comb[NB_FIRST_INSTR] + best_comb[NB_SECOND_INSTR];
	if (instr_steps_itm[NB_FIRST_INSTR] + steps < steps_max)
	{
		best_comb[FIRST_INSTR] = instr;
		best_comb[NB_FIRST_INSTR] = steps;
		best_comb[SECOND_INSTR] = instr_steps_itm[FIRST_INSTR];
		best_comb[NB_SECOND_INSTR] = instr_steps_itm[NB_FIRST_INSTR];
	}
	free(instr_steps_itm);
	return (best_comb[NB_FIRST_INSTR] + best_comb[NB_SECOND_INSTR]); //initialement non NB_X mais X
}

void	refresh_in_dir(t_lnk *lst_a, t_lnk *lst_b, int instr, \
	int *best_comb)
{
	int		steps;
	int		steps_max;
	int		*instr_steps_item;

	steps = 0;
	steps_max = best_comb[NB_FIRST_INSTR] + best_comb[NB_SECOND_INSTR];
	while (++steps < steps_max)
	{
		if (is_rotate_instr(instr))
		{
			apply_instr(instr, &lst_a, &lst_b, QUIET);
			instr_steps_item = itm_insert(lst_a, lst_b);
			steps_max = refresh_best_combs(best_comb, instr, steps, \
				instr_steps_item);
		}
	}
}
