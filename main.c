/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/16 22:16:57 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int main(int argc, char **argv)
{
	t_lnk	*lst_a = NULL;
	t_lnk	*lst_initial = NULL;
	//t_lnk	*lst_b = NULL;
	int		ind_max;

	if (argc < 2)
		error_msg(NULL);
	else if (argc == 2)
		lst_a = get_args_allinone(argv[1]);
	else
		lst_a = get_args(argc, argv);
	ind_max = lst_init_ranks(&lst_a);
	set_initial_pointers(&lst_a);
	if (!ft_no_duplicate(lst_a))
		error_msg("Error: duplicated items");
	lst_initial = lst_a;
	//apply_instr(rra, &lst_a, NULL, 0);
	ft_printf("ind max:%d\n", ind_max);
	ft_printf("%d\n", get_bestway(2, lst_a));
	print_lst_byrank(lst_a, "A");
	del_lst(&lst_a);
}
