/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algobsolete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/01/20 21:21:14 by nidionis         ###   ########.fr       */
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

int	can_push_a(t_lnk *lst_a, t_lnk *lst_b)
{
	if (!lst_a)
		return (TRUE);
	if (!lst_b)
		return (FALSE);
	if (lst_a->rank - 1 == lst_b->rank && (lst_a->prev)->rank + 1 == lst_b->rank)
		return (TRUE);
	return (FALSE);
}

int	can_push_b(t_lnk *lst_a, t_lnk *lst_b)
{
	if (!lst_a)
		return (FALSE);
	if (lst_a->rank > lst_b->rank && (lst_b->prev)->rank < lst_a->rank)
		return (TRUE);
	if (!lst_b || lst_b->next == lst_b)
		return (TRUE);
	return (FALSE);
}

int is_rotate_instr(int instr)
{
	if (instr == ra || instr == rra || instr == rr)
		return (TRUE);
	if (instr == rb || instr == rrb || instr == rrr)
		return (TRUE);
	return (FALSE);
}

void itm_dirty_insert_loop(t_lnk *lst_a, t_lnk *lst_b, int instr, int *best_result)
{
    int steps = 0;

    while (!can_dirty_push_a(lst_a, lst_b) && steps < LOOP_MAX)
	{
        if (is_rotate_instr(instr)) {
            apply_instr(instr, &lst_a, &lst_b, QUIET);
        }
        if (steps >= best_result[NB_FIRST_INSTR]) {
            break;
        }
        steps++;
    }
    if (steps < best_result[NB_FIRST_INSTR])
	{
        best_result[FIRST_INSTR] = instr;
        best_result[NB_FIRST_INSTR] = steps;
    }
}

void itm_insert_loop(t_lnk *lst_a, t_lnk *lst_b, int instr, int *best_result)
{
    int steps = 0;

    while (!can_push_a(lst_a, lst_b) && steps < LOOP_MAX)
	{
        if (is_rotate_instr(instr)) {
            apply_instr(instr, &lst_a, &lst_b, QUIET);
        }
        if (steps >= best_result[NB_FIRST_INSTR]) {
            break;
        }
        steps++;
    }
    if (steps < best_result[NB_FIRST_INSTR])
	{
        best_result[FIRST_INSTR] = instr;
        best_result[NB_FIRST_INSTR] = steps;
    }
}

int *itm_dirty_insert(t_lnk *lst_a, t_lnk *lst_b) {
    int instr;
    int *best_result = malloc(sizeof(int) * 2);

    if (!best_result) {
        ft_errmsg("[itm_insert] did not malloc");
        return NULL;
    }

    best_result[NB_FIRST_INSTR] = INT_MAX;
    for (instr = ROTATE_MIN; instr <= ROTATE_MAX; instr++)
	{
        if (is_rotate_instr(instr))
		{
            itm_dirty_insert_loop(lst_a, lst_b, instr, best_result);
        }
    }

    return best_result;
}

int *itm_insert(t_lnk *lst_a, t_lnk *lst_b) {
    int instr;
    int *best_result = malloc(sizeof(int) * 2);

    if (!best_result) {
        ft_errmsg("[itm_insert] did not malloc");
        return NULL;
    }

    best_result[NB_FIRST_INSTR] = INT_MAX;
    for (instr = ROTATE_MIN; instr <= ROTATE_MAX; instr++)
	{
        if (is_rotate_instr(instr))
		{
            itm_insert_loop(lst_a, lst_b, instr, best_result);
        }
    }

    return best_result;
}

int refresh_best_combs(int *best_comb, int instr, int steps, int *instr_steps_item) {
    int steps_max = best_comb[NB_FIRST_INSTR] + best_comb[NB_SECOND_INSTR];

    if (instr_steps_item[NB_FIRST_INSTR] + steps < steps_max) {
        best_comb[FIRST_INSTR] = instr;
        best_comb[NB_FIRST_INSTR] = steps;
        best_comb[SECOND_INSTR] = instr_steps_item[FIRST_INSTR];
        best_comb[NB_SECOND_INSTR] = instr_steps_item[NB_FIRST_INSTR];
    }

    free(instr_steps_item);
    return best_comb[NB_FIRST_INSTR] + best_comb[NB_SECOND_INSTR];
}

void refresh_dirty_in_dir(t_lnk *lst_a, t_lnk *lst_b, int instr, int *best_comb) {
    int steps = 0;
    int *instr_steps_item;

    while (++steps < best_comb[NB_FIRST_INSTR] + best_comb[NB_SECOND_INSTR]) {
        if (is_rotate_instr(instr)) {
            apply_instr(instr, &lst_a, &lst_b, QUIET);
            instr_steps_item = itm_dirty_insert(lst_a, lst_b);
            refresh_best_combs(best_comb, instr, steps, instr_steps_item);
        }
    }
}

void refresh_in_dir(t_lnk *lst_a, t_lnk *lst_b, int instr, int *best_comb) {
    int steps = 0;
    int *instr_steps_item;

    while (++steps < best_comb[NB_FIRST_INSTR] + best_comb[NB_SECOND_INSTR]) {
        if (is_rotate_instr(instr)) {
            apply_instr(instr, &lst_a, &lst_b, QUIET);
            instr_steps_item = itm_insert(lst_a, lst_b);
            refresh_best_combs(best_comb, instr, steps, instr_steps_item);
        }
    }
}
