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

//void	select_algo(int ind_max)
//{
//	if (ind_max == 1)
//		sort_2_nb(1);
//	else if (ind_max == 2)
//		sort_3_nb(2);
//	else if (ind_max == 3)
//		sort_4_nb(3);
//	else if (ind_max == 4)
//		sort_5_nb(4);
//	else
//	{
//		printf("Error\n");
//	}
//}

int	main(int argc, char **argv)
{
	t_data d;
	t_instr_map instr_map[12];
	int instr_ls[] = {ra, rb, rra, rrb, rr, rrr, LOOP_END};

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
	init_instr_map(instr_map);
	d.instr_map = instr_map;
	d.r_instr = instr_ls;
	while (d.lst_a)
	{
		t_list *insertion_step;
		if (can_load_b(&d))
			apply_instr(&d, pb, PRINT);
		else
		{
			insertion_step = ft_best_comb(&d, d.r_instr, can_first_load, SIZE_MAX);
			//print_instr_ls(insertion_step);
			apply_best_comb_and(NULL, &d, insertion_step, PRINT);
			if (!insertion_step)
				break ;
			ft_lstclear(&insertion_step, free);
		}
		//print_lst(&d);
	}
	//gather_min_and_max(&d);
	//first_dump(&d);
	del_lst(&d.lst_a);
	del_lst(&d.lst_b);
}
