/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/02/02 21:44:58 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	init_instr_map(t_instr_map *instr_map)
{
	instr_map[0] = (t_instr_map){"sa", sa, swap_a};
	instr_map[1] = (t_instr_map){"sb", sb, swap_b};
	instr_map[2] = (t_instr_map){"ss", ss, swap_both};
	instr_map[3] = (t_instr_map){"ra", ra, rotate_a};
	instr_map[4] = (t_instr_map){"rb", rb, rotate_b};
	instr_map[5] = (t_instr_map){"rr", rr, rotate_both};
	instr_map[6] = (t_instr_map){"rra", rra, rrotate_a};
	instr_map[7] = (t_instr_map){"rrb", rrb, rrotate_b};
	instr_map[8] = (t_instr_map){"rrr", rrr, rrotate_both};
	instr_map[9] = (t_instr_map){"pa", pa, push_a};
	instr_map[10] = (t_instr_map){"pb", pb, push_b};
	instr_map[11] = (t_instr_map){NULL, -1, NULL};
}

void	print_instr(int instr)
{
	t_instr_map	instr_map[12];
	int			i;

	i = 0;
	init_instr_map(instr_map);
	while (instr_map[i].name)
	{
		if (instr_map[i].code == instr)
		{
			printf("%s\n", instr_map[i].name);
			return ;
		}
		i++;
	}
}

void	execute_command(t_lnk **lst_a, t_lnk **lst_b, int instr)
{
	t_instr_map			instr_map[12];
	int					i;

	init_instr_map(instr_map);
	i = 0;
	while (instr_map[i].code != -1)
	{
		if (instr_map[i].code == instr)
		{
			instr_map[i].func(lst_a, lst_b);
			return ;
		}
		i++;
	}
	ft_errmsg("[execute_command] Invalid instruction");
}

void	apply_instr(t_data *data, int instr, int to_print)
{
	t_lnk	*lst_a;
	t_lnk	*lst_b;

	lst_a = data->lst_a;
	lst_b = data->lst_b;
	execute_command(lst_a, lst_b, instr);
	if (to_print == PRINT)
		print_instr(instr);
	data_update(data, lst_a, lst_b);
}
