/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/19 00:14:04 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_lnk	*find_highest_tower(t_lnk *ind_lnk, int inst_way, t_lnk *relMinMax[2])
{
	int		last_highest;
	int		ind_relMinMax;
	t_lnk	*highest_tower;

	last_highest = ind_lnk->rank;
	ind_relMinMax = 0;
	highest_tower = ind_lnk;
	if (inst_way == ra)
		ind_relMinMax = 1;
	while (ind_lnk->rank < relMinMax[ind_relMinMax]->rank)
	{
		if (ind_lnk->rank > last_highest)
		{
			highest_tower = ind_lnk;
			last_highest = ind_lnk->rank;
		}
		if (inst_way == ra)
			ind_lnk = ind_lnk->next;
		else
			ind_lnk = ind_lnk->prev;
	}
	return (highest_tower);
}

t_lnk **recentrer(t_lnk **lst_a, t_lnk **relMinMax)
{
	if (!ft_is_sorted(*lst_a))
	{
		relMinMax[0] = refresh_RelMin(relMinMax[0]);
		relMinMax[1] = refresh_RelMax(relMinMax[1]);
		if ((*lst_a)->rank <= relMinMax[0]->rank)
		{
			while ((*lst_a)->rank <= relMinMax[0]->rank)
				apply_instr(ra, lst_a, NULL, 1);
		}
		else if ((*lst_a)->rank >= relMinMax[1]->rank)
			while ((*lst_a)->rank <= relMinMax[1]->rank)
				apply_instr(rra, lst_a, NULL, 1);
	}
	return (relMinMax);
}

int main(int argc, char **argv)
{
	t_lnk	*lst_a = NULL;
	t_lnk	*lst_initial = NULL;
	t_lnk	*lst_b = NULL;
	t_lnk	**relMinMax;
	int		ind_max;

	if (argc < 2)
		error_msg(NULL);
	else if (argc == 2)
		lst_a = get_args_allinone(argv[1]);
	else
		lst_a = get_args(argc, argv);
	ind_max = lst_init_ranks(&lst_a);
	//set_initial_pointers(&lst_a);
	if (!ft_no_duplicate(lst_a))
		error_msg("Error: duplicated items");
	lst_initial = lst_a;
	relMinMax = (t_lnk **)malloc(sizeof(t_lnk *) * 2);
	first_parse(&lst_a, &lst_b, ind_max, relMinMax);
	relMinMax[1] = get_RelMax(lst_a, ind_max);
	relMinMax[0] = get_RelMin(lst_a);
	relMinMax = recentrer(&lst_a, relMinMax);
		t_lnk	*taquet;
	while (lst_b || relMinMax[0]->rank < relMinMax[1]->rank)
	{
		print_lst_byrank(lst_a, " A");
		print_lst_byrank(lst_b, " B");
		taquet = find_highest_tower(lst_a, rra, relMinMax);
		reach_push(&lst_a, &lst_b, taquet->rank, rra, relMinMax);
		if (lst_a->rank < relMinMax[1]->rank && lst_a->rank > relMinMax[0]->rank)
			apply_instr(pb, &lst_a, &lst_b, 1);
		reach_push(&lst_a, &lst_b, relMinMax[1]->rank, ra, relMinMax);
		dump_relMax(&lst_a, &lst_b);
		relMinMax = recentrer(&lst_a, relMinMax);
	}
	reach_rank(&lst_a, 0, get_shortestway(0, lst_a));
		print_lst_byrank(lst_a, " A");
		print_lst_byrank(lst_b, " B");
	//refresh_RelMin(relMin);
	//reach_push(&lst_a, &lst_b, relMax->prev->rank, ra);
	//dump_relMax(&lst_a, &lst_b);
	//print_lst_byrank(lst_a, "A");
	//print_lst_byrank(lst_b, "B");
	del_lst(&lst_a);
	del_lst(&lst_b);
	free(relMinMax);
}