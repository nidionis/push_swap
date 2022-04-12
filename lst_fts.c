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

t_lnk	*pop(t_lst	*lst)
{
	t_lnk	*poped;

	if (lst->size == 0)
		poped = NULL;
	else if (lst->size == 1)
	{
		poped = lst->first;
                lst_init(lst);
	}
	else
	{
		poped = lst->first;
		(lst->last)->next = poped->next;
		(poped->next)->prev = lst->last;
		(lst->first) = poped->next;
                (lst->size)--;
	}
	return (lnk_init(poped));
}

t_lnk	*push_item(t_lnk *lnk, t_lst *lst)
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

void    swap_lst(t_lst *lst)
{
        t_lnk   *old_first;
        t_lnk   *new_first;

        new_first = (lst->first)->next;
        old_first = lst->first;
        (new_first->next)->prev = old_first;
        (lst->last)->next = new_first;
        old_first->next = new_first->next;
        old_first->prev = new_first;
        new_first->next = lst->first;
        new_first->prev = lst->last;
        lst->first = new_first;
}


void    rev_lst(t_lst *lst)
{
    t_lnk   *lnk;
    t_lnk   *tmp;
    size_t     looped;

    lnk = lst->first;
    looped = 0;
    if (lst->size)
    {
        while (looped++ < lst->size)
        {
                tmp = lnk->next;
                lnk->next = lnk->prev;
                lnk->prev = tmp;
                lnk = lnk->next;
        }
        tmp = lst->first;
        lst->first = lst->last;
        lst->last = tmp;
    }
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

/*
int main(int argc, char *argv[])
{
	int ii = 0;
	int *tab = get_args(&argv[1], argc - 1);
        t_lnk   *lnk;
	t_lst *lst = new_lst();

	while (ii < argc - 1)
		push_item(new_lnk(tab[ii++], 0, 0), lst);
	print_lst(lst);
        printf("lst size:%d\n", (lst)->size);
        rev_lst(lst);
	print_lst(lst);
        del_list(lst);
}
*/
