/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_fts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:38:32 by supersko          #+#    #+#             */
/*   Updated: 2022/04/09 22:03:05 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lnk	*new_lnk(int nb, int ind, int rank)
{
	t_lnk	*returned_lnk;

	returned_lnk = malloc(sizeof(t_lnk));
	if (!nb)
		returned_lnk = NULL;
	else
	{
		returned_lnk->nb = nb;
		returned_lnk->ind = ind;
		returned_lnk->rank = rank;
		returned_lnk->next = NULL;
		returned_lnk->prev = NULL;
	}
	return (returned_lnk);
}

t_lnk	*addr_null(t_lnk *lnk)
{
	lnk->next = NULL;
	lnk->prev = NULL;
	return (lnk);
}

size_t	lnk_cnt(t_lnk **lst)
{
	size_t	cnt;
	t_lnk	*lnk_init;

	cnt = 0;
	lnk_init = *lst;
	while (*lst != NULL || *lst != lnk_init)
	{
		*lst = (*lst)->next;
		cnt++;
	}
	*lst = lnk_init;
	return (cnt);
}

t_lnk	*pop(t_lnk	**lst)
{
	t_lnk	*poped;

	if (*lst == NULL)
		poped = NULL;
	else if (*lst == (*lst)->next)
	{
		poped = *lst;
		*lst = NULL;
	}
	else
	{
		poped = *lst;
		(poped->prev)->next = poped->next;
		(poped->next)->prev = poped->prev;
		*lst = poped->next;
	}
	return (addr_null(poped));
}

t_lnk	*push(t_lnk	*lnk, t_lnk **lst)
{
	if (*lst == 0)
	{
		*lst = lnk;
	}
	else
	{
		lnk->next = *lst;
		if ((*lst)->next == NULL)
			(*lst)->next = lnk;
		if ((*lst)->prev == NULL)
			(*lst)->prev = lnk;
		else
			lnk->prev = (*lst)->prev;
		((*lst)->prev)->next = lnk;
		((*lst)->prev)->next = lnk;
		(*lst)->prev = lnk;
		*lst = lnk;
	}
	return (*lst);
}

t_lnk	**reverse_lst(t_lnk **lst)
{
	return (lst);
}

#include <stdio.h>
void print_lst(t_lnk **lst)
{
	t_lnk *lnk_init;
	int looped;

	lnk_init = *lst;
	looped = 0;
	while (!looped++ && *lst != NULL && *lst != lnk_init)
	{
		printf("%d\n", (*lst)->nb);
		*lst = (*lst)->next;
	}
	*lst = lnk_init;
}

int main(int argc, char *argv[])
{
	int ii = 0;
	int *tab = get_args(&argv[1], argc - 1);
	t_lnk *lnk_init;
	t_lnk **liste_chainee = &lnk_init;

	while (ii < argc - 1)
	{
		push(new_lnk(tab[ii++], 0, 0), liste_chainee);
	}
	print_lst(liste_chainee);
}
