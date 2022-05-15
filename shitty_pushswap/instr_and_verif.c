/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_and_verif.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:10:33 by supersko          #+#    #+#             */
/*   Updated: 2022/05/15 22:29:05 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_instruction(char *instr, t_lst *lst_a, t_lst *lst_b)
{
	if (*instr == 's')
		swap(++instr, lst_a, lst_b);
	else if (*instr == 'p')
		push(++instr, lst_a, lst_b);
	else if (*instr == 'r')
		rotate(++instr, lst_a, lst_b);
	else
		error_msg(NULL);
}

int	verif(t_lst *lst_a)
{
	t_lnk	*lnk;

	lnk = lst_a->first;
	while (lnk->nb < (lnk->next)->nb && lnk != lst_a->last)
			lnk = lnk->next;
	if (lnk == lst_a->last)
		return (1);
	else
		return (0);
}
