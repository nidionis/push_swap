/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reach.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:47:40 by supersko          #+#    #+#             */
/*   Updated: 2025/02/01 22:15:44 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	instr_direction(int instr)
{
	if (instr == ra || instr == rb)
		return (rr);
	if (instr == rra || instr == rrb)
		return (rrr);
	if (instr == rr || instr == rrr)
		return (instr);
	return (ERR_INSTR);
}

void	reach_rank(t_lnk **lst, int rank, int instr, int verbose)
{
	t_lnk	*first_lnk;
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	data.lst_a = *lst;
	first_lnk = *lst;
	if (first_lnk->rank != rank)
	{
		apply_instr(&data, instr, verbose);
		while (data.lst_a != first_lnk)
		{
			if (data.lst_a->rank == rank)
				break ;
			apply_instr(&data, instr, verbose);
		}
	}
	*lst = data.lst_a;
}