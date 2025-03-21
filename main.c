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
	if (lst == data->lst_a)
	{
		if (data->max_a == lst->rank || data->min_a == lst->rank)
			return (TRUE);
	}
	else if (lst == data->lst_b)
	{
		if (data->max_b == lst->rank || data->min_b == lst->rank)
			return (TRUE);
	}
	return (FALSE);
}

int	do_best_insert(t_data *data, t_searching_op *op)
{
	t_list *insertion_step;
	int nb_instr;

	nb_instr = -1;
	if (op->f_can(data))
		apply_instr(data, op->px, op->verbose);
	else
	{
		insertion_step = ft_best_comb(data, op->instr_lst, op->f_can, SIZE_MAX);
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
		d.lst_a = get_args(&d, argc, argv);
	d.rank_max = lst_init_ranks(&d.lst_a);
	d.lst_b = NULL;
	if (!ft_no_duplicate(d.lst_a))
		ft_errmsg("Error: duplicated items");
	init_data(&d, &d.lst_a, &d.lst_b);
		//print_lst(&d);
	d.instr_map = init_instr_map();
    int r_instr[12] = {ra, rb, rra, rrb, rr, rrr, LOOP_END, LOOP_END, LOOP_END, LOOP_END, LOOP_END, LOOP_END};

	t_searching_op op_best_insert_b;
	op_best_insert_b = {can_push_b, NULL, r_instr. pb, PRINT};
	while (d.a.lst) {
		do_best_insert(&d, &op_best_insert_b);
	}
	//print_lst(&d);
	del_lst(&d.lst_a);
	del_lst(&d.lst_b);
	free(d.instr_map);
}
