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

t_list	*best_insert(t_data *d, int lst_instr[], int (*can_push)(t_data *), int max_cost)
{
	t_data d_copy;
	t_list *instr_step_node;
	int i_instr = 0;

	ft_memcpy(&d_copy, d, sizeof(t_data));

	t_instr_step *instr_step;
	instr_step = malloc(sizeof(t_instr_step));
	if (!instr_step)
		return (NULL);
	instr_step->instr = lst_instr[i_instr];
	instr_step->nb_instr = SIZE_MAX;
	instr_step_node= ft_lstnew(instr_step);

	if (can_push(&d_copy))
	{
		instr_step->nb_instr = 0;
	}
	else
	{
		while (lst_instr[i_instr] != LOOP_END)
		{
			instr_step->instr = lst_instr[i_instr];
			while (!can_push(&d_copy))
			{
				if (instr_step->nb_instr >= max_cost)
				{
					instr_step->instr = NO_INSTR;
					instr_step->nb_instr = CANT_INSERT;
					break ;
				}
				else
				{
					apply_instr(&d_copy, lst_instr[i_instr], QUIET);
					instr_step->nb_instr++;
					if (can_push(&d_copy))
						break ;
				}
			}
			i_instr++;
		}
	}
	return (instr_step_node);
}

//void	explore_insert_paths(t_data *d, int lst_instr[], int first_instr_steps[], int (*can_push)(t_data *))
//{
//	int	*second_instr_steps;
//	int	j_instr = 0;
//
//	while (first_instr_steps[NB_INSTR]++ < ft_cost(d->best_comb))
//	{
//		apply_instr(d, lst_instr[j_instr], QUIET);
//		second_instr_steps = insert_target_to_list_steps(d, lst_instr, can_push, ft_cost(d->best_comb));
//		j_instr++;
//	}
//	//while (lst_instr[j_instr] != LOOP_END && first_instr_steps[NB_INSTR]++ < ft_cost(d->best_comb))
//	//{
//	//	apply_instr(d, lst_instr[j_instr], QUIET);
//	//	second_instr_steps = insert_target_to_list_steps(d, lst_instr, can_push, ft_cost(d->best_comb));
//	//	if (can_push(d))
//	//	{
//	//		update_best_comb(&d->best_comb, first_instr_steps, second_instr_steps);
//	//		d->best_cost_comb = ft_cost(d->best_comb);
//	//		free(second_instr_steps);
//	//		break;
//	//	}
//	//	else
//	//		free(second_instr_steps);
//	//	j_instr++;
//	//}
//}
//
