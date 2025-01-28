/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/01/29 00:00:03 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	can_push_b()
{
	if (!d.lst_a)
		return (FALSE);
	if (!d.lst_b)
		return (TRUE);
	if (d.softmax_b == UNSET)
		return (TRUE);
	if (d.lst_b->rank < d.lst_a->rank && (d.lst_b->prev)->rank > d.lst_a->rank)
		return (TRUE);
	if (d.lst_b->rank == d.max_b && (d.lst_a->rank > d.max_b || d.lst_a->rank < d.min_b))
		return (TRUE);
	return (FALSE);
}

int	can_push_a()
{
	if (!d.lst_b)
		return (FALSE);
	if (!d.lst_a)
		return (TRUE);
	if (d.softmax_a == UNSET)
		return (TRUE);
	if (d.lst_a->rank > d.lst_b->rank && (d.lst_a->prev)->rank < d.lst_b->rank)
		return (TRUE);
	if (d.lst_a->rank == d.min_a && (d.lst_b->rank < d.min_a || d.lst_b->rank > d.max_a))
		return (TRUE);
	return (FALSE);
}

void	update_best_instr(int instr_steps_itm[2])
{
	if (instr_steps_itm[NB_FIRST_INSTR] < d.best_inst_step[NB_FIRST_INSTR])
	{
		d.best_inst_step[FIRST_INSTR] = instr_steps_itm[FIRST_INSTR];
		d.best_inst_step[NB_FIRST_INSTR] = instr_steps_itm[NB_FIRST_INSTR];
	}
}

void set_instr_step_itm(int instr, int instr_steps_itm[2])
{
	instr_steps_itm[FIRST_INSTR] = instr;
	instr_steps_itm[NB_FIRST_INSTR] = 0;
}

int opposite_instr(int instr)
{
	if (instr == ra)
		return (rra);
	if (instr == rb)
		return (rrb);
	if (instr == rra)
		return (ra);
	if (instr == rrb)
		return (rb);
	if (instr == rr)
		return (rrr);
	if (instr == rrr)
		return (rr);
	return (-42);
}

void	insert_target_to_list_steps(t_lnk *target, t_lnk *lst, int lst_instr[], int (*can_push)(t_lnk *lst_a, t_lnk *lst_b))
{
	int i_instr;
	t_lnk *lst_orig;
	int	instr_steps_itm[2];

	(void)target;
	lst_orig = lst;
	i_instr = 0;
	instr_steps_itm[FIRST_INSTR] = lst_instr[0];
	instr_steps_itm[NB_FIRST_INSTR] = 0;
	if (can_push(target, lst))
	{
		update_best_instr(instr_steps_itm);
		return ;
	}
	while (lst_instr[i_instr] != LOOP_END)
	{
		set_instr_step_itm(lst_instr[i_instr], instr_steps_itm);
		apply_instr(&d.lst_a, &d.lst_b, lst_instr[i_instr], QUIET);
		instr_steps_itm[FIRST_INSTR]++;
		while (lst_orig != lst)
		{
			if (can_push(d.lst_a, d.lst_b))
				break;
			apply_instr(&d.lst_a, &d.lst_b, lst_instr[i_instr], QUIET);
			instr_steps_itm[FIRST_INSTR]++;
		}
		update_best_instr(instr_steps_itm);
		++i_instr;
		lst_orig = d.lst_b;
	}
}