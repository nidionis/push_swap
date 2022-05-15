/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lsts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:47:42 by supersko          #+#    #+#             */
/*   Updated: 2022/05/15 22:29:05 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	print_lst(t_lst *lst_a, t_lst *lst_b)
{
	size_t	loop_nb;
	size_t	ii;
	t_lnk	*lnk_a;
	t_lnk	*lnk_b;

	lnk_a = lst_a->first;
	lnk_b = NULL;
	if (lst_b)
		lnk_b = lst_b->first;
	loop_nb = lst_a->size;
	if (lst_b && lst_a->size < lst_b->size)
		loop_nb = lst_b->size;
	if (lst_a)
		printf("[lst_a]: size=%d,	min_val=%d, 	maw_val=%d\n", lst_a->size, lst_a->min_val, lst_a->max_val);
	if (lst_b)
		printf("[lst_b]: size=%d,	min_val=%d, 	maw_val=%d\n", lst_b->size, lst_b->min_val, lst_b->max_val);
	ii = 0;
	while (ii < loop_nb)
	{
		if (!lst_b)
			printf("%10d\t|\n", lnk_a->nb);
		else
		{
			if (ii < lst_a->size && ii < lst_b->size)
				printf("%8d\t|%8d\n", lnk_a->nb, lnk_b->nb);
			else if (ii < lst_a->size)
				printf("%8d\t|\n", lnk_a->nb);
			else if (ii < lst_b->size)
				printf("\t\t|%8d\n", lnk_b->nb);
		}
		if (lnk_a)
				lnk_a = lnk_a->next;
		if (lnk_b)
				lnk_b = lnk_b->next;
		ii++;
	}
	printf("	***************\n");
}
