/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/01/30 22:39:15 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int load_b_low_and_max(t_data *data, t_lnk *a, t_lnk *b)
{
	if (ft_lstsize(b) > 2)
		if (a->rank == data->rank_max && b->prev->rank == data->min_b)
			return (TRUE);
	if (a->rank > data->rank_max / 2)
		return (FALSE);
	return (load_b_minmax(data, a, b));
}

int	load_b_but_softmax_and_hight(t_data *data, t_lnk *a, t_lnk *b)
{
	if (a->rank > data->softmax_a / 2)
		return (FALSE);
	if (a->rank <= data->softmin_a)
		return (FALSE);
	return (load_b_minmax(data, a, b));
}

int	load_b_but_softmins_and_low(t_data *data, t_lnk *a, t_lnk *b)
{
	if (a->rank < data->softmin_a / 2)
		return (FALSE);
	if (a->rank >= data->softmax_a)
		return (FALSE);
	return (load_b_minmax(data, a, b));
}

int	load_b_minmax(t_data *data, t_lnk *a, t_lnk *b)
{
	int size_b;

	if (!a)
		return (FALSE);
	if (!b)
		return (TRUE);
	size_b = ft_lstsize(b);
	if (size_b == 1)
		return (TRUE);
	if (size_b == 2)
	{
		if (b->rank == data->max_b)
		{
			if (a->rank > data->max_b || a->rank < data->min_b)
				return (TRUE);
		}
		else if (a->rank > b->rank && b->prev->rank > a->rank)
				return (TRUE);
	}
	else
	{
		if (b->rank == data->max_b)
		{
			if (a->rank > data->max_b)
				return (TRUE);
			if (a->rank < data->min_b)
				return (TRUE);
		}
		else if (b->prev->rank == data->min_b)
		{
			if (a->rank < data->min_b)
				return (TRUE);
			if (a->rank > data->max_b)
				return (TRUE);
		}
		else if (a->rank > b->rank && a->rank < b->prev->rank)
			return (TRUE);
	}
	return (FALSE);
}

int	can_push_a(t_data *data, t_lnk *a, t_lnk *b)
{
	if (!a)
		return (TRUE);
	if (!b)
		return (FALSE);
	if (a->rank == data->softmax_a && b->rank == data->softmax_a - 1)
		return (TRUE);
	if (a->prev->rank == data->softmin_a && b->rank == data->softmin_a + 1)
		return (TRUE);
	return (FALSE);
}

void	update_best_instr(t_data *data, int instr_steps_itm[2])
{
	if (instr_steps_itm[NB_INSTR] < data->best_inst_step[NB_INSTR])
	{
		data->best_inst_step[INSTR] = instr_steps_itm[INSTR];
		data->best_inst_step[NB_INSTR] = instr_steps_itm[NB_INSTR];
		//data->best_cost_instr = ft_cost(data->best_inst_step);
	}
}

