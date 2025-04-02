/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:49:48 by nidionis          #+#    #+#             */
/*   Updated: 2025/04/02 21:55:20 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_instr_step(t_data *d_copy, t_instr_step *instr_step,
		int lst_instr[], int (*can_push)(t_data *), int *max_cost)
{
	int	cost;
	int	i_instr;

	cost = SIZE_MAX;
	i_instr = 0;
	while (lst_instr[i_instr] != LOOP_END)
	{
		cost = count_instr(d_copy, lst_instr[i_instr], can_push, *max_cost);
		if (cost < instr_step->nb_instr)
		{
			instr_step->instr = lst_instr[i_instr];
			instr_step->nb_instr = cost;
			*max_cost = cost;
		}
		i_instr++;
	}
}

t_list	*best_insert(t_data *d, int lst_instr[], int (*can_push)(t_data *),
		int max_cost)
{
	t_data			d_copy;
	t_list			*instr_step_node;
	t_instr_step	*instr_step;

	ft_memcpy(&d_copy, d, sizeof(t_data));
	instr_step = malloc(sizeof(t_instr_step));
	if (!instr_step)
		return (NULL);
	instr_step->instr = lst_instr[0];
	d_copy.r_instr = lst_instr;
	instr_step->nb_instr = SIZE_MAX;
	instr_step_node = ft_lstnew(instr_step);
	if (can_push(&d_copy))
	{
		instr_step->nb_instr = 0;
	}
	else
	{
		update_instr_step(&d_copy, instr_step, lst_instr, can_push, &max_cost);
	}
	return (instr_step_node);
}

int	get_steps(t_list *instr_step_node)
{
	t_instr_step	*instr_step;

	instr_step = instr_step_node->content;
	return (instr_step->nb_instr);
}

t_list	*init_instr_step_node(int instr, int nb_instr_init)
{
	t_instr_step	*first_intr_step;
	t_list			*first_intr_step_node;

	first_intr_step = malloc(sizeof(t_instr_step));
	if (!first_intr_step)
		return (NULL);
	first_intr_step->instr = instr;
	first_intr_step->nb_instr = nb_instr_init;
	first_intr_step_node = ft_lstnew(first_intr_step);
	return (first_intr_step_node);
}
