/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algobsolete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/01/20 17:02:50 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	can_push_a(t_lnk *lst_a, t_lnk *lst_b)
{
	if (!lst_a)
		return (TRUE);
	if (!lst_b)
		return (FALSE);
	if (lst_a->rank > lst_b->rank && (lst_a->prev)->rank < lst_b->rank)
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

/*
void	itm_insert_loop(t_lnk *lst_a, t_lnk *lst_b, int instr, int *best_result)
{
	int	steps;
	t_lnk *ind[2];

	steps = 0;
	ind[0] = lst_a->prev;
	ind[1] = lst_b->prev;
	while (!can_push_a(lst_a, lst_b) && lst_a != ind[0] && lst_b != ind[1])
	{
		if (is_rotate_instr(instr))
			apply_instr(instr, &lst_a, &lst_b, QUIET);
		if (steps >= best_result[NB_FIRST_INSTR])
			break ;
		steps++;
	}
	if (steps < best_result[NB_FIRST_INSTR])
	{
		best_result[FIRST_INSTR] = instr;
		best_result[NB_FIRST_INSTR] = steps;
	}
	if (lst_a == ind[0] || lst_b == ind[1])
		best_result[NB_FIRST_INSTR] = 0;
}

int	*itm_insert(t_lnk *lst_a, t_lnk *lst_b)
{
	int		instr;
	t_lnk	*lst_a_init;
	t_lnk	*lst_b_init;
	int		*best_result;

	best_result = malloc(sizeof(int) * 2);
	if (!best_result)
		ft_errmsg("[itm_insert] did not malloc");
	instr = ROTATE_MIN;
	lst_a_init = lst_a;
	lst_b_init = lst_b;
	if (!can_push_a(lst_a, lst_b))
	{
		while (instr <= ROTATE_MAX)
		{
			best_result[NB_FIRST_INSTR] = 2147483647;
			if (is_rotate_instr(instr))
				itm_insert_loop(lst_a, lst_b, instr, best_result);
			lst_a = lst_a_init;
			lst_b = lst_b_init;
			instr++;
		}
	}
	else
		best_result[NB_FIRST_INSTR] = 0;
	return (best_result);
}

int	refresh_best_combs(int *best_comb, int instr, int steps, \
	int	*instr_steps_itm)
{
	int	steps_max;

	steps_max = best_comb[NB_FIRST_INSTR] + best_comb[NB_SECOND_INSTR];
	if (instr_steps_itm[NB_FIRST_INSTR] + steps < steps_max)
	{
		best_comb[FIRST_INSTR] = instr;
		best_comb[NB_FIRST_INSTR] = steps;
		best_comb[SECOND_INSTR] = instr_steps_itm[FIRST_INSTR];
		best_comb[NB_SECOND_INSTR] = instr_steps_itm[NB_FIRST_INSTR];
	}
	free(instr_steps_itm);
	return (best_comb[NB_FIRST_INSTR] + best_comb[NB_SECOND_INSTR]); //initialement non NB_X mais X
}

void	refresh_in_dir(t_lnk *lst_a, t_lnk *lst_b, int instr, \
	int *best_comb)
{
	int		steps;
	int		steps_max;
	int		*instr_steps_item;

	steps = 0;
	steps_max = best_comb[NB_FIRST_INSTR] + best_comb[NB_SECOND_INSTR];
	while (++steps < steps_max)
	{
		if (is_rotate_instr(instr))
		{
			apply_instr(instr, &lst_a, &lst_b, QUIET);
			instr_steps_item = itm_insert(lst_a, lst_b);
			steps_max = refresh_best_combs(best_comb, instr, steps, \
				instr_steps_item);
		}
	}
}



void init_best_comb(int *best_comb, int *itm_insert_result, t_lnk *lst_a, t_lnk *lst_b) {
    if (!best_comb) {
        ft_errmsg("[init_best_comb] did not malloc");
        return;
    }

    itm_insert_result = itm_insert(lst_a, lst_b);
    if (!itm_insert_result) {
        ft_errmsg("[init_best_comb] itm_insert failed");
        return;
    }

    best_comb[NB_FIRST_INSTR] = 0;
    best_comb[FIRST_INSTR] = rr;
    best_comb[NB_SECOND_INSTR] = itm_insert_result[NB_FIRST_INSTR];
    best_comb[SECOND_INSTR] = itm_insert_result[FIRST_INSTR];
    free(itm_insert_result);
}

int *best_insert(t_lnk *lst_a, t_lnk *lst_b, int *best_comb) {
    int *itm_insert_result = NULL;
    int instr;

    init_best_comb(best_comb, itm_insert_result, lst_a, lst_b);

    for (instr = ROTATE_MIN; instr <= ROTATE_MAX; instr++) {
        if (is_rotate_instr(instr)) {
            refresh_in_dir(lst_a, lst_b, instr, best_comb);
        }
    }

    return best_comb;
}

int nb_instruction(int **b, int INSTR) {
    return ((*b)[INSTR]--);
}

void execute_best_comb(t_lnk **lst_a, t_lnk **lst_b, int *best_comb) {
    while (nb_instruction(&best_comb, NB_FIRST_INSTR)) {
        if (is_rotate_instr(best_comb[FIRST_INSTR])) {
            apply_instr(best_comb[FIRST_INSTR], lst_a, lst_b, PRINT);
        }
    }
    while (nb_instruction(&best_comb, NB_SECOND_INSTR)) {
        if (is_rotate_instr(best_comb[SECOND_INSTR])) {
            apply_instr(best_comb[SECOND_INSTR], lst_a, lst_b, PRINT);
        }
    }
}

void b_dump(t_lnk **lst_a, t_lnk **lst_b) {
    int best_comb[4];

    while (*lst_b)
	{
        if (!can_push_b(*lst_a, *lst_b)) {
            best_insert(*lst_a, *lst_b, best_comb);
            execute_best_comb(lst_a, lst_b, best_comb);
        }
        apply_instr(pa, lst_a, lst_b, 1);
    }
}
*/

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
