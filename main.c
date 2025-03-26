/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/02/09 16:30:59 by nidionis         ###   ########.fr       */
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
    int r_instr[12] = {ra, rb, rra, rrb, rr, rrr, LOOP_END, LOOP_END, LOOP_END, LOOP_END, LOOP_END, LOOP_END};

	d.b.pivot = d.rank_max / 2;
	d.a.pivot = d.rank_max / 2;
	d.b.sorting_range = d.rank_max / 30;
	t_searching_op op_best_insert_b;
	op_best_insert_b = (t_searching_op) {can_range_sort, NULL, r_instr, pb, PRINT_DISPLAY};
	//op_best_insert_b = (t_searching_op) {can_load_b, NULL, r_instr, pb, PRINT_DISPLAY};
	int ret = 1;
	while (d.a.size && ret != ERR_NO_BEST_COMB && ret != EMPTY_LST) {
		ret = do_best_insert(&d, &op_best_insert_b);
		//printf("ret: %d\n", ret);
		//print_lst(&d);
	}
	//print_lst(&d);
	del_lst(&d.a.lst);
	del_lst(&d.b.lst);
	//free(d.instr_map);
}
