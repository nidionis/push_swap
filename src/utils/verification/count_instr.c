/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 01:36:32 by nidionis          #+#    #+#             */
/*   Updated: 2025/02/03 01:36:49 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	count_instr(t_data *data, int instr, int (*can_push)(t_data *data), int max)
{
	int		count;
	t_data	data_copy;

	/* Allow LOOP_END as a special case */
	if (instr == LOOP_END)
	{
		return (CANT_INSERT_ERROR);
	}
	/* Validate instruction range */
	if (instr < INSTR_MIN || instr > INSTR_MAX)
	{
		fprintf(stderr, "[count_instr] Invalid instruction code: %d\n", instr);
		return (CANT_INSERT_ERROR);
	}

	ft_memcpy(&data_copy, data, sizeof(t_data));

	count = 0;
	while (!can_push(&data_copy) && count < max)
	{
		apply_instr(&data_copy, instr, QUIET);
		count++;
	}
	if (count >= max)
		return (CANT_INSERT_ERROR);
	return (count);
}