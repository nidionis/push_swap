/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/01/29 22:34:36 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	can_push_b(t_data *data, t_lnk *a, t_lnk *b)
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

void	update_best_instr(t_data *data, int instr_steps_itm[2])
{
	if (instr_steps_itm[NB_INSTR] < data->best_inst_step[NB_INSTR])
	{
		data->best_inst_step[INSTR] = instr_steps_itm[INSTR];
		data->best_inst_step[NB_INSTR] = instr_steps_itm[NB_INSTR];
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
	int max;
	t_lnk *orig_a;
	t_lnk *orig_b;

	count = 0;
	orig_a = lst_a;
	orig_b = lst_b;
	max = ft_lstsize(orig_a) + ft_lstsize(orig_b); // yolo
	if (can_push(data, lst_a, lst_b))
		return (0);
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

void apply_best_comb(t_data *data, int *best_comb)
{
	if (best_comb[FIRST_INSTR] != NO_INSTR)
		while (best_comb[NB_FIRST_INSTR]--)
			apply_instr(data, &data->lst_a, &data->lst_b, best_comb[FIRST_INSTR], PRINT);
	if (best_comb[SECOND_INSTR] != NO_INSTR)
		while (best_comb[NB_SECOND_INSTR]--)
			apply_instr(data, &data->lst_a, &data->lst_b, best_comb[SECOND_INSTR], PRINT);
	free(best_comb);
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
	instr_steps_itm[NB_INSTR] = CANT_INSERT;
	instr_steps_itm[INSTR] = NO_INSTR;
	if (!data)
		return (instr_steps_itm);
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

int	*insert_target_to_list_steps(t_lnk *lst_a, t_lnk *lst_b, int lst_instr[], int (*can_push)(t_data *data, t_lnk *lst_a, t_lnk *lst_b))
{
	int i_instr;
	int	*instr_steps_itm;
	int instr;
	t_data data;

	i_instr = 0;
	set_data(&data, &lst_a, &lst_b);
	instr = lst_instr[0];
	instr_steps_itm = malloc(2 * sizeof(int));
	set_instr_step_itm(instr, 0, instr_steps_itm);
	if (can_push(&data, lst_a, lst_b))
	{
		update_best_instr(&data, instr_steps_itm);
		return (instr_steps_itm);
	}
	while (instr != LOOP_END)
	{
		set_instr_step_itm(instr, INT_MAX, instr_steps_itm);
		instr_steps_itm[NB_INSTR] = count_instr(&data, lst_a, lst_b, instr, can_push);
		update_best_instr(&data, instr_steps_itm);
		instr = lst_instr[++i_instr];
	}
	return (malloc_instr_steps_itm(&data));
}

void set_best_comb(int *best_comb)
{
	set_instr_step_itm(NO_INSTR, INT_MAX, &best_comb[FIRST_INSTR]);
	set_instr_step_itm(NO_INSTR, INT_MAX, &best_comb[SECOND_INSTR]);
}

int cost(int *best_comb)
{
	int cost;

	cost = best_comb[NB_FIRST_INSTR];
	if (best_comb[SECOND_INSTR] != NO_INSTR)
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
	if (cost(new_best_comb) < cost(best_comb))
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
			return (malloc_instr_steps_itm(NULL));
		int j_instr = 0;
		while (first_instr_steps[NB_INSTR]++ < cost(d.best_comb))
		{
			apply_instr(&d, &lst_a, &lst_b, lst_instr[i_instr], QUIET);
			second_instr_steps = insert_target_to_list_steps(lst_a, lst_b, lst_instr, can_push);
			update_best_comb(&d.best_comb, first_instr_steps, second_instr_steps);
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