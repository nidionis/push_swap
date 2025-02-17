/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/02/09 16:30:59 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_list *handle_best_comb(t_best_comb *best, t_list *instr_step_node, int instr, int nb_instr)
{
	t_list *saved_first_instr;
	if (best->best_comb)
		ft_lstclear(&best->best_comb, free);
	best->best_comb = instr_step_node;
	saved_first_instr = init_instr_step_node(instr, nb_instr);
	ft_lstadd_front(&best->best_comb, saved_first_instr);
	best->max_cost = ft_cost(best->best_comb);
	return (best->best_comb);
}

void handle_else_case(t_data *d_copy, t_instr_step *first_intr_step, int instr, t_list *instr_step_node)
{
	first_intr_step->nb_instr++;
	apply_instr(d_copy, instr, QUIET);
	ft_lstclear(&instr_step_node, free);
}

int should_update(t_best_comb *best, t_list *instr_step_node, int nb_first_instr)
{
	return (nb_first_instr + get_steps(instr_step_node) < best->max_cost);

}
t_list *best_insert_dir(t_data *d, int instr, int (*can_push)(t_data *), int max_cost)
{
	t_data d_copy;
	t_list *first_intr_step_node;
	t_instr_step *first_intr_step;
	t_best_comb best = {NULL, max_cost};

	ft_memcpy(&d_copy, d, sizeof(t_data));
	first_intr_step_node = init_instr_step_node(instr, 0);
	first_intr_step = first_intr_step_node->content;

	while (best.max_cost && first_intr_step->nb_instr < best.max_cost)
	{
		t_list *instr_step_node;
		instr_step_node = best_insert(&d_copy, d_copy.r_instr, can_push, best.max_cost - first_intr_step->nb_instr);
		if (!instr_step_node)
			ft_errmsg("[best_insert_dir] best_insert returned NULL");
		else if (should_update(&best, instr_step_node, first_intr_step->nb_instr))
			best.best_comb = handle_best_comb(&best, instr_step_node, instr, first_intr_step->nb_instr);
		else
			handle_else_case(&d_copy, first_intr_step, instr, instr_step_node);
	}
	ft_lstclear(&first_intr_step_node, free);
	return (best.best_comb);
}


/*
t_list *handle_best_comb(t_list **best_comb, t_list *instr_step_node, int instr, int nb_instr)
{
	t_list *saved_first_instr;
	if (*best_comb)
		ft_lstclear(best_comb, free);
	*best_comb = instr_step_node;
	saved_first_instr = init_instr_step_node(instr, nb_instr);
	ft_lstadd_front(best_comb, saved_first_instr);
	return (*best_comb);
}

void handle_no_best_comb(t_list *first_intr_step_node, t_data *d_copy, int instr)
{
	t_instr_step *first_intr_step;
	first_intr_step = first_intr_step_node->content;
	first_intr_step->nb_instr++;
	apply_instr(d_copy, instr, QUIET);
}

void best_insert_loop(t_data *d_copy, int instr, int (*can_push)(t_data *), int *max_cost, t_list **best_comb)
{
	t_list *first_intr_step_node = init_instr_step_node(instr, 0);
	t_instr_step *first_intr_step = first_intr_step_node->content;
	while (first_intr_step->nb_instr < *max_cost)
	{
		t_list *instr_step_node = best_insert(d_copy, d_copy->r_instr, can_push, *max_cost);
		if (instr_step_node && first_intr_step->nb_instr + get_steps(instr_step_node) < *max_cost - 1)
		{
			*best_comb = handle_best_comb(best_comb, instr_step_node, instr, first_intr_step->nb_instr);
			*max_cost = ft_cost(*best_comb);
		}
		else
		{
			handle_no_best_comb(first_intr_step_node, d_copy, instr);
			ft_lstclear(&instr_step_node, free);
		}
	}
	ft_lstclear(&first_intr_step_node, free);
}

t_list *best_insert_dir(t_data *d, int instr, int (*can_push)(t_data *), int max_cost)
{
	t_data d_copy;
	t_list *best_comb = NULL;

	ft_memcpy(&d_copy, d, sizeof(t_data));
	best_insert_loop(&d_copy, instr, can_push, &max_cost, &best_comb);
	return (best_comb);
}
*/