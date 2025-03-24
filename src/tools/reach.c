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

void	reach_rank_dir(t_lnk **lst, int rank, int instr, int verbose)
{
	t_lnk	*first_lnk;
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	data.a.lst = *lst;
	data.b.lst = *lst;
	first_lnk = *lst;
	if (first_lnk->rank != rank)
	{
		apply_instr(&data, instr, verbose);
		while (data.a.lst != first_lnk)
		{
			if (data.a.lst->rank == rank)
				break ;
			apply_instr(&data, instr, verbose);
		}
	}
	if (*lst != data.a.lst)
		*lst = data.a.lst;
	else
		*lst = data.b.lst;
}

void	reach_rank_ls_quiet(t_lnk **lst, int rank)
{
	reach_rank_dir(lst, rank, get_shortestway(rank, *lst), QUIET);
}

int	reached_rank(int rank, t_data *data)
{
	return (get_shortestway(rank, data->a.lst) == 0 || get_shortestway(rank, data->b.lst) == 0);
}

int reach_rank(t_data *data, int rank, int verbose)
{
	int nb_instr;
	int instr;
	int way;
	t_lnk *lst;

	nb_instr = 0;
	lst = data->a.lst;
	instr = ra;
	if (is_rank_in_lst_forward(rank, lst) == NOT_FOUND)
	{
		lst = data->b.lst;
		instr = rb;
		if (is_rank_in_lst_forward(rank, lst) == NOT_FOUND)
			return (NOT_FOUND);
	}
	way = get_shortestway(rank, lst);
	if (way == RROTATE)
		instr = ft_rev_instr(instr);
	while (!reached_rank(rank, data))
		nb_instr += apply_instr(data, instr, verbose);
	return (nb_instr);
}