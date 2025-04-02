/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:43:44 by nidionis          #+#    #+#             */
/*   Updated: 2025/04/02 17:14:27 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_instr_steps(int instr_steps_itm[2])
{
	int	instr;

	instr = instr_steps_itm[INSTR];
	printf("instr: %i ", instr_steps_itm[NB_INSTR]);
	if (instr == ra)
		printf("ra ");
	else if (instr == rb)
		printf("rb ");
	else if (instr == rra)
		printf("rra ");
	else if (instr == rrb)
		printf("rrb ");
	else if (instr == rr)
		printf("rr ");
	else if (instr == rrr)
		printf("rrr ");
	else if (instr == pa)
		printf("pa ");
	else if (instr == pb)
		printf("pb ");
	else
		printf("%i is weird instruction", instr);
	printf("\n");
}

void	print_data(t_data *d)
{
	printf("max_a: %d\n", d->a.max);
	printf("max_b: %d\n", d->b.max);
	printf("min_a: %d\n", d->a.min);
	printf("min_b: %d\n", d->b.min);
	printf("softmax_a: %d\n", d->a.softmax);
	printf("softmax_b: %d\n", d->b.softmax);
	printf("softmin_a: %d\n", d->a.softmin);
	printf("softmin_b: %d\n", d->b.softmin);
	printf("rank_max: %d\n", d->rank_max);
}
