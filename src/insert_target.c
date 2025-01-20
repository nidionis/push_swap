/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_target.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 21:16:34 by supersko          #+#    #+#             */
/*   Updated: 2025/01/20 20:22:26 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	insert_target_in_a(t_lnk **lst_a, t_lnk **lst_b, int target_rank)
{
    reach_rank_lst_b(lst_a, lst_b, target_rank, PRINT);
    apply_instr(pa, lst_a, lst_b, PRINT);
    apply_instr(ra, lst_a, lst_b, PRINT);
}

int can_insert_in_b(t_lnk *lst_b, int target_rank)
{
	int	max;
	int	min;

	max = get_max(lst_b);
	min = get_min(lst_b);
    if (lst_b->rank < target_rank && (lst_b->prev)->rank > target_rank)
		return (TRUE);
    if (max < target_rank && max == lst_b->prev->rank)
		return (TRUE);
    if (min > target_rank && min == lst_b->rank)
		return (TRUE);
	return (FALSE);
}

int	next_lower_rank(t_lnk *lst_b, int target_rank)
{
    t_lnk *ind;
    int min;

    min = get_min(lst_b);
    if (min >= target_rank)
        return (min);
    ind = lst_b->next;
    while (ind != lst_b)
    {
        while (!can_insert_in_b(lst_b, target_rank))
            apply_instr(rrb, NULL, &lst_b, QUIET);
        return (lst_b->rank);
    }
    return (get_max(lst_b));
}

void	insert_target_in_b(t_lnk **lst_a, t_lnk **lst_b, int target_rank)
{
    target_rank = next_lower_rank(*lst_b, target_rank);
    reach_rank_lst_b(lst_a, lst_b, target_rank, PRINT);
    apply_instr(pb, lst_a, lst_b, PRINT);
}
