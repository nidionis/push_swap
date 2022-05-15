/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:47:42 by supersko          #+#    #+#             */
/*   Updated: 2022/05/15 22:29:05 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_lst(t_lnk *lst, char *header)
{
	t_lnk	*lnk_ind;

	if (header)
		ft_printf("%s\t", header);
	ft_printf("***************\n");
	if (lst)
	{
		ft_printf("-%d-\t", ((t_itm *)lst->itm)->nb);
		lnk_ind = lst->next;
		while (lnk_ind != lst)
		{
			ft_printf("-%d-\t", ((t_itm *)lnk_ind->itm)->nb);
			lnk_ind = lnk_ind->next;
		}
	}
	else
		ft_printf("	[ empty list ]");
	ft_printf("\n\t***************\n");
}

void	print_lst_byrank(t_lnk *lst, char *header)
{
	t_lnk	*lnk_ind;

	if (header)
		ft_printf("%s\t", header);
	ft_printf("***************\n");
	if (lst)
	{
		ft_printf("%d\t", ((t_itm *)lst->itm)->rank);
		lnk_ind = lst->next;
		while (lnk_ind != lst)
		{
			ft_printf("%d\t", ((t_itm *)lnk_ind->itm)->rank);
			lnk_ind = lnk_ind->next;
		}
	}
	else
		ft_printf("	[ empty list ]");
	ft_printf("\n\t***************\n");
}