/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_do_apply_comb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:45:30 by nidionis          #+#    #+#             */
/*   Updated: 2025/02/03 01:10:39 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	swap_if_high_to_dump(t_data *data, int instr)
{
	if (data->max_b == data->rank_max || data->min_b == 0)
		if (data->lst_a->rank == data->rank_max || data->lst_a->rank == 0)
			return (BREAK_BEST_COMB);
	return (swap_if_high(data, instr));
}

int	swap_if_softmax(t_data *data, int instr)
{
	t_lnk	*lst_a;

	(void)lst_a;
	(void)instr;
	(void)data;
	lst_a = data->lst_a;
	if (lst_a->rank == data->softmax_a - 1 && lst_a->next->next->rank == data->softmax_a)
	{
		apply_instr(data, sa, PRINT);
		return (BREAK);
	}
	if (lst_a->prev->rank == data->softmin_a + 1 && lst_a->prev->rank == data->softmin_a)
	{
		apply_instr(data, sa, PRINT);
		return (BREAK);
	}
	return (IGNORE);
}

int	swap_if_low(t_data *data, int instr)
{
	t_lnk	*lst_a;

	(void)lst_a;
	lst_a = data->lst_a;
	if (instr == ra || instr == rr)
		return (IGNORE);
	//if (swap_if_softmax(data, instr))
	//	return (IGNORE);
	//if (lst_a->rank < data->mediane_a && lst_a->next->rank < data->mediane_a)
	//{
	//	if (lst_a->next->rank < lst_a->rank)
	//		apply_instr(data, sa, PRINT);
	//}
	return (IGNORE);
}

int	swap_if_high(t_data *data, int instr)
{
	t_lnk	*lst_a;

	(void)instr;
	(void)lst_a;
	lst_a = data->lst_a;
	if (instr == ra || instr == rr)
		return (IGNORE);
	//if (swap_if_softmax(data, instr))
	//	return (IGNORE);
	//if (lst_a->rank > data->mediane_a && lst_a->next->rank > data->mediane_a)
	//{
	//	if (lst_a->next->rank < lst_a->rank)
	//		apply_instr(data, sa, PRINT);
	//}
	return (IGNORE);
}