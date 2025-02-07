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
	printf("\n----------------------------------------------------------------");
}

void	print_lst(t_data *d)
{
	t_lnk	*a;
	t_lnk	*b;

	a = d->lst_a;
	b = d->lst_b;
	print_lst_byrank(b, "B");
	print_lst_byrank(a, "A");
	printf("\n###################################################################");
	printf("\n\n");
}