/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/04/02 23:03:51 by nidionis         ###   ########.fr       */
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

int dump_b_basic(t_data *d, int *r_instr, int verbose)
{
    t_searching_op op_best_insert_b;
    int ret;

	op_best_insert_b = (t_searching_op) {can_dump_b, NULL, r_instr, pa, verbose};
    ret = 0;
    d->r_instr = r_instr;
	while (d->b.size) {
		ret += do_best_insert(d, &op_best_insert_b);
	}
    return (ret);
}

int load_b_Turk(t_data *d, int coef_turk, int verbose)
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
        if (head(b) < next(b) && head(b) < coef_turk)
            ret = apply_instr(d, sb, verbose);
    return (ret);
}


int load_b_opti_turk(t_data *d, int coef_turk, int r_x, int verbose)
{
	int nb_instr;

    nb_instr = 0;
	while (!is_sorted(d->a.lst)) {
        d->min_to_load = d->a.max / coef_turk;
        d->max_to_load = d->a.max - d->min_to_load * 2;
        if (head(&d->a) >= d->max_to_load || head(&d->a) <= d->min_to_load)
        {
            nb_instr += load_b_Turk(d, coef_turk, verbose);
        }
        else
            nb_instr += apply_instr(d, r_x, verbose);
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

int main_test(t_data d, int coef_turk, int r_x, int verbose)
{
	int r_instr[12];
	int nb_instr;

    //init_r_instr_load_b_basic(r_instr);
	init_r_instr_load_b_turk_(r_instr);
	nb_instr = load_b_opti_turk(&d, coef_turk, r_x, verbose);
	nb_instr += dump_b_basic(&d, r_instr, verbose);
	nb_instr += reach_rank_a(&d, 0, verbose);
	return (nb_instr);
}

t_lnk *list_deep_cpy(t_lnk *lst)
{
	t_lnk *tmp;
	t_lnk *ret;
	t_lnk *last;

	ret = NULL;
	if (!lst)
		return (NULL);
	lst = lst->prev;
	last = lst;
	while (!ret || lst != last)
	{
		tmp = malloc(sizeof(t_lnk));
		if (!tmp)
		{
			del_lst(&ret);
			return (NULL);
		}
		ft_memcpy(tmp, lst, sizeof(t_lnk));
		push_item(tmp, &ret);
		lst = lst->prev;
	}
	return (ret);
}
void reset_lst(t_data *d, t_lnk *back_up)
{
	del_lst(&d->a.lst);
	d->a.lst = list_deep_cpy(back_up);
	d->b.lst = NULL;
}

int	main(int argc, char **argv)
{
	t_data d;

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

	int coef_turk = 3;
	int best_coef = coef_turk;
	int best_turk = SIZE_MAX * 20;
	int nb_instr = best_turk;
	t_lnk *deep_cpy = list_deep_cpy(d.a.lst);
	int best_way = ra;
	while (coef_turk < 8)
	{
		int tmp = 100000;
		int r_x = ra;
		nb_instr = main_test(d, coef_turk, r_x, QUIET);
		reset_lst(&d, deep_cpy);
		tmp = main_test(d, coef_turk, ft_rev_instr(r_x), QUIET);
		reset_lst(&d, deep_cpy);
		if (nb_instr > tmp)
		{
			nb_instr = tmp;
			r_x = rra;
		}
		if (nb_instr < best_turk)
		{
			best_turk = nb_instr;
			best_coef = coef_turk;
			best_way = r_x;
		}
		coef_turk++;
	}
	main_test(d, best_coef, best_way, PRINT_DISPLAY);
	del_lst(&d.a.lst);
	del_lst(&d.b.lst);
	del_lst(&deep_cpy);
}
