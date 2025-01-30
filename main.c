/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/01/30 23:20:14 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	select_algo(int ind_max)
{
	if (ind_max == 1)
		sort_2_nb(1);
	else if (ind_max == 2)
		sort_3_nb(2);
	else if (ind_max == 3)
		sort_4_nb(3);
	else if (ind_max == 4)
		sort_5_nb(4);
	else
	{
		// load_b();
		// b_dump();
		reach_rank_lst_a(&d.lst_a, 0, get_shortestway(0, d.lst_a));
	}
}

void print_best_insert(int *best_insert_itm)
{
	printf("first instr: ");
	print_instr_steps(best_insert_itm);
	printf("second instr: ");
	print_instr_steps(best_insert_itm + 2);
}

void reach_softmin(t_data *data)
{
	int *best_load_b;
	int		no_rra_instr[] = {ra, rb, rrb, rr, LOOP_END};

	while (data->min_b != data->softmin_a + 1)
	{
		best_load_b = best_insert(data->lst_a, data->lst_b, data->full_instr, load_b_but_softmax_and_hight);
		apply_best_comb(data, best_load_b);
		apply_instr(data, &data->lst_a, &data->lst_b, pb, PRINT);
	}
	while (data->lst_a->prev->rank != data->softmin_a)
	{
		best_load_b = best_insert(data->lst_a, data->lst_b, no_rra_instr, load_b_but_softmax_and_hight);
		apply_best_comb_until_softmin(data, best_load_b);
		apply_instr(data, &data->lst_a, &data->lst_b, pa, PRINT);
	}
}

t_data d;

void first_dump(t_data *data)
{
	apply_instr(data, &data->lst_a, &data->lst_b, pa, PRINT);
	if (data->lst_a->rank == 0)
	{
		reach_rank_lst_b(&d.lst_b, data->rank_max, get_shortestway(data->rank_max, data->lst_b));
		apply_instr(data, &data->lst_a, &data->lst_b, pa, PRINT);
		apply_instr(data, &data->lst_a, &data->lst_b, ra, PRINT);
		apply_instr(data, &data->lst_a, &data->lst_b, ra, PRINT);
	}
	else
	{
		apply_instr(data, &data->lst_a, &data->lst_b, ra, PRINT);
		reach_rank_lst_b(&data->lst_b, data->max_b, get_shortestway(data->max_b, data->lst_b));
	}
	while (data->lst_b)
		apply_instr(data, &data->lst_a, &data->lst_b, pa, PRINT);
}

void gather_min_and_max(t_data *data)
{
	int *best_insert_itm;

	while (!(data->max_b == data->rank_max && data->min_b == 0))
	{
		best_insert_itm = best_insert(data->lst_a, data->lst_b, data->full_instr, load_b_low_and_max);
		if (apply_best_comb_and(swap_if_high_to_dump, data, best_insert_itm) != CANT_INSERT)
			apply_instr(data, &data->lst_a, &data->lst_b, pb, PRINT);
		else
			break ;
	}
}

int	main(int argc, char **argv)
{
	int		lst_instr[] = {ra, rb, rra, rrb, rr, rrr, LOOP_END};
	int		no_rra_instr[] = {ra, rb, rrb, rr, rrr, LOOP_END};

	(void)lst_instr;
	(void)no_rra_instr;
	d = (t_data){0};
	if (argc < 2)
		error_msg(NULL);
	else if (argc == 2)
		d.lst_a = get_args_allinone(argv[1]);
	else
		d.lst_a = get_args(argc, argv);
	d.rank_max = lst_init_ranks(&d.lst_a);
	d.lst_b = NULL;
	if (!ft_no_duplicate(d.lst_a))
		error_msg("Error: duplicated items");
	set_data(&d, &d.lst_a, &d.lst_b);
	//print_lst_byrank(d.lst_a, "lst_a");
	//print_lst_byrank(d.lst_b, "lst_b");
	//printf("\n");
	if (!is_sorted(d.lst_a))
	{
		gather_min_and_max(&d);
		first_dump(&d);
		//while (!is_sorted(d.lst_a) || d.lst_b)
		//{
		//	apply_instr(&d, &d.lst_a, &d.lst_b, ra, PRINT);
		//	reach_soft_min(&d);
		//	dump_b(&d);
		//}
		//int *instr_steps_itm = insert_target_to_list_steps(d.lst_a, d.lst_b, lst_instr, load_b_minmax);
		//print_best_insert(best_insert_itm);
	//print_lst_byrank(d.lst_a, "lst_a");
	//print_lst_byrank(d.lst_b, "lst_b");
		//apply_best_comb(&d, best_insert_itm);
	}
	del_lst(&d.lst_a);
	del_lst(&d.lst_b);
}
