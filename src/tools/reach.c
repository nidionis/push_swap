/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reach.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:47:40 by supersko          #+#    #+#             */
/*   Updated: 2025/04/03 20:50:07 by nidionis         ###   ########.fr       */
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

int	reach_rank_a(t_data *data, int rank, int verbose)
{
	int	nb_instr;
	int	way;
	int	instr;

    if (head(&data->a) == rank)
    {
        return (0);
    }
	way = get_shortestway(rank, data->a.lst);
	instr = rra;
	if (way == ROTATE)
		instr = ra;
	nb_instr = 0;
	while (data->a.lst->rank != rank)
		nb_instr += apply_instr(data, instr, verbose);
	return (nb_instr);
}

int	reach_rank_b(t_data *data, int rank, int verbose)
{
	int	nb_instr;
	int	way;
	int	instr;

	way = get_shortestway(rank, data->b.lst);
	instr = rrb;
	if (way == ROTATE)
		instr = rb;
	nb_instr = 0;
	while (data->b.lst->rank != rank)
		nb_instr += apply_instr(data, instr, verbose);
	return (nb_instr);
}
