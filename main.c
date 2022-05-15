/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/15 22:29:05 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int main(int argc, char **argv)
{
	t_lnk	*lst_a = NULL;
	t_lnk	*lst_initial = NULL;
	t_lnk	*lst_b = NULL;

	if (argc < 2)
		error_msg(NULL);
	else if (argc == 2)
		lst_a = get_args_allinone(argv[1]);
	else
		lst_a = get_args(argc, argv);
	lst_init_ranks(&lst_a);
	set_initial_pointers(&lst_a);
	if (!ft_no_duplicate(lst_a))
		error_msg("Error: duplicated items");
	lst_initial = lst_a;
	print_lst(lst_a, "lsta");
	apply_instr(ra, &lst_a, &lst_b, NULL);
	apply_instr(ra, &lst_a, &lst_b, NULL);
	apply_instr(pb, &lst_a, &lst_b, NULL);
	apply_instr(ra, &lst_a, &lst_b, NULL);
	apply_instr(pb, &lst_a, &lst_b, NULL);
	apply_instr(pb, &lst_a, &lst_b, NULL);
	apply_instr(rr, &lst_a, &lst_b, NULL);
	reset_initial_pointers(&lst_a, &lst_b);
	print_lst(lst_initial, "initial ?");
	del_lst(&lst_a);
}
