/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/04/01 19:04:33 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void init_r_instr_load_b_turk_(int r_instr[12]) {
    r_instr[0] = ra;
    r_instr[1] = rr;
    r_instr[2] = rb;
    r_instr[5] = rrb;
    r_instr[4] = rrr;
    r_instr[3] = rra;
    r_instr[6] = LOOP_END;
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

int load_b_Turk(t_data *d, int verbose)
{
    int ret;
    int pivot;
    t_lst *b;

    b = &d->b;
    pivot = d->min_to_load + (d->max_to_load - d->min_to_load) / COEF_TURK;
    ret = 0;
    ret = apply_instr(d, pb, verbose);
    if (head(b) < pivot)
        ret = apply_instr(d, rb, verbose);
    if (head(b) != b->max)
        if (head(b) < next(b) && head(b) < COEF_TURK)
            ret = apply_instr(d, sb, verbose);
    return (ret);
}


int load_b_opti_turk(t_data *d, int *r_instr, int verbose)
{
	int nb_instr;
    //int instr_ls[7] = {rb, rrb, rr, rrr, LOOP_END};

	d->r_instr = r_instr;
	//d->b.pivot = (d->a.softmax - d->a.softmin) / 2 + d->a.softmin;
    nb_instr = 0;
	while (!is_sorted(d->a.lst)) {
        d->min_to_load = d->a.max / COEF_TURK;
        d->max_to_load = d->a.max - d->min_to_load * 2;
        if (head(&d->a) >= d->max_to_load || head(&d->a) <= d->min_to_load)
        {
            nb_instr += load_b_Turk(d, verbose);
        }
        else
            nb_instr = apply_instr(d, ra, verbose);
	}
	return (nb_instr);
}

int dump_b_while_contains_next_softmax(t_data *d, int verbose)
{
    int r_instr[12];
    int ret;
    t_searching_op op_best_insert_b;

    init_r_instr_load_b_basic(r_instr);
    d->r_instr = r_instr;
    op_best_insert_b = (t_searching_op) {can_dump_b, NULL, r_instr, pa, verbose};
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
    init_instr_map(&d.instr_map);
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

    init_r_instr_load_b_turk_(r_instr);
    load_b_opti_turk(&d, r_instr, PRINT_DISPLAY);
	//dump_b_softminmax(&d, PRINT_DISPLAY);
	dump_b_basic(&d);
	//splitload_but_softs(&d);
	//dump_b_basic(&d);
	//	//print_lst(&d);
    reach_rank_a(&d, 0, PRINT_DISPLAY);
	del_lst(&d.a.lst);
	del_lst(&d.b.lst);
	//free(d.instr_map);
}
