/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/24 18:36:00 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	select_algo(t_lnk *lst_a, t_lnk *lst_b, int ind_max)
{
	if (ind_max == 1)
		sort_2_nb(&lst_a);
	else if (ind_max == 2)
		sort_3_nb(&lst_a, ind_max);
	else if (ind_max == 3)
		sort_4_nb(&lst_a, &lst_b);
	else if (ind_max == 4)
		sort_5_nb(&lst_a, &lst_b);
	else
	{
		load_b(&lst_a, &lst_b, ind_max);
		b_dump(&lst_a, &lst_b);
		reach_rank(&lst_a, 0, get_shortestway(0, lst_a));
	}
}

int	main(int argc, char **argv)
{
	t_lnk	*lst_a;
	t_lnk	*lst_b;
	int		ind_max;

	if (argc < 2)
		error_msg(NULL);
	else if (argc == 2)
		lst_a = get_args_allinone(argv[1]);
	else
		lst_a = get_args(argc, argv);
	ind_max = lst_init_ranks(&lst_a);
	if (!ft_no_duplicate(lst_a))
		error_msg("Error: duplicated items");
	select_algo(lst_a, lst_a, ind_max);
	del_lst(&lst_a);
	del_lst(&lst_b);
}
