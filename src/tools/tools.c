/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 01:37:34 by nidionis          #+#    #+#             */
/*   Updated: 2025/02/03 01:37:42 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	ft_rev_instr(int instr)
{
	if (instr == ra)
		return (rra);
	if (instr == rb)
		return (rrb);
	if (instr == rra)
		return (ra);
	if (instr == rrb)
		return (rb);
	if (instr == rr)
		return (rrr);
	if (instr == rrr)
		return (rr);
	return (-42);
}

int mirror_instr(const int instr)
{
	if (instr == ra)
		return rb;
	if (instr == rb)
		return ra;
	if (instr == rra)
		return rrb;
	if (instr == rrb)
		return rra;
	if (instr == sa)
		return sb;
	if (instr == sb)
		return sa;
	if (instr == pa)
		return pb;
	if (instr == pb)
		return pa;
	return instr;
}

int ft_nb_instr(t_list *instr_step_node)
{
	int nb_instr;
	t_instr_step *instr_step;

	nb_instr = 0;
	while (instr_step_node)
	{
		instr_step = instr_step_node->content;
		nb_instr += instr_step->nb_instr;
		instr_step_node = instr_step_node->next;
	}
	return (nb_instr);	
}