
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/24 19:36:41 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int is_next_sorted_lst_a(t_lnk *lst)
{
    return (lst->rank + 1 == lst->next->rank);
}

int is_a_softminmax_b(t_lnk *lst)
{
    return (lst->rank <= get_softmin_in_b(lst) || lst->rank >= get_softmax_in_b(lst));
}

int is_a_softmax_a(t_lnk *lst)
{
    return (lst->rank >= get_softmax_in_a(lst));
}

int is_a_softmin_a(t_lnk *lst)
{
    return (lst->rank <= get_softmin_in_a(lst));
}

int is_a_softminmax_a(t_lnk *lst)
{
    return (lst->rank <= get_softmin_in_a(lst) || lst->rank >= get_softmax_in_a(lst));
}

void if_next_softmin_in_b_insert_it(t_lnk **lst_a, t_lnk **lst_b)
{
    t_lnk	*ind;

    ind = *lst_a;
    if (!is_next_sorted_lst_a(ind))
        if (is_in_lst(*lst_b, ind->rank + 1))
                while (is_in_lst(*lst_b, ind->rank + 1))
                    insert_target_in_a(&ind, lst_b, ind->rank + 1);
}

void swap_b_if_needed(t_lnk **lst_b)
{
    if ((*lst_b)->rank > (*lst_b)->next->rank && !is_a_softminmax_b((*lst_b)))
        apply_instr(sb, lst_b, lst_b, PRINT);
}

void    smart_push_in_b(t_lnk **lst_a, t_lnk **lst_b)
{
    if (!*lst_b)
        apply_instr(pb, lst_a, lst_b, PRINT);
    else
    {
		if ((*lst_b)->next != (*lst_b))
			swap_b_if_needed(lst_b);
        if (!is_a_softminmax_a(*lst_a))
            insert_target_in_b(lst_a, lst_b, (*lst_a)->rank);
		else
		{
			b_dump_dirty(lst_a, lst_b);
			//dummy_reach_and_push_softmax(lst_a, lst_b);
			////sort_from_min_to_max(lst_a, lst_b);
		}
    }
}

void sort_from_min_to_max(t_lnk **lst_a, t_lnk **lst_b)
{
	int softmin;

	softmin = get_softmin_in_a(*lst_a);
    while (!is_sorted_a(*lst_a))
	{
    	if (is_a_softmin_a((*lst_a)->prev))
    	    apply_instr(rra, lst_a, lst_b, PRINT);
    	else if (is_in_lst(*lst_b, softmin + 1))
    	    insert_target_in_a(lst_a, lst_b, softmin - 1);
		else if (is_a_softmin_a(*lst_a) && !*lst_b)
    	    apply_instr(rra, lst_a, lst_b, PRINT);
    	else if (!is_a_softmin_a(*lst_a))
    	    smart_push_in_b(lst_a, lst_b);
		else
		{
			b_dump_dirty(lst_a, lst_b);
			dummy_reach_and_push_softmin(lst_a, lst_b);
			sort_from_max_to_min(lst_a, lst_b);
		}
	}
}

void sort_from_max_to_min(t_lnk **lst_a, t_lnk **lst_b)
{
	int softmax;

	softmax = get_softmax_in_a(*lst_a);
    while (!is_sorted_a(*lst_a))
	{
    	if (is_a_softmax_a((*lst_a)->next))
    	    apply_instr(ra, lst_a, lst_b, PRINT);
    	else if (is_in_lst(*lst_b, softmax - 1))
    	    insert_target_in_a(lst_a, lst_b, softmax + 1);
		else if (is_a_softmax_a(*lst_a) && !*lst_b)
    	    apply_instr(ra, lst_a, lst_b, PRINT);
    	else if (!is_a_softmax_a(*lst_a))
    	    smart_push_in_b(lst_a, lst_b);
		else
		{
			b_dump_dirty(lst_a, lst_b);
			dummy_reach_and_push_softmax(lst_a, lst_b);
			sort_from_min_to_max(lst_a, lst_b);
		}
	}
}

