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
		int cost = SIZE_MAX;
		while (lst_instr[i_instr] != LOOP_END)
		{
			cost = count_instr(&d_copy, lst_instr[i_instr], can_push, max_cost);
			if (cost < instr_step->nb_instr)
			{
				instr_step->instr = lst_instr[i_instr];
				instr_step->nb_instr = cost;
				max_cost = cost;
			}
			i_instr++;
		}
	}
	return (instr_step_node);
}

int get_steps(t_list *instr_step_node)
{
	t_instr_step *instr_step;

	instr_step = instr_step_node->content;
	return (instr_step->nb_instr);
}

t_list *init_instr_step_node(int instr, int nb_instr_init)
{
	t_instr_step *first_intr_step;
	t_list *first_intr_step_node;

	first_intr_step = malloc(sizeof(t_instr_step));
	if (!first_intr_step)
		return (NULL);
	first_intr_step->instr = instr;
	first_intr_step->nb_instr = nb_instr_init;
	first_intr_step_node = ft_lstnew(first_intr_step);
	return (first_intr_step_node);
}

t_list	*best_insert_dir(t_data *d, int instr, int (*can_push)(t_data *), int max_cost)
{
	t_data d_copy;
	t_list *best_instr_step_node;
	t_list *first_intr_step_node;

	ft_memcpy(&d_copy, d, sizeof(t_data));
	best_instr_step_node = NULL;
	first_intr_step_node = init_instr_step_node(instr, 0);
	t_instr_step *first_intr_step;
	first_intr_step = first_intr_step_node->content;
	while (first_intr_step->nb_instr < max_cost)
	{
		t_list *instr_step_node;
		instr_step_node = best_insert(&d_copy, &instr, can_push, max_cost);
		if (instr_step_node && first_intr_step->nb_instr + get_steps(instr_step_node) > max_cost)
		{
			if (best_instr_step_node)
				ft_lstclear(&best_instr_step_node, free);
			best_instr_step_node = instr_step_node;
			max_cost = first_intr_step->nb_instr + get_steps(best_instr_step_node);
		}
		else
		{
			first_intr_step->nb_instr++;
			apply_instr(&d_copy, instr, QUIET);
			free(instr_step_node);
		}
	}
	ft_lstadd_front(&best_instr_step_node, first_intr_step_node);
	return (best_instr_step_node);
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
