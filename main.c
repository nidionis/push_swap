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

int	load_butterfly(t_data *data, int (*can_do)(t_data *data), int verbose)
{
	t_list *insertion_step;
	int nb_instr;

	nb_instr = -1;
	if (can_do(data))
		nb_instr = apply_instr(data, pb, verbose);
	else
	{
		insertion_step = ft_best_comb(data, data->r_instr, can_do, SIZE_MAX);
		if (!insertion_step)
			return (-1);
		nb_instr = ft_nb_instr(insertion_step);
		if (apply_best_comb_and(should_swap_b_, data, insertion_step, verbose) == BREAK_BEST_COMB)
			return (BREAK_BEST_COMB);
		else
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
	d.instr_map = init_instr_map();
	//set_minmax_load_low(&d, PRINT);
	//while (d.lst_a)
	//	apply_instr(&d, pb, QUIET);
	//print_lst(&d);
	//reach_rank(&d, 0, PRINT);



	while (d.lst_a)
	{
		//print_lst(&d);
		int r_instr[] = {ra, rb, rra, rrb, rr, rrr, LOOP_END};
		d.r_instr = r_instr;
		//printf("can_butterfly: %d\n", can_butterfly(&d));
	d.softmax_a = d.rank_max;
	d.softmin_a = 0;
		d.max_to_load = d.rank_max;
		d.min_to_load = 0;
		//load_butterfly(&d, PRINT);
		load_butterfly(&d, can_butterfly, PRINT);
	}



	//print_lst(&d);
	del_lst(&d.lst_a);
	del_lst(&d.lst_b);
	free(d.instr_map);
}
