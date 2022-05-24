/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/24 15:25:05 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
//
//t_lnk	*find_highest_tower(t_lnk *ind_lnk, int inst_way, t_lnk *relMinMax[2])
//{
//	int		last_highest;
//	int		ind_relMinMax;
//	t_lnk	*highest_tower;
//
//	last_highest = ind_lnk->rank;
//	ind_relMinMax = 0;
//	highest_tower = ind_lnk;
//	if (inst_way == ra)
//	{
//		ind_relMinMax = 1;
//	}
//	while (ind_lnk != relMinMax[ind_relMinMax])
//	{
//		if (ind_lnk->rank > last_highest)
//		{
//			highest_tower = ind_lnk;
//			last_highest = ind_lnk->rank;
//		}
//		if (inst_way == ra)
//			ind_lnk = ind_lnk->next;
//		else
//			ind_lnk = ind_lnk->prev;
//	}
//	return (highest_tower);
//}
//
//// recentre la liste sur relMax (en prevision de push)
//// ou sur relMin->next
//t_lnk	**recentrer(t_lnk **lst_a, t_lnk **relMinMax)
//{
//	relMinMax[0] = refresh_RelMin(relMinMax[0]);
//	relMinMax[1] = refresh_RelMax(relMinMax[1]);
//	if (relMinMax[0]->rank < relMinMax[1]->rank)
//	{
//		if ((*lst_a)->rank < relMinMax[0]->rank)
//		{
//			while ((*lst_a)->rank < relMinMax[0]->rank && relMinMax[0]->next != relMinMax[1])
//				apply_instr(ra, lst_a, NULL, 1);
//		}
//		else if ((*lst_a)->rank >= relMinMax[1]->rank)
//		{
//			while ((*lst_a)->rank >= relMinMax[1]->rank)
//				apply_instr(rra, lst_a, NULL, 1);
//		}
//	}
//	return (relMinMax);
//}

int main(int argc, char **argv)
{
	t_lnk	*lst_a = NULL;
	t_lnk	*lst_b = NULL;
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
	if (ind_max == 1)
		sort_2_nb(&lst_a);
	else if (ind_max == 2)
		sort_3_nb(&lst_a, ind_max);	
	else if (ind_max == 3)
		sort_4_nb(&lst_a, &lst_b);	
	else if (ind_max == 4)
		sort_5_nb(&lst_a, &lst_b);	
	else
	{
		new_load_b(&lst_a, &lst_b, ind_max);
		b_dump(&lst_a, &lst_b);
		reach_rank(&lst_a, 0, get_shortestway(0, lst_a));
	}
	//print_lst(lst_a, "a");
	//print_lst(lst_b, "b");
	del_lst(&lst_a);
	del_lst(&lst_b);
}