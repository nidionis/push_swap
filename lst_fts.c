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

t_lnk	*lnk_init(t_lnk *lnk)
{
	lnk->next = lnk;
	lnk->prev = lnk;
	return (lnk);
}

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
		lnk_init(returned_lnk);
	}
	return (returned_lnk);
}

t_lst   *new_lst(void)
{
    t_lst   *lst;

    lst = malloc(sizeof(t_lst));
    lst->first = NULL;
    lst->last = NULL;
    lst->size = 0;
    return (lst);
}

size_t	lnk_cnt(t_lst lst)
{
	size_t	cnt;

	cnt = 0;
        if (lst.size)
            while (lst.first != lst.last)
	{
		lst.first = (lst.first)->next;
		cnt++;
	}
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
	return (lnk_init(poped));


}

t_lnk	*push(t_lnk	*lnk, t_lst *lst)
{
	if (lst->size == 0)
	{
		lst->first = lnk;
		lst->last = lnk;
	}
	else
	{
		lnk->next = lst->first;
		lnk->prev = lst->last;
		((lst->first)->prev)->next = lnk;
		(lst->first)->prev = lnk;
		lst->first = lnk;
	}
    (lst->size)++;
	return (lnk);
}

t_lnk	**reverse_lst(t_lnk **lst)
{
	return (lst);
}

#include <stdio.h>
void print_lst(t_lst *lst)
{
	int looped;
        t_lnk   *lnk;

    lnk = lst->first;
    looped = 0;
    //printf("first : %d\n", (lst->first)->nb);
    //printf("last : %d\n", (lst->last)->nb);
    if (lst->size)
    {
        while (!(looped++) || lnk != lst->first)
	{
		printf("%d\n", lnk->nb);
		lnk = lnk->next;
	}
    }
}



int main(int argc, char *argv[])
{
	int ii = 0;
	int *tab = get_args(&argv[1], argc - 1);
	t_lst *lst = new_lst();

	while (ii < argc - 1)
	{
		push(new_lnk(tab[ii++], 0, 0), lst);
	}
	print_lst(lst);
}
