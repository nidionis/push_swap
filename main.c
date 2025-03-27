/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/03/27 03:37:22 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	is_on_min_or_max(t_data *data, t_lnk *lst)
{
	if (lst == data->a.lst)
	{
		if (data->a.max == lst->rank || data->a.min == lst->rank)
			return (TRUE);
	}
	else if (lst == data->b.lst)
	{
		if (data->b.max == lst->rank || data->b.min == lst->rank)
			return (TRUE);
	}
	return (FALSE);
}

int	do_best_insert(t_data *data, t_searching_op *op)
{
	t_list *insertion_step;
	int nb_instr;

	nb_instr = UNSET_NB_INSTR;
	if (op->f_can(data))
		apply_instr(data, op->px, op->verbose);
	else
	{
		insertion_step = ft_best_comb(data, op->instr_ls, op->f_can, SIZE_MAX);
		if (!insertion_step)
			return (ERR_NO_BEST_COMB);
		nb_instr = ft_nb_instr(insertion_step);
		if (apply_best_comb_and(op->f_do, data, insertion_step, op->verbose) == BREAK_BEST_COMB)
			nb_instr = BREAK_BEST_COMB;
		ft_lstclear(&insertion_step, free);
	}
	return (nb_instr);
}

void init_r_instr_load_b_basic(int r_instr[12]) {
    r_instr[0] = rrr;
    r_instr[1] = rr;
    r_instr[2] = ra;
    r_instr[3] = rra;
    r_instr[4] = rb;
    r_instr[5] = rrb;
    r_instr[6] = LOOP_END;
}

int load_b_quick_load(t_data *d)
{
    int r_instr[12];
    t_searching_op op_best_insert_b;
    int ret;

	op_best_insert_b = (t_searching_op) {can_quicklad_b, NULL, r_instr, pb, PRINT_DISPLAY};
    ret = 0;
    init_r_instr_load_b_basic(r_instr);
    d->r_instr = r_instr;
	while (d->a.size && ret != ERR_NO_BEST_COMB && ret != EMPTY_LST) {
		ret = do_best_insert(d, &op_best_insert_b);
	}
    return (ret);
}

int load_b_split_load_but_medium(t_data *d)
{
    int r_instr[12];
    t_searching_op op_best_insert_b;
    int ret;

	op_best_insert_b = (t_searching_op) {can_splitload_but_medium, NULL, r_instr, pb, PRINT_DISPLAY};
    ret = 0;
    init_r_instr_load_b_basic(r_instr);
    d->r_instr = r_instr;
    d->b.pivot = d->rank_max / 2;
	while (ret != ERR_NO_BEST_COMB && ret != EMPTY_LST) {
		ret = do_best_insert(d, &op_best_insert_b);
	}
    return (ret);
}

int load_b_dirty_load(t_data *d)
{
    int r_instr[12];
    t_searching_op op_best_insert_b;
    int ret;

	op_best_insert_b = (t_searching_op) {can_dirty_load_b, NULL, r_instr, pb, PRINT_DISPLAY};
    ret = 0;
    init_r_instr_load_b_basic(r_instr);
    d->r_instr = r_instr;
    d->b.sorting_range = 5;
	while (d->a.size && ret != ERR_NO_BEST_COMB && ret != EMPTY_LST) {
		ret = do_best_insert(d, &op_best_insert_b);
	}
    return (ret);
}

int dump_b_basic(t_data *d)
{
    int r_instr[12];
    t_searching_op op_best_insert_b;
    int ret;

	op_best_insert_b = (t_searching_op) {can_dump_b, NULL, r_instr, pa, PRINT_DISPLAY};
    ret = 0;
    init_r_instr_load_b_basic(r_instr);
    d->r_instr = r_instr;
	while (d->b.size) {
		ret = do_best_insert(d, &op_best_insert_b);
	}
    return (ret);
}


int	main(int argc, char **argv)
{
	t_data d;

	ft_bzero(&d, sizeof(t_data));
	if (argc < 2)
	{
		ft_errmsg(NULL);
		exit(0);
	}
	else
		d.a.lst = get_args(&d, argc, argv);
	d.rank_max = lst_init_ranks(&d.a.lst);
	d.b.lst = NULL;
	if (!ft_no_duplicate(d.a.lst))
		ft_errmsg("Error: duplicated items");
	init_data(&d, &d.a.lst, &d.b.lst);
		//print_lst(&d);
	init_instr_map(&d.instr_map);
    load_b_split_load_but_medium(&d);
	dump_b_basic(&d);
	//	//print_lst(&d);
	del_lst(&d.a.lst);
	del_lst(&d.b.lst);
	//free(d.instr_map);
}
