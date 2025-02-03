/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:49:48 by nidionis          #+#    #+#             */
/*   Updated: 2025/02/03 01:14:15 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	update_best_comb(int (*b_c)[4], int *instr_steps_itm1,
		int *instr_steps_itm2)
{
	int	*best_comb;
	int	new_best_comb[4];

	best_comb = *b_c;
	new_best_comb[FIRST_INSTR] = instr_steps_itm1[INSTR];
	new_best_comb[NB_FIRST_INSTR] = instr_steps_itm1[NB_INSTR];
	new_best_comb[SECOND_INSTR] = instr_steps_itm2[INSTR];
	new_best_comb[NB_SECOND_INSTR] = instr_steps_itm2[NB_INSTR];
	if (ft_cost(new_best_comb) < ft_cost(best_comb))
	{
		best_comb[FIRST_INSTR] = new_best_comb[FIRST_INSTR];
		best_comb[NB_FIRST_INSTR] = new_best_comb[NB_FIRST_INSTR];
		best_comb[SECOND_INSTR] = new_best_comb[SECOND_INSTR];
		best_comb[NB_SECOND_INSTR] = new_best_comb[NB_SECOND_INSTR];
	}
}

int	*best_insert(t_data *d, int lst_instr[],
		int (*can_push)(t_data *))
{
	t_data d_copy;
	int first_instr_steps[2];
	int i_instr = 0;

	ft_memcpy(&d_copy, d, sizeof(t_data));
	set_best_comb(d_copy.best_comb);

	while (lst_instr[i_instr] != LOOP_END)
	{
		set_instr_step_itm(lst_instr[i_instr], 0, first_instr_steps);

		if (can_push(&d_copy))
			return (malloc_instr_steps_itm(NULL));

		explore_insert_paths(&d_copy, lst_instr, first_instr_steps, can_push);

		ft_memcpy(d, &d_copy, sizeof(t_data));
		i_instr++;
	}
	return (malloc_best_insert(&d_copy));
}

void	explore_insert_paths(t_data *d, int lst_instr[], int first_instr_steps[], int (*can_push)(t_data *))
{
	int	*second_instr_steps;
	int	j_instr = 0;

	while (lst_instr[j_instr] != LOOP_END &&
		first_instr_steps[NB_INSTR]++ < ft_cost(d->best_comb))
	{
		apply_instr(d, lst_instr[j_instr], QUIET);
		second_instr_steps = insert_target_to_list_steps(d, lst_instr, can_push, ft_cost(d->best_comb));
		
		update_best_comb(&d->best_comb, first_instr_steps, second_instr_steps);
		d->best_cost_comb = ft_cost(d->best_comb);
		free(second_instr_steps);

		if (can_push(d))
			break;

		j_instr++;
	}
}
