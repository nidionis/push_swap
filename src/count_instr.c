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

int	count_instr(t_data *data, int instr, int (*can_push)(t_data *data, t_lnk *lst_a, t_lnk *lst_b))
{
	t_lnk	*lst_a;
	t_lnk	*lst_b;
	int		count;

	lst_a = data->lst_a;
	lst_b = data->lst_b;
	count = 0;
	if (can_push(data, lst_a, lst_b))
		return (0);
	while (!can_push(data, lst_a, lst_b) && count < data->best_cost_comb)
	{
		apply_instr(data, &lst_a, &lst_b, instr, QUIET);
		count++;
	}
	if (count >= data->best_cost_comb)
		return (CANT_INSERT);
	return (count);
}