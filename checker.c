/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/15 22:29:05 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
int main(int argc, char **argv)
{
	t_lnk	*lst_a = NULL;
	t_lnk	*lst_b = NULL;
	char	*instruction;

	if (argc < 2)
		error_msg(NULL);
	else
		lst_a = get_args(argc, argv);
	lst_init_ranks(&lst_a);
	if (!ft_no_duplicate(lst_a))
		error_msg("Error: duplicated items");
	instruction = get_next_line(0);
	while (*instruction != '\n')
	{
		apply_instr(instr_to_i(instruction), &lst_a, &lst_b, 0);
//		print_lst(lst_a, "lst_a");
//		print_lst(lst_b, "lst_b");
		instruction = get_next_line(0);
		ft_printf("%s\n", instruction);
	}
	if (ft_is_sorted(lst_a) && lst_b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	del_lst(&lst_a);
	del_lst(&lst_b);
	return (0);
}
*/
