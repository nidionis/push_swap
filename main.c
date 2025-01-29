/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/01/29 00:59:13 by nidionis         ###   ########.fr       */
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

t_data d;

int	main(int argc, char **argv)
{
	int		ind_max;
	int		lst_instr[] = {ra, rb, rra, rrb, LOOP_END};

	d = (t_data){0};
	if (argc < 2)
		error_msg(NULL);
	else if (argc == 2)
		d.lst_a = get_args_allinone(argv[1]);
	else
		d.lst_a = get_args(argc, argv);
	ind_max = lst_init_ranks(&d.lst_a);
	(void)ind_max;
	d.lst_b = NULL;
	if (!ft_no_duplicate(d.lst_a))
		error_msg("Error: duplicated items");
	set_data();
	apply_instr(&d.lst_a, &d.lst_b, pb, QUIET);
	apply_instr(&d.lst_a, &d.lst_b, pb, QUIET);
	print_lst_byrank(d.lst_a, "lst_a");
	print_lst_byrank(d.lst_b, "lst_b");
	print_instr_steps(insert_target_to_list_steps(d.lst_a, d.lst_b, lst_instr, can_push_a));
	print_instr_steps(insert_target_to_list_steps(d.lst_a, d.lst_b, lst_instr, can_push_b));
	// select_algo();
	//print_data(&d);
	del_lst(&d.lst_a);
	del_lst(&d.lst_b);
}
