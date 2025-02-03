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

int	opposite_instr(int instr)
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