int dummy_stack_if_higher(t_lnk *lst_a, t_lnk *lst_b)
{
    (void)lst_b;
    if (is_a_softminmax_a(lst_a))
        return (FALSE);
    if (!lst_b)
        return (TRUE);
    return (lst_a->rank > lst_b->next->rank);
}

int dummy_stack_if_lower(t_lnk *lst_a, t_lnk *lst_b)
{
    (void)lst_b;
    if (is_a_softminmax_a(lst_a))
        return (FALSE);
    if (!lst_b)
        return (TRUE);
    return (lst_a->rank < lst_b->rank);
}

int stack_if_higher(t_lnk *lst_a, t_lnk *lst_b, int rank)
{
    (void)lst_b;
    if (is_a_softminmax_a(lst_a))
        return (FALSE);
    if (!lst_b)
        return (TRUE);
    return (lst_a->rank < rank && lst_a->rank < lst_b->next->rank);
}

void dummy_reach_and_push_softmin(t_lnk **lst_a, t_lnk **lst_b)
{
	int softmin;

	softmin = get_softmax_in_a(*lst_a);
    while ((*lst_a)->rank != softmin)
    {
        if (dummy_stack_if_higher(*lst_a, *lst_b))
            apply_instr(pb, lst_a, lst_b, PRINT);
		else
			apply_instr(ra, lst_a, lst_b, PRINT);
    }
}

void dummy_reach_and_push_softmax(t_lnk **lst_a, t_lnk **lst_b)
{
	int softmax;

	softmax = get_softmax_in_a(*lst_a);
    while ((*lst_a)->rank != softmax)
    {
        if (dummy_stack_if_lower(*lst_a, *lst_b))
            apply_instr(pb, lst_a, lst_b, PRINT);
		else
			apply_instr(rra, lst_a, lst_b, PRINT);
    }
    //apply_instr(pb, lst_a, lst_b, PRINT);
}

/* rrb push max to allow to load even more */
void dump_max_next_to_zero(t_lnk **lst_a, t_lnk **lst_b)
{
    int max;
    int direction;

    max = get_max(*lst_b);
	direction = get_shortestway(*lst_a, 0);
	if (direction == ROTATE)
		direction = ra;
    else
        direction = rra;
    while ((*lst_a)->rank != 0)
    {
        if (stack_if_higher(*lst_a, *lst_b, max))
            apply_instr(pb, lst_a, lst_b, PRINT);
        apply_instr(direction, lst_a, lst_b, PRINT);
    }
	reach_rank_lst_b(lst_a, lst_b, max, PRINT);
    apply_instr(pa, lst_a, lst_b, PRINT);
}

void smart_reach_and_push_max(t_lnk **lst_a, t_lnk **lst_b)
{
    int max;
    int direction;

    max = get_max(*lst_a);
	direction = get_shortestway(*lst_a, max);
	if (direction == ROTATE)
		direction = ra;
    else
        direction = rra;
    while ((*lst_a)->rank != max)
    {
        if (stack_if_higher(*lst_a, *lst_b, max / 2))
            apply_instr(pb, lst_a, lst_b, PRINT);
		else
			apply_instr(direction, lst_a, lst_b, PRINT);
    }
    apply_instr(pb, lst_a, lst_b, PRINT);
}

int find_best_step(t_lnk *lst_a, t_lnk *lst_b, int step)
{
	t_lnk	*ind;
	int		gap;
	int		best_gap;
	int		best;
	int		ret;

	gap = GAP_MAX;	
	best = 0;
	while (gap > GAP)
	{
		ret = nb_loaded(lst_a, gap);
		if (ret > best)
		{
			best = ret;
			best_gap = gap;
		}
		gap -= GAP
	}
	return (best_gap);
}
