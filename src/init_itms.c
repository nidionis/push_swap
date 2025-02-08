/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_itms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 01:35:53 by nidionis          #+#    #+#             */
/*   Updated: 2025/02/03 01:38:22 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
void	update_best_comb(int (*b_c)[4], int *instr_steps_itm1, int *instr_steps_itm2)
{
	int	*best_comb;
	int	new_best_comb[4];

	best_comb = *b_c;
	new_best_comb[FIRST_INSTR] = instr_steps_itm1[INSTR];
	new_best_comb[NB_FIRST_INSTR] = instr_steps_itm1[NB_INSTR];
	if (instr_steps_itm2)
	{
		new_best_comb[SECOND_INSTR] = instr_steps_itm2[INSTR];
		new_best_comb[NB_SECOND_INSTR] = instr_steps_itm2[NB_INSTR];
	}
	else
	{
		new_best_comb[SECOND_INSTR] = NO_INSTR;
		new_best_comb[NB_SECOND_INSTR] = 0;
	}
	if (ft_cost(new_best_comb) < ft_cost(best_comb))
	{
		best_comb[FIRST_INSTR] = new_best_comb[FIRST_INSTR];
		best_comb[NB_FIRST_INSTR] = new_best_comb[NB_FIRST_INSTR];
		best_comb[SECOND_INSTR] = new_best_comb[SECOND_INSTR];
		best_comb[NB_SECOND_INSTR] = new_best_comb[NB_SECOND_INSTR];
	}
}

void	set_best_comb(int *best_comb)
{
	set_instr_step_itm(NO_INSTR, SIZE_MAX, &best_comb[FIRST_INSTR]);
	set_instr_step_itm(NO_INSTR, SIZE_MAX, &best_comb[SECOND_INSTR]);
}

void	update_best_instr(t_data *data, int instr_steps_itm[2])
{
	if (instr_steps_itm[NB_INSTR] < data->best_inst_step[NB_INSTR])
	{
		data->best_inst_step[INSTR] = instr_steps_itm[INSTR];
		data->best_inst_step[NB_INSTR] = instr_steps_itm[NB_INSTR];
		data->best_cost_instr = ft_cost(data->best_inst_step);
	}
}

void	set_instr_step_itm(int instr, int nb_instr, int *instr_steps_itm)
{
	instr_steps_itm[INSTR] = instr;
	instr_steps_itm[NB_INSTR] = nb_instr;
}
	*/