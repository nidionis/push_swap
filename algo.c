/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/01/26 23:43:21 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	can_push_b()
{
	if (!d.lst_a)
		return (FALSE);
	if (!d.lst_b)
		return (TRUE);
	if (d.lst_b->rank > d.lst_a->rank && (d.lst_b->prev)->rank < d.lst_a->rank)
		return (TRUE);
	if (d.softmax_b == UNSET)
		return (TRUE);
	if (d.lst_b->rank == d.min_b && (d.lst_a->rank < d.min_b || d.lst_a->rank > d.max_b))
		return (TRUE);
	return (FALSE);
}

int	can_push_a()
{
	if (!d.lst_b)
		return (FALSE);
	if (!d.lst_a)
		return (TRUE);
	if (d.lst_a->rank > d.lst_b->rank && (d.lst_a->prev)->rank < d.lst_b->rank)
		return (TRUE);
	if (d.softmax_a == UNSET)
		return (TRUE);
	if (d.lst_a->rank == d.min_a && (d.lst_b->rank < d.min_a || d.lst_b->rank > d.max_a))
		return (TRUE);
	return (FALSE);
}

void save_best_instr(int instr_steps_itm[2])
{
	d.best_inst_step[FIRST_INSTR] = instr_steps_itm[FIRST_INSTR];
	d.best_inst_step[NB_FIRST_INSTR] = instr_steps_itm[NB_FIRST_INSTR];
}

void	insert_target(t_lnk *target, int way)
{
	int instr;
	t_lnk *lst_b_tmp;
	int	instr_steps_itm[2];

	(void)target;
	lst_b_tmp = d.lst_b;
	instr = 0;
	d.best_inst_step[NB_FIRST_INSTR] = INT_MAX;
	instr_steps_itm[FIRST_INSTR] = 0;
	instr_steps_itm[NB_FIRST_INSTR] = 0;
	while (instr < 4)
	{
		instr_steps_itm[FIRST_INSTR] = d.rotate_instr[way][instr];
		instr_steps_itm[NB_FIRST_INSTR] = 0;
		if (can_push_b(d.lst_a, lst_b_tmp))
		{
			save_best_instr(instr_steps_itm);
			return ;
		}
		lst_b_tmp = lst_b_tmp->next;
		while (!can_push_b(d.lst_a, lst_b_tmp) && lst_b_tmp != d.lst_b)
		{

			apply_instr(d.rotate_instr[way][instr], QUIET);
		}
		++instr;
		lst_b_tmp = d.lst_b;
	}
}