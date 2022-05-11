/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:47:42 by supersko          #+#    #+#             */
/*   Updated: 2022/05/11 21:43:09 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_lst(t_lnk **lst)
{
	t_lnk	*lnk_ind;

	ft_printf("%d\n", ((*lst)->items)->nb);
	lnk_ind = (*lst)->next;
	while (lnk_ind != *lst)
	{
		ft_printf("%d\t|\n", lnk_ind->items->nb);
		lnk_ind = lnk_ind->next;
	}
	ft_printf("	***************\n");
}