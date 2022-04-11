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
	t_lnk	*lnk;

	lnk = malloc(sizeof(t_lnk));
	if (!lnk)
                error_msg("Error creating a new link\n");
	else
	{
		lnk->nb = nb;
		lnk->ind = ind;
		lnk->rank = rank;
		lnk_init(lnk);
	}
	return (lnk);
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

void   lst_init(t_lst *lst)
{
    lst->first = NULL;
    lst->last = NULL;
    lst->size = 0;
}

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

void    reverse(t_lst *lst)
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

void    push(t_lst *lst_a, t_lst *lst_b, char action)
{
    t_lnk   *tmp;

    if (action == 'a' || 'A')
        push_item(pop(lst_a), lst_b);
    else if (action == 'b' || 'B')
        push_item(pop(lst_b), lst_a);
    else if (action == 's' || 'S')
    {
        tmp = pop(lst_b);
        push_item(pop(lst_a), lst_b);
        push_item(tmp, lst_a);
    }
    else
        error_msg("error in push function\n");
    if (action > 96) // si action est minuscule, imprimer 
    {
        write(1, "s", 1);
        write(1, &action, 1);
        write(1, "\n", 1);
    }
}

void    *del_list(t_lst *lst)
{
    t_lnk   *lnk;
    while (lst->size > 0)
    {
    	lnk = pop(lst);
        free(lnk);
    }
    free(lst);
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
        t_lnk   *lnk;
	t_lst *lst = new_lst();

	while (ii < argc - 1)
		push_item(new_lnk(tab[ii++], 0, 0), lst);
	print_lst(lst);
        printf("lst size:%d\n", (lst)->size);
        reverse(lst);
	print_lst(lst);
}
