/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:47:42 by supersko          #+#    #+#             */
/*   Updated: 2025/01/30 20:04:34 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_lst_byrank(t_lnk *lst, char *header)
{
	t_lnk	*lnk_ind;

	printf("----------------------------------------------------------------\n");
	if (header)
		printf("%s\t", header);
	printf("\n");
	if (lst)
	{
		t_lst temp;
		
		temp.lst = lst;
		printf("%d\t", head(&temp));
		lnk_ind = lst->next;
		while (lnk_ind != lst)
		{
			temp.lst = lnk_ind;
			printf("%d\t", head(&temp));
			lnk_ind = lnk_ind->next;
		}
	}
	else
		printf("	[ empty list ]");
	printf("\n----------------------------------------------------------------");
}

void	print_lst(t_data *d)
{
	t_lnk	*a;
	t_lnk	*b;

	a = d->a.lst;
	b = d->b.lst;
	print_lst_byrank(b, "B");
	print_lst_byrank(a, "A");
	printf("\n###################################################################");
	printf("\n\n");
}

void print_instr_step(t_instr_step *instr_step)
{
	printf("instr: ");
	print_instr_from_int_heavy(instr_step->instr);
	printf(" x%i", instr_step->nb_instr);
}

void print_instr_ls(t_list *ls)
{
	t_instr_step *instr_step;

	if (ls)
	{
		while (ls)
		{
			instr_step = ls->content;
			print_instr_step(instr_step);
			printf(" -> ");
			ls = ls->next;
		}
	}
	printf(" NULL\n");
}