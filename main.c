/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndionis <ndionis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/01/18 14:31:32 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	select_algo(t_lnk *lst_a, t_lnk *lst_b, int ind_max)
{
	if (ind_max == 0)
		del_lst(&lst_a);
	else if (ind_max == 1)
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
	}
	reach_rank(&lst_a, 0, get_shortestway(0, lst_a));
}

int	main(int argc, char **argv)
{
	t_lnk	*lst_a;
	t_lnk	*lst_b;
	int		ind_max;

	lst_b = NULL;
	if (argc < 2)
		return (1);
	else if (argc == 2)
	{
		if (!(*argv[1]))
			exit(0);
		//lst_a = get_args_allinone(argv[1]);
	}
	else
		lst_a = get_args(argc, argv);
	ind_max = lst_init_ranks(&lst_a);
	if (!ft_no_duplicate(lst_a))
		error_msg(NULL);
	if (!is_sorted(lst_a))
		select_algo(lst_a, lst_b, ind_max);
	del_lst(&lst_a);
	del_lst(&lst_b);
}
