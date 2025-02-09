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

//void	select_algo(int ind_max)
//{
//	if (ind_max == 1)
//		sort_2_nb(1);
//	else if (ind_max == 2)
//		sort_3_nb(2);
//	else if (ind_max == 3)
//		sort_4_nb(3);
//	else if (ind_max == 4)
//		sort_5_nb(4);
//	else
//	{
//		printf("Error\n");
//	}
//}

int break_when_minmax_loaded(t_data *d, int instr)
{
	(void)instr;
	if (d->max_b == d->rank_max || d->min_b == 0)
	{
		if (d->lst_a->rank == d->rank_max || d->lst_a->rank == 0)
			return (BREAK_BEST_COMB);
	}
	return (TRUE);
}

int ft_nb_instr(t_list *instr_step_node)
{
	int nb_instr;
	t_instr_step *instr_step;

	nb_instr = 0;
	while (instr_step_node)
	{
		instr_step = instr_step_node->content;
		nb_instr += instr_step->nb_instr;
		instr_step_node = instr_step_node->next;
	}
	return (nb_instr);	
}

int first_load_loop(t_data *data)
{
	t_list *insertion_step;
	int nb_instr;

	nb_instr = 0;
	if (can_load_b(data))
		apply_instr(data, pb, PRINT);
	else
	{
		insertion_step = ft_best_comb(data, data->r_instr, can_first_load, SIZE_MAX);
		if (!insertion_step)
			return (0);
		nb_instr = ft_nb_instr(insertion_step);
		if (apply_best_comb_and(break_when_minmax_loaded, data, insertion_step, PRINT) == BREAK_BEST_COMB)
			return (BREAK_BEST_COMB);
		ft_lstclear(&insertion_step, free);
	}
	return (nb_instr);
}

int firts_load(t_data *data)
{
	int nb_instr;
	int return_value;

	nb_instr = 0;
	while (TRUE)
	{
		return_value = first_load_loop(data);
		if (return_value == BREAK_BEST_COMB)
			break ;
		nb_instr += return_value;
	}
	return (nb_instr);
}

int	main(int argc, char **argv)
{
	t_data d;
	t_instr_map instr_map[12];
	int instr_ls[] = {ra, rb, rra, rrb, rr, rrr, LOOP_END};

	ft_bzero(&d, sizeof(t_data));
	if (argc < 2)
	{
		ft_errmsg(NULL);
		exit(0);
	}
	else
		d.lst_a = get_args(&d, argc, argv);
	d.rank_max = lst_init_ranks(&d.lst_a);
	d.lst_b = NULL;
	if (!ft_no_duplicate(d.lst_a))
		ft_errmsg("Error: duplicated items");
	init_data(&d, &d.lst_a, &d.lst_b);
	init_instr_map(instr_map);
	d.instr_map = instr_map;
	d.r_instr = instr_ls;
	firts_load(&d);
	//gather_min_and_max(&d);
	//first_dump(&d);
	del_lst(&d.lst_a);
	del_lst(&d.lst_b);
}
