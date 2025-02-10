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
	set_minmax_load_low(&d, PRINT);
	del_lst(&d.lst_a);
	del_lst(&d.lst_b);
}
