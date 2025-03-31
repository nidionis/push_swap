/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/03/31 21:27:02 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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
	while (ret >= 0) {
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

int dump_b_softminmax(t_data *d, int verbose)
{
	int r_instr[12];
	int ret;

	ret = 0;
	init_r_instr_load_b_basic(r_instr);
	d->r_instr = r_instr;
	ret += reach_rank(d, d->b.softmin, verbose);
	int softmax_b = d->b.softmax;
	while (head(&d->a) != softmax_b)
		ret += apply_instr(d, pa, verbose);
	return (ret);
}

int splitload_but_softs(t_data *d)
{
    int r_instr[12];
    t_searching_op op_best_insert_b;
    int ret;

	op_best_insert_b = (t_searching_op) {can_splitload_but_softs, NULL, r_instr, pb, PRINT_DISPLAY};
    ret = 0;
    init_r_instr_load_b_basic(r_instr);
    d->r_instr = r_instr;
    d->b.pivot = (d->a.softmax - d->a.softmin) / 2 + d->a.softmin;
	while (ret >= 0) {
		ret = do_best_insert(d, &op_best_insert_b);
	}
    return (ret);
}

int load_b_Turk(t_data *d, int verbose)
{
    int ret;
    int pivot;
    t_lst *a;
    t_lst *b;

    a = &d->a;
    b = &d->b;
    pivot = d->min_to_load + (d->max_to_load - d->min_to_load) / 3;
    ret = 0;
    ret = apply_instr(d, pb, verbose);
    if (head(b) < pivot)
        ret = apply_instr(d, rb, verbose);
    if (head(b) != b->max)
        if (head(b) < next(b))
            ret = apply_instr(d, sb, verbose);
    return (ret);
}


int load_b_until_min_and_max(t_data *d, int *r_instr, int verbose)
{
	int ret;
	int nb_instr;
    //int instr_ls[7] = {rb, rrb, rr, rrr, LOOP_END};

    d->min_to_load = d->rank_max / 2;
    d->max_to_load = d->rank_max;
    //d->a.pivot = ((d->max_to_load - d->min_to_load) / 2) + d->min_to_load;
	nb_instr = 0;
	d->r_instr = r_instr;
	//d->b.pivot = (d->a.softmax - d->a.softmin) / 2 + d->a.softmin;
    ret = 0;
	while (break_when_minmax_loaded(d, 0) != BREAK_BEST_COMB) {
        if (head(&d->a) == 0 || head(&d->a) == d->rank_max)
        {
            ret += apply_instr(d, pb, verbose);
        }
        else if (head(&d->a) > d->max_to_load || head(&d->a) < d->min_to_load)
        {
            ret = apply_instr(d, ra, verbose);
        }
        else
            ret += load_b_Turk(d, verbose);
	}
	return (ret);
}

int dump_b_while_contains_next_softmax(t_data *d, int verbose)
{
    int r_instr[12];
    int ret;
    t_searching_op op_best_insert_b;

    init_r_instr_load_b_basic(r_instr);
    d->r_instr = r_instr;
    op_best_insert_b = (t_searching_op) {can_dump_b, NULL, r_instr, pa, verbose};
    d->b.pivot = (d->a.softmax - d->a.softmin) / 2 + d->a.softmin;
    while (d->b.max == d->a.softmax - 1 || d->a.min != 0 || d->a.max != d->rank_max)
    {
        ret = do_best_insert(d, &op_best_insert_b);
    }
    return (ret);
}


int	main(int argc, char **argv)
{
	t_data d;
	int r_instr[12];

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
	init_r_instr_load_b_basic(r_instr);
		//print_lst(&d);
	init_instr_map(&d.instr_map);
	load_b_until_min_and_max(&d, r_instr, PRINT_DISPLAY);
	//dump_b_softminmax(&d, PRINT_DISPLAY);
    apply_instr(&d, pa, PRINT_DISPLAY);
    dump_b_while_contains_next_softmax(&d, PRINT_DISPLAY);
	//dump_b_basic(&d);
	//splitload_but_softs(&d);
	//dump_b_basic(&d);
	//	//print_lst(&d);
	del_lst(&d.a.lst);
	del_lst(&d.b.lst);
	//free(d.instr_map);
}
