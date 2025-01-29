/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/01/29 03:07:33 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	can_push_b(t_data *data, t_lnk *lst_a, t_lnk *lst_b)
{
	if (!lst_a)
		return (FALSE);
	if (!lst_b)
		return (TRUE);
	if (data->softmax_b == UNSET)
		return (TRUE);
	if (lst_a->rank > lst_b->rank && ((lst_b->prev)->rank > lst_a->rank))// && lst_b->rank != data->min_b))
		return (TRUE);
	if (lst_b->rank == data->max_b && (lst_a->rank > data->max_b || lst_a->rank < data->min_b))
		return (TRUE);
	return (FALSE);
}

int	can_push_a(t_data *data, t_lnk *lst_a, t_lnk *lst_b)
{
	if (!lst_b)
		return (FALSE);
	if (!lst_a)
		return (TRUE);
	if (data->softmax_a == UNSET)
		return (TRUE);
	if (lst_a->rank > lst_b->rank && (lst_a->prev)->rank < lst_b->rank)
		return (TRUE);
	if (lst_a->rank == data->min_a && (lst_b->rank < data->min_a || lst_b->rank > data->max_a))
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

int count_instr(t_data *data, t_lnk *lst_a, t_lnk *lst_b, int instr, int (*can_push)(t_data *data, t_lnk *lst_a, t_lnk *lst_b))
{
	int count;
	int max;
	t_lnk *orig_a;
	t_lnk *orig_b;

	count = 0;
	orig_a = lst_a;
	orig_b = lst_b;
	max = ft_lstsize(orig_a) + ft_lstsize(orig_b); // yolo
	while (!can_push(data, lst_a, lst_b) && count < max)
	{
		apply_instr(data, &lst_a, &lst_b, instr, QUIET);
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

void print_instr_steps(int instr_steps_itm[2])
{
	printf("instr %d nb_instr %d\n", instr_steps_itm[INSTR], instr_steps_itm[NB_INSTR]);
}

void apply_instr_step_itm_test(t_lnk **lst_a, t_lnk **lst_b, int **instr_steps_itm_addr, int verbose)
{
	int *instr_steps_itm;

	instr_steps_itm = *instr_steps_itm_addr;
	if (instr_steps_itm[NB_INSTR] != CANT_INSERT)
		while (instr_steps_itm[NB_INSTR]--)
			apply_instr(&d, lst_a, lst_b, instr_steps_itm[INSTR], verbose);
	free(instr_steps_itm);
	instr_steps_itm = NULL;
}

void apply_instr_step_itm(int **instr_steps_itm_addr)
{
	apply_instr_step_itm_test(&d.lst_a, &d.lst_b, instr_steps_itm_addr, PRINT);
}

int	*insert_target_to_list_steps(t_lnk *lst_a, t_lnk *lst_b, int lst_instr[], int (*can_push)(t_data *data, t_lnk *lst_a, t_lnk *lst_b))
{
	int i_instr;
	int	*instr_steps_itm;
	int instr;
	t_data data;

	i_instr = 0;
	set_data(&data, &lst_a, &lst_b);
	instr = lst_instr[i_instr];
	instr_steps_itm = malloc(2 * sizeof(int));
	set_instr_step_itm(instr, instr_steps_itm);
	if (can_push(&data, lst_a, lst_b))
	{
		update_best_instr(instr_steps_itm);
		return (instr_steps_itm);
	}
	while (instr != LOOP_END)
	{
		set_instr_step_itm(instr, instr_steps_itm);
		instr_steps_itm[NB_INSTR] = count_instr(&data, lst_a, lst_b, instr, can_push);
		update_best_instr(instr_steps_itm);
		instr = lst_instr[i_instr++];
	}
	return (instr_steps_itm);
}