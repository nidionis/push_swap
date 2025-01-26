/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing_fts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 21:16:34 by supersko          #+#    #+#             */
/*   Updated: 2025/01/26 19:06:13 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	push(t_lnk **from_lst, t_lnk **to_lst)
{
	push_item(pop_item(from_lst), to_lst);
}

void	push_item(t_lnk *lnk, t_lnk **lst)
{
	if (lnk)
	{
		if (*lst == NULL)
			*lst = lnk_init(lnk);
		else
		{
			lnk->next = *lst;
			lnk->prev = (*lst)->prev;
			((*lst)->prev)->next = lnk;
			(*lst)->prev = lnk;
			(*lst) = lnk;
		}
	}
	if (!lnk)
		ft_printf("[push item] pushing non existing link\n");
}

t_lnk	*pop_item(t_lnk **lst)
{
	t_lnk	*poped_item;

	poped_item = *lst;
	if (*lst == NULL)
		return (NULL);
	else if ((*lst)->next == *lst)
		*lst = NULL;
	else
	{
		(poped_item->prev)->next = poped_item->next;
		(poped_item->next)->prev = poped_item->prev;
		*lst = (*lst)->next;
	}
	return (lnk_init(poped_item));
}
