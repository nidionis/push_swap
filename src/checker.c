/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/01/19 06:57:41 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
void	finishing(t_lnk *lst_a, t_lnk *lst_b, char *instruction)
{
	if (is_sorted(lst_a) && lst_b == NULL)
		printf("OK\n");
	else
		printf("KO\n");
	free(instruction);
	del_lst(&lst_a);
	del_lst(&lst_b);
}

int	main(int argc, char **argv)
{
	t_lnk	*lst_a;
	t_lnk	*lst_b;
	char	*instruction;
	int		ind_max;

	if (argc < 2)
		ft_errmsg("error\n");
	else if (argc == 2)
		lst_a = get_args_allinone(argv[1]);
	else
		lst_a = get_args(argc, argv);
	ind_max = lst_init_ranks(&lst_a);
	(void)ind_max;
	if (!ft_is_duplicate(lst_a))
		ft_errmsg("Error: duplicated items");
	instruction = get_next_line(0);
	while (instruction && *instruction != '\n')
	{
		apply_instr(instr_to_i(instruction), &lst_a, &lst_b, 0);
		free(instruction);
		instruction = get_next_line(0);
	}
	finishing(lst_a, lst_b, instruction);
	return (0);
}
*/