void set_instr_step_itm(int instr, int nb_instr,int *instr_steps_itm)
{
	instr_steps_itm[INSTR] = instr;
	instr_steps_itm[NB_INSTR] = nb_instr;
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

	count = 0;
	if (can_push(data, lst_a, lst_b))
		return (0);
	while (!can_push(data, lst_a, lst_b) && count < data->best_cost_comb)
	{
		apply_instr(data, &lst_a, &lst_b, instr, QUIET);
		count++;
	}
	if (count >= data->best_cost_comb)
		return (CANT_INSERT);
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
	int instr = instr_steps_itm[INSTR];

	printf("instr: %i ", instr_steps_itm[NB_INSTR]);
	if (instr == ra)
		printf("ra ");
	else if (instr == rb)
		printf("rb ");
	else if (instr == rra)
		printf("rra ");
	else if (instr == rrb)
		printf("rrb ");
	else if (instr == rr)
		printf("rr ");
	else if (instr == rrr)
		printf("rrr ");
	else if (instr == pa)
		printf("pa ");
	else if (instr == pb)
		printf("pb ");
	else
		printf("%i is weird instruction", instr);
	printf("\n");
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

void load_minmax(t_data *data, int *best_comb)
{
	if (best_comb[FIRST_INSTR] != NO_INSTR)
	{
		while (best_comb[NB_FIRST_INSTR]--)
		{
			if (data->lst_a->rank == data->rank_max || data->lst_a->rank == 0)
			{
				int *best_insert_itm;

				best_insert_itm = insert_target_to_list_steps(data->lst_a, data->lst_b, data->b_only_instr, load_b_minmax, SIZE_MAX);
				apply_instr_step_itm(&best_insert_itm);
				apply_instr(data, &data->lst_a, &data->lst_b, pb, PRINT);
				free(best_comb);
				return ;
			}
			apply_instr(data, &data->lst_a, &data->lst_b, best_comb[FIRST_INSTR], PRINT);
		}
	}
	if (best_comb[SECOND_INSTR] != NO_INSTR)
	{
		while (best_comb[NB_SECOND_INSTR]--)
		{
			if (data->lst_a->rank == data->rank_max || data->lst_a->rank == 0)
			{
				int *best_insert_itm;

				best_insert_itm = insert_target_to_list_steps(data->lst_a, data->lst_b, data->b_only_instr, load_b_minmax, SIZE_MAX);
				apply_instr_step_itm(&best_insert_itm);
				apply_instr(data, &data->lst_a, &data->lst_b, pb, PRINT);
				free(best_comb);
				return ;
			}
			apply_instr(data, &data->lst_a, &data->lst_b, best_comb[SECOND_INSTR], PRINT);
		}
	}
	apply_instr(data, &data->lst_a, &data->lst_b, pb, PRINT);
	free(best_comb);
}

void apply_best_comb_until_softmin(t_data *data, int *best_comb)
{
	if (best_comb[FIRST_INSTR] != NO_INSTR)
	{
		while (best_comb[NB_FIRST_INSTR]--)
		{
			if (data->lst_a->prev->rank == data->softmin_a)
			{
				free(best_comb);
				return ;

			}
			apply_instr(data, &data->lst_a, &data->lst_b, best_comb[FIRST_INSTR], PRINT);
		}
	}
	if (best_comb[SECOND_INSTR] != NO_INSTR)
	{
		while (best_comb[NB_SECOND_INSTR]--)
		{
			if (data->lst_a->prev->rank == data->softmin_a)
			{
				free(best_comb);
				return ;
			}
			apply_instr(data, &data->lst_a, &data->lst_b, best_comb[SECOND_INSTR], PRINT);
		}
	}
	free(best_comb);
}

int swap_if_high_to_dump(t_data *data, int instr)
{
	if (data->max_b == data->rank_max || data->min_b == 0)
		if (data->lst_a->rank == data->rank_max || data->lst_a->rank == 0)
			return (BREAK_BEST_COMB);
	return (swap_if_high(data, instr));
}

int swap_if_high(t_data *data, int instr)
{
	t_lnk *lst_a = data->lst_a;

	if (instr == ra || instr == rr)
		return (IGNORE); 
	if (lst_a->rank > data->mediane_a && lst_a->next->rank > data->mediane_a)
	{
		if (lst_a->next->rank < lst_a->rank)
			apply_instr(data, &data->lst_a, &data->lst_b, sa, PRINT);
	}
	return (IGNORE);
}

int apply_best_comb_and(int (*f_do)(t_data *d, int instr), t_data *data, int *best_comb)
{
	if (best_comb[FIRST_INSTR] == CANT_INSERT)
		return (CANT_INSERT);
	while (best_comb[NB_FIRST_INSTR]--)
	{
		if (f_do(data, best_comb[FIRST_INSTR]) == BREAK_BEST_COMB)
			return (BREAK_BEST_COMB);
		apply_instr(data, &data->lst_a, &data->lst_b, best_comb[FIRST_INSTR], PRINT);
		if (f_do(data, best_comb[FIRST_INSTR]) == BREAK_BEST_COMB)
			return (BREAK_BEST_COMB);
	}
	if (best_comb[SECOND_INSTR] != NO_INSTR)
	{
		while (best_comb[NB_SECOND_INSTR]--)
		{
			if (f_do(data, best_comb[FIRST_INSTR]) == BREAK_BEST_COMB)
				return (BREAK_BEST_COMB);
			apply_instr(data, &data->lst_a, &data->lst_b, best_comb[SECOND_INSTR], PRINT);
			if (f_do(data, best_comb[FIRST_INSTR]) == BREAK_BEST_COMB)
				return (BREAK_BEST_COMB);
		}
	}
	free(best_comb);
	return (TRUE);
}

int apply_best_comb(t_data *data, int *best_comb)
{
	if (best_comb[FIRST_INSTR] == CANT_INSERT)
		return (CANT_INSERT);
	while (best_comb[NB_FIRST_INSTR]--)
		apply_instr(data, &data->lst_a, &data->lst_b, best_comb[FIRST_INSTR], PRINT);
	if (best_comb[SECOND_INSTR] != NO_INSTR)
		while (best_comb[NB_SECOND_INSTR]--)
			apply_instr(data, &data->lst_a, &data->lst_b, best_comb[SECOND_INSTR], PRINT);
	free(best_comb);
	return (TRUE);
}

void apply_instr_step_itm(int **instr_steps_itm_addr)
{
	apply_instr_step_itm_test(&d.lst_a, &d.lst_b, instr_steps_itm_addr, PRINT);
}

int *malloc_instr_steps_itm(t_data *data)
{
	int *instr_steps_itm;

	instr_steps_itm = ft_calloc(4, sizeof(int));
	if (!instr_steps_itm)
		return (NULL);
	instr_steps_itm[NB_INSTR] = SIZE_MAX;
	instr_steps_itm[INSTR] = NO_INSTR;
	if (!data)
	{
		instr_steps_itm[NB_INSTR] = 0;
		return (instr_steps_itm);
	}
	instr_steps_itm[NB_INSTR] = data->best_inst_step[NB_INSTR];
	instr_steps_itm[INSTR] = data->best_inst_step[INSTR];
	return (instr_steps_itm);
}

int *malloc_best_insert(t_data *data)
{
	int *best_comb;

	best_comb = malloc(4 * sizeof(int));
	if (!best_comb)
		return (FALSE);
	best_comb[FIRST_INSTR] = data->best_comb[FIRST_INSTR];
	best_comb[NB_FIRST_INSTR] = data->best_comb[NB_FIRST_INSTR];
	best_comb[SECOND_INSTR] = data->best_comb[SECOND_INSTR];
	best_comb[NB_SECOND_INSTR] = data->best_comb[NB_SECOND_INSTR];
	return (best_comb);
}

int	*insert_target_to_list_steps(t_lnk *lst_a, t_lnk *lst_b, int lst_instr[], int (*can_push)(t_data *data, t_lnk *lst_a, t_lnk *lst_b), int cost)
{
	int i_instr;
	int	instr_steps_itm[2];
	int instr;
	t_data data;

	i_instr = 0;
	set_data(&data, &lst_a, &lst_b);
	data.best_cost_comb = cost;
	//data.best_cost_instr = cost;
	instr = lst_instr[0];
	set_instr_step_itm(instr, 0, instr_steps_itm);
	if (can_push(&data, lst_a, lst_b))
	{
		update_best_instr(&data, instr_steps_itm);
		return (malloc_instr_steps_itm(&data));
	}
	while (instr != LOOP_END)
	{
		set_instr_step_itm(instr, INT_MAX, instr_steps_itm);
		instr_steps_itm[NB_INSTR] = count_instr(&data, lst_a, lst_b, instr, can_push);
		update_best_instr(&data, instr_steps_itm);
		data.best_cost_comb = ft_cost(d.best_comb);
		instr = lst_instr[++i_instr];
	}
	return (malloc_instr_steps_itm(&data));
}

void set_best_comb(int *best_comb)
{
	set_instr_step_itm(NO_INSTR, SIZE_MAX, &best_comb[FIRST_INSTR]);
	set_instr_step_itm(NO_INSTR, SIZE_MAX, &best_comb[SECOND_INSTR]);
}

int ft_cost(int *best_comb)
{
	int cost;

	cost = SIZE_MAX;
	if (best_comb[FIRST_INSTR] != NO_INSTR && best_comb[FIRST_INSTR] != CANT_INSERT)
		cost = best_comb[NB_FIRST_INSTR];
	if (best_comb[SECOND_INSTR] != NO_INSTR && best_comb[SECOND_INSTR] != CANT_INSERT)
		cost += best_comb[NB_SECOND_INSTR];
	return (cost);
}

void update_best_comb(int (*b_c)[4], int *instr_steps_itm1, int *instr_steps_itm2)
{
	int *best_comb;
	int new_best_comb[4];

	best_comb = *b_c;
	new_best_comb[FIRST_INSTR] = instr_steps_itm1[INSTR];
	new_best_comb[NB_FIRST_INSTR] = instr_steps_itm1[NB_INSTR];
	new_best_comb[SECOND_INSTR] = instr_steps_itm2[INSTR];
	new_best_comb[NB_SECOND_INSTR] = instr_steps_itm2[NB_INSTR];
	if (ft_cost(new_best_comb) < ft_cost(best_comb))
	{
		best_comb[FIRST_INSTR] = new_best_comb[FIRST_INSTR];
		best_comb[NB_FIRST_INSTR] = new_best_comb[NB_FIRST_INSTR];
		best_comb[SECOND_INSTR] = new_best_comb[SECOND_INSTR];
		best_comb[NB_SECOND_INSTR] = new_best_comb[NB_SECOND_INSTR];
	}
}


int *best_insert(t_lnk *lst_a, t_lnk *lst_b, int lst_instr[], int (*can_push)(t_data *data, t_lnk *lst_a, t_lnk *lst_b))
{
	t_data d;
	int i_instr;
	int first_instr_steps[2];

	set_data(&d, &lst_a, &lst_b);
	set_best_comb(d.best_comb);
	i_instr = 0;
	while (lst_instr[i_instr] != LOOP_END)
	{
		int *second_instr_steps;
		t_lnk *lst_a_original = lst_a;
		t_lnk *lst_b_original = lst_b;
		set_instr_step_itm(lst_instr[i_instr], 0, first_instr_steps);
		if (can_push(&d, lst_a, lst_b))
		{
			return (malloc_instr_steps_itm(NULL));
		}
		int j_instr = 0;
		while (first_instr_steps[NB_INSTR]++ < ft_cost(d.best_comb))
		{
			apply_instr(&d, &lst_a, &lst_b, lst_instr[i_instr], QUIET);
			second_instr_steps = insert_target_to_list_steps(lst_a, lst_b, lst_instr, can_push, ft_cost(d.best_comb));
			update_best_comb(&d.best_comb, first_instr_steps, second_instr_steps);
			d.best_cost_comb = ft_cost(d.best_comb);
			free(second_instr_steps);
			if (can_push(&d, lst_a, lst_b))
				break ;
			j_instr++;
		}
		lst_a = lst_a_original;
		lst_b = lst_b_original;
		i_instr++;
	}
	return (malloc_best_insert(&d));
}