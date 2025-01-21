/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/01/21 03:31:16 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	can_dirty_push_a(t_lnk *lst_a, t_lnk *lst_b)
{
	if (!lst_a)
		return (TRUE);
	if (!lst_b)
		return (FALSE);
	if (lst_a->rank > lst_b->rank && (lst_a->prev)->rank < lst_b->rank)
		return (TRUE);
	return (FALSE);
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

void	dump_softmax(t_lnk **lst_a, t_lnk **lst_b)
{
	if (is_a_softmax_a(*lst_a))
		while (is_a_softmax_a(*lst_a) && !is_sorted_a(*lst_a))
			apply_instr(TO_SOFTMIN, lst_a, lst_b, PRINT);
	while (*lst_b)
	{
		if (can_dirty_push_a(*lst_a, *lst_b))
			apply_instr(pa, lst_a, lst_b, PRINT);
		else
			apply_instr(TO_SOFTMIN, lst_a, lst_b, PRINT);
	}
}

void	dump_softmin(t_lnk **lst_a, t_lnk **lst_b)
{
	if (is_a_softmin_a(*lst_a))
		while (is_a_softmin_a(*lst_a) && !is_sorted_a(*lst_a))
			apply_instr(TO_SOFTMAX, lst_a, lst_b, PRINT);
	while (*lst_b)
	{
		if (can_dirty_push_a(*lst_a, *lst_b))
			apply_instr(pa, lst_a, lst_b, PRINT);
		else
			apply_instr(TO_SOFTMAX, lst_a, lst_b, PRINT);
	}
}

int	is_loadable_high(t_lnk *lnk, int gap, int last_min)
{
	if (is_a_softminmax_a(lnk))
			return (FALSE);
	if (lnk->rank > last_min && lnk->rank <= last_min + gap)
		return (TRUE);
	return (FALSE);
}

int nb_loaded_high(t_lnk *lnk, int gap, int softmin, int softmax)
{
	int	nb;
	int	last_min;

	nb = 0;
	last_min = (softmax - softmin) / 2;
	while (lnk->rank != softmax)
	{
		if (is_loadable_high(lnk, gap, last_min))
		{
			nb++;
			last_min = lnk->rank;	
		}
		lnk = lnk->next;
	}
	return (nb);
}

/* reach from softmin, push from median to softmax */
int find_best_step_high(t_lnk *lst, int step, int softmin, int softmax)
{
	(void)step;
	int		gap;
	int		best_gap;
	int		best;
	int		ret;

	gap = GAP_MAX;	
	best = 0;
	while (gap > 0)
	{
		ret = nb_loaded_high(lst, gap, softmin, softmax);
		if (ret > best)
		{
			best = ret;
			best_gap = gap;
		}
		gap -= GAP;
	}
	return (best_gap);
}

/* reach from softmin, push from median to softmax */
void	load_high(t_lnk **lst_a, t_lnk **lst_b, int step, int softmin, int softmax)
{
	(void)step;
	int		gap;
	int	last_min;

	last_min = (softmax - softmin) / 2;
	gap = find_best_step_high(*lst_a, step, softmin, softmax);
	while ((*lst_a)->rank != softmax)
	{
		if (is_loadable_high(*lst_a, gap, last_min))
		{
			apply_instr(pb, lst_a, lst_b, PRINT);
			last_min = (*lst_a)->rank;	
		}
		else
			apply_instr(TO_SOFTMAX, lst_a, lst_b, PRINT);
	}
}

int	is_loadable_low(t_lnk *lnk, int gap, int last_max)
{
	if (is_a_softminmax_a(lnk))
			return (FALSE);
	if (lnk->rank > last_max && lnk->rank >= last_max - gap)
		return (TRUE);
	return (FALSE);
}


int nb_loaded_low(t_lnk *lnk, int gap, int softmin, int softmax)
{
	int	nb;
	int	last_max;

	nb = 0;
	last_max = (softmax - softmin) / 2;
	while (lnk->rank != softmin)
	{
		if (is_loadable_low(lnk, gap, last_max))
		{
			nb++;
			last_max = lnk->rank;	
		}
		lnk = lnk->prev;
	}
	return (nb);
}

/* reach from softmin, push from median to softmax */
int find_best_step_low(t_lnk *lst, int step, int softmin, int softmax)
{
	(void)step;
	int		gap;
	int		best_gap;
	int		best;
	int		ret;

	gap = GAP_MAX;	
	best = 0;
	while (gap > 0)
	{
		ret = nb_loaded_low(lst, gap, softmin, softmax);
		if (ret > best)
		{
			best = ret;
			best_gap = gap;
		}
		gap -= GAP;
	}
	return (best_gap);
}

/* reach from softmin, push from median to softmax */
void	load_low(t_lnk **lst_a, t_lnk **lst_b, int step, int softmin, int softmax)
{
	int		gap;
	int	last_max;

	last_max = (softmax - softmin) / 2;
	gap = find_best_step_low(*lst_a, step, softmin, softmax);
	while ((*lst_a)->prev->rank != softmin)
	{
		if (is_loadable_low(*lst_a, gap, last_max))
		{
			apply_instr(pb, lst_a, lst_b, PRINT);
			last_max = (*lst_a)->rank;	
		}
		else
			apply_instr(TO_SOFTMIN, lst_a, lst_b, PRINT);
	}
}
