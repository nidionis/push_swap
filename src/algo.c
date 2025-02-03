/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/02/03 01:39:29 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>


//int	apply_best_comb_and(int (*f_do)(t_data *d, int instr), t_data *data,
//		int *best_comb)
//{
//	if (best_comb[FIRST_INSTR] == CANT_INSERT)
//		return (CANT_INSERT);
//	while (best_comb[NB_FIRST_INSTR]--)
//	{
//		if (f_do(data, best_comb[FIRST_INSTR]) == BREAK_BEST_COMB)
//			return (BREAK_BEST_COMB);
//		apply_instr(data, &data->lst_a, &data->lst_b, best_comb[FIRST_INSTR],
//			PRINT);
//		if (f_do(data, best_comb[FIRST_INSTR]) == BREAK_BEST_COMB)
//			return (BREAK_BEST_COMB);
//	}
//	if (best_comb[SECOND_INSTR] != NO_INSTR && best_comb[NB_SECOND_INSTR] != CANT_INSERT)
//	{
//		while (best_comb[NB_SECOND_INSTR]--)
//		{
//			if (f_do(data, best_comb[FIRST_INSTR]) == BREAK_BEST_COMB)
//				return (BREAK_BEST_COMB);
//			apply_instr(data, &data->lst_a, &data->lst_b,
//				best_comb[SECOND_INSTR], PRINT);
//			if (f_do(data, best_comb[FIRST_INSTR]) == BREAK_BEST_COMB)
//				return (BREAK_BEST_COMB);
//		}
//	}
//	free(best_comb);
//	return (TRUE);
//}


//int	*insert_target_to_list_steps(t_data *data, int lst_instr[],
//		int (*can_push)(t_data *data, t_lnk *lst_a, t_lnk *lst_b), int cost)
//{
//	t_data d;
//	int		i_instr;
//	int		instr_steps_itm[2];
//	int		instr;
//
//	ft_memcpy(&d, data, sizeof(t_data));
//	i_instr = 0;
//	d.best_cost_comb = cost;
//	// d.best_cost_instr = cost;
//	instr = lst_instr[0];
//	set_instr_step_itm(instr, 0, instr_steps_itm);
//	if (can_push(&d, d.lst_a, d.lst_b))
//	{
//		update_best_instr(&d, instr_steps_itm);
//		return (malloc_instr_steps_itm(&d));
//	}
//	while (instr != LOOP_END)
//	{
//		set_instr_step_itm(instr, INT_MAX, instr_steps_itm);
//		instr_steps_itm[NB_INSTR] = count_instr(&d, d.lst_a, d.lst_b, instr,
//				can_push);
//		update_best_instr(&d, instr_steps_itm);
//		d.best_cost_comb = ft_cost(d.best_comb);
//		instr = lst_instr[++i_instr];
//	}
//	return (malloc_instr_steps_itm(&d));
//}

//int	*best_insert(t_lnk *lst_a, t_lnk *lst_b, int lst_instr[],
//		int (*can_push)(t_data *data, t_lnk *lst_a, t_lnk *lst_b))
//{
//	t_data d;
//	int i_instr;
//	int first_instr_steps[2];
//
//	set_data(&d, &lst_a, &lst_b);
//	set_best_comb(d.best_comb);
//	i_instr = 0;
//	while (lst_instr[i_instr] != LOOP_END)
//	{
//		int *second_instr_steps;
//		t_lnk *lst_a_original = lst_a;
//		t_lnk *lst_b_original = lst_b;
//		set_instr_step_itm(lst_instr[i_instr], 0, first_instr_steps);
//		if (can_push(&d, lst_a, lst_b))
//		{
//			return (malloc_instr_steps_itm(NULL));
//		}
//		int j_instr = 0;
//		while (lst_instr[j_instr] != LOOP_END
//			&& first_instr_steps[NB_INSTR]++ < ft_cost(d.best_comb))
//		{
//			apply_instr(&d, &lst_a, &lst_b, lst_instr[i_instr], QUIET);
//			second_instr_steps = insert_target_to_list_steps(lst_a, lst_b,
//					lst_instr, can_push, ft_cost(d.best_comb));
//			update_best_comb(&d.best_comb, first_instr_steps,
//				second_instr_steps);
//			d.best_cost_comb = ft_cost(d.best_comb);
//			free(second_instr_steps);
//			if (can_push(&d, lst_a, lst_b))
//				break ;
//			j_instr++;
//		}
//		lst_a = lst_a_original;
//		lst_b = lst_b_original;
//		i_instr++;
//	}
//	return (malloc_best_insert(&d));
//}