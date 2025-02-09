/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:49:48 by nidionis          #+#    #+#             */
/*   Updated: 2025/02/09 17:01:47 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_instr_step *create_instr_step(int instr)
{
    t_instr_step *instr_step;

    instr_step = malloc(sizeof(t_instr_step));
    if (!instr_step)
        return (NULL);
    instr_step->instr = instr;
    instr_step->nb_instr = SIZE_MAX;
    return (instr_step);
}

t_list *initialize_instr_step(int instr)
{
    t_instr_step *instr_step;

    instr_step = create_instr_step(instr);
    if (!instr_step)
        return (NULL);
    return (ft_lstnew(instr_step));
}

int find_best_instr(t_data *d_copy, int lst_instr[], int (*can_push)(t_data *), int max_cost)
{
    int i_instr = 0;
    int cost;
    int best_instr = lst_instr[0];
    int min_cost = SIZE_MAX;

    while (lst_instr[i_instr] != LOOP_END)
    {
        cost = count_instr(d_copy, lst_instr[i_instr], can_push, max_cost);
        if (cost < min_cost)
        {
            best_instr = lst_instr[i_instr];
            min_cost = cost;
            max_cost = cost;
        }
        i_instr++;
    }
    return best_instr;
}

t_list *best_insert(t_data *d, int lst_instr[], int (*can_push)(t_data *), int max_cost)
{
    t_data d_copy;
    t_list *instr_step_node;

    ft_memcpy(&d_copy, d, sizeof(t_data));
    instr_step_node = initialize_instr_step(lst_instr[0]);
    if (!instr_step_node)
        return (NULL);

    t_instr_step *instr_step = (t_instr_step *)instr_step_node->content;
    if (can_push(&d_copy))
    {
        instr_step->nb_instr = 0;
    }
    else
    {
        instr_step->instr = find_best_instr(&d_copy, lst_instr, can_push, max_cost);
        instr_step->nb_instr = count_instr(&d_copy, instr_step->instr, can_push, max_cost);
    }
    return (instr_step_node);
}

/*
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
*/

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
	t_list *first_intr_step_node;
	t_list *best_comb;

	ft_memcpy(&d_copy, d, sizeof(t_data));
	best_comb = NULL;
	first_intr_step_node = init_instr_step_node(instr, 0);
	t_instr_step *first_intr_step;
	first_intr_step = first_intr_step_node->content;
	while (first_intr_step->nb_instr < max_cost)
	{
		t_list *instr_step_node;
		instr_step_node = best_insert(&d_copy, d_copy.r_instr, can_push, max_cost);
		if (instr_step_node && first_intr_step->nb_instr + get_steps(instr_step_node) < max_cost - 1)
		{
			t_list *saved_first_instr;
			if (best_comb)
				ft_lstclear(&best_comb, free);
			best_comb = instr_step_node;
			saved_first_instr = init_instr_step_node(instr, first_intr_step->nb_instr);
			ft_lstadd_front(&best_comb, saved_first_instr);
			max_cost = ft_cost(best_comb);
		}
		else
		{
			first_intr_step->nb_instr++;
			apply_instr(&d_copy, instr, QUIET);
			ft_lstclear(&instr_step_node, free);
		}
	}
	ft_lstclear(&first_intr_step_node, free);
	return (best_comb);
}
