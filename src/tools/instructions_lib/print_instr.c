/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:49:48 by nidionis          #+#    #+#             */
/*   Updated: 2025/04/02 17:00:28 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_instr(t_data *data, int instr)
{
	t_instr_map	*instr_map;
	int			i;

	i = 0;
	instr_map = data->instr_map;
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
