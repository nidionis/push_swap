/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/02/02 19:16:36 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	init_cmd_map(t_cmd_map *cmd_map)
{
	cmd_map[0] = (t_cmd_map){sa, swap_a};
	cmd_map[1] = (t_cmd_map){sb, swap_b};
	cmd_map[2] = (t_cmd_map){ss, swap_both};
	cmd_map[3] = (t_cmd_map){ra, rotate_a};
	cmd_map[4] = (t_cmd_map){rb, rotate_b};
	cmd_map[5] = (t_cmd_map){rr, rotate_both};
	cmd_map[6] = (t_cmd_map){rra, rrotate_a};
	cmd_map[7] = (t_cmd_map){rrb, rrotate_b};
	cmd_map[8] = (t_cmd_map){rrr, rrotate_both};
	cmd_map[9] = (t_cmd_map){pa, push_a};
	cmd_map[10] = (t_cmd_map){pb, push_b};
	cmd_map[11] = (t_cmd_map){-1, NULL};
}

void	execute_command(t_lnk **lst_a, t_lnk **lst_b, int instr)
{
	static t_cmd_map	cmd_map[12];
	int					i;

	if (!cmd_map[0].code)
		init_cmd_map(cmd_map);
	i = 0;
	while (cmd_map[i].code != -1)
	{
		if (cmd_map[i].code == instr)
		{
			cmd_map[i].func(lst_a, lst_b);
			return ;
		}
		i++;
	}
	ft_errmsg("[execute_command] Invalid instruction");
}

void	apply_instr(t_data *data, t_lnk **lst_a, t_lnk **lst_b, int instr,
		int to_print)
{
	execute_command(lst_a, lst_b, instr);
	if (to_print)
		i_to_instr(instr);
	data_update(data, lst_a, lst_b);
}

int	find_instr_code(const char *str, const t_instr_map *map)
{
	if (!map->name)
	{
		ft_errmsg("[find_instr_code] Error");
		return (-1);
	}
	if (!ft_strncmp(str, map->name, ft_strlen(map->name)))
		return (map->code);
	return (find_instr_code(str, map + 1));
}

int	instr_to_i(char *str)
{
	static const t_instr_map	instr_map[] = {{"sa", sa}, {"sb", sb}, {"ss",
			ss}, {"ra", ra}, {"rb", rb}, {"rr", rr}, {"rra", rra}, {"rrb", rrb},
			{"rrr", rrr}, {"pa", pa}, {"pb", pb}, {NULL, -1}};

	return (find_instr_code(str, instr_map));
}

void	print_instr(int i, const t_instr_map *map)
{
	if (!map->name)
	{
		ft_errmsg("[i_to_instr]: instruction non reconnue\n");
		return ;
	}
	if (map->code == i)
	{
		printf("%s\n", map->name);
		return ;
	}
	print_instr(i, map + 1);
}

static void	init_instr_map(t_instr_map *instr_map)
{
	instr_map[0] = (t_instr_map){"sa", sa};
	instr_map[1] = (t_instr_map){"sb", sb};
	instr_map[2] = (t_instr_map){"ss", ss};
	instr_map[3] = (t_instr_map){"ra", ra};
	instr_map[4] = (t_instr_map){"rb", rb};
	instr_map[5] = (t_instr_map){"rr", rr};
	instr_map[6] = (t_instr_map){"rra", rra};
	instr_map[7] = (t_instr_map){"rrb", rrb};
	instr_map[8] = (t_instr_map){"rrr", rrr};
	instr_map[9] = (t_instr_map){"pa", pa};
	instr_map[10] = (t_instr_map){"pb", pb};
	instr_map[11] = (t_instr_map){NULL, -1};
}

void	i_to_instr(int i)
{
	static t_instr_map	instr_map[12];
	static int			is_initialized = 0;

	if (!is_initialized)
	{
		init_instr_map(instr_map);
		is_initialized = 1;
	}
	print_instr(i, instr_map);
}
