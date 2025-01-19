/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:47:42 by supersko          #+#    #+#             */
/*   Updated: 2025/01/19 00:15:30 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_lst(t_lnk *lst, char *header)
{
	t_lnk	*lnk_ind;

	if (header)
		printf("%s\t", header);
	printf("***************\n");
	if (lst)
	{
		printf("%d\t", lst->nb);
		lnk_ind = lst->next;
		while (lnk_ind != lst)
		{
			printf("%d\t", lnk_ind->nb);
			lnk_ind = lnk_ind->next;
		}
	}
	else
		printf("	[ empty list ]");
	printf("\n\t***************\n");
}

void	print_lst_byrank(t_lnk *lst, char *header)
{
	t_lnk	*lnk_ind;

	if (header)
		printf("%s\t", header);
	printf("***************\n");
	if (lst)
	{
		printf("%d\t", lst->rank);
		lnk_ind = lst->next;
		while (lnk_ind != lst)
		{
			printf("%d\t", lnk_ind->rank);
			lnk_ind = lnk_ind->next;
		}
	}
	else
		printf("	[ empty list ]");
	printf("\n\t***************\n");
}
