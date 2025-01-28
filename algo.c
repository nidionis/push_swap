/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/01/29 00:43:55 by nidionis         ###   ########.fr       */
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
	if (instr_steps_itm[NB_INSTR] < d.best_inst_step[NB_INSTR])
	{
		d.best_inst_step[INSTR] = instr_steps_itm[INSTR];
		d.best_inst_step[NB_INSTR] = instr_steps_itm[NB_INSTR];
	}
}

void set_instr_step_itm(int instr, int instr_steps_itm[2])
{
	instr_steps_itm[INSTR] = instr;
	instr_steps_itm[NB_INSTR] = 0;
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

int count_instr(t_lnk *lst_a, t_lnk *lst_b, int instr, int (*can_push)(t_lnk *lst_a, t_lnk *lst_b))
{
	int count;
	int max;
	t_lnk *orig_a;
	t_lnk *orig_b;

	count = 0;
	orig_a = lst_a;
	orig_b = lst_b;
	max = ft_lstsize(orig_a) + ft_lstsize(orig_b); // yolo
	while (!can_push(lst_a, lst_b) && count < max)
	{
		apply_instr(&lst_a, &lst_b, instr, QUIET);
		count++;
	}
	if (count == max)
	{
		return (CANT_INSERT);
	}
	return (count);
}

int ft_lstsize(t_lnk *lst)
{
	int count;
	t_lnk *orig;

	if (!lst)
		return (0);
	count = 1;
	orig = lst;
	lst = lst->next;
	while (lst != orig)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

int	*insert_target_to_list_steps(t_lnk *lst_a, t_lnk *lst_b, int lst_instr[], int (*can_push)(t_lnk *lst_a, t_lnk *lst_b))
{
	int i_instr;
	int	*instr_steps_itm;
	int instr;

	instr_steps_itm = malloc(2 * sizeof(int));
	if (can_push(lst_a, lst_b))
	{
		update_best_instr(instr_steps_itm);
		return (instr_steps_itm);
	}
	i_instr = 0;
	instr = lst_instr[i_instr];
	while (instr != LOOP_END)
	{
		instr_steps_itm[INSTR] = instr;
		instr_steps_itm[NB_INSTR] = 0;
		set_instr_step_itm(instr, instr_steps_itm);
		instr_steps_itm[NB_INSTR] = count_instr(lst_a, lst_b, instr, can_push);
		update_best_instr(instr_steps_itm);
		++i_instr;
		instr = lst_instr[i_instr];
	}
	return (instr_steps_itm);
}