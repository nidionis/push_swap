/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/01/30 02:37:27 by nidionis         ###   ########.fr       */
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
		reach_rank(&d.lst_a, 0, get_shortestway(0, d.lst_a));
	}
}

void print_best_insert(int *best_insert_itm)
{
	printf("first instr: ");
	print_instr_steps(best_insert_itm);
	printf("second instr: ");
	print_instr_steps(best_insert_itm + 2);
}

t_data d;

int	main(int argc, char **argv)
{
	int		lst_instr[] = {ra, rb, rra, rrb, rr, rrr, LOOP_END};
	int		load_minmax_rot[] = {ra, rb, rrb, rr, rrr, LOOP_END};

	(void)lst_instr;
	(void)load_minmax_rot;
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
	while (!is_sorted(d.lst_a))
	{
		while (d.max_b != d.rank_max && d.min_b != 0)
		{
			int *best_insert_itm = best_insert(d.lst_a, d.lst_b, load_minmax_rot, can_push_b);
			load_minimax(&d, best_insert_itm);
			//print_data(&d);
		}
		break ;
		//int *instr_steps_itm = insert_target_to_list_steps(d.lst_a, d.lst_b, lst_instr, can_push_b);
		//print_best_insert(best_insert_itm);
	//print_lst_byrank(d.lst_a, "lst_a");
	//print_lst_byrank(d.lst_b, "lst_b");
		//apply_best_comb(&d, best_insert_itm);
	}
	del_lst(&d.lst_a);
	del_lst(&d.lst_b);
}
