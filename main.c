/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/15 17:17:23 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int main(int argc, char **argv)
{
	t_lnk	*lst_a = NULL;

	if (argc < 2)
		error_msg(NULL);
	else if (argc == 2)
		lst_a = get_args_allinone(argv[1]);
	else
		lst_a = get_args(argc, argv);
	lst_init_ranks(&lst_a);
	if (!ft_no_duplicate(&lst_a))
		error_msg("Error: duplicated items");
	apply_instr(rra, &lst_a, NULL, NULL);
	print_lst(lst_a, "lsta");
	del_lst(&lst_a);
}
