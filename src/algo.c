
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/24 19:36:41 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int is_next_sorted_lst_a(t_lnk *lst)
{
    return (lst->rank + 1 == lst->next->rank);
}

void if_next_softmin_in_b_insert_it(t_lnk **lst_a, t_lnk **lst_b)
{
    t_lnk	*ind;

    ind = *lst_a;
    if (!is_next_sorted_lst_a(ind))
        if (is_in_lst(*lst_b, ind->rank + 1))
            insert_target_in_a(&ind, lst_b, ind->rank + 1);
                while (is_in_lst(*lst_b, ind->rank + 1))
                    insert_target_in_a(&ind, lst_b, ind->rank + 1);
}

void swap_b_if_needed(t_lnk **lst_b)
{
    if ((*lst_b)->rank > (*lst_b)->next->rank && !is_a_softminmax_b((*lst_b)))
        apply_instr(sb, lst_b, lst_b, PRINT);
}

void    if_not_sorted_push_in_b(t_lnk **lst_a, t_lnk **lst_b)
{
    if (!*lst_b)
        apply_instr(pb, lst_a, lst_b, PRINT);
    else
    {
        swap_b_if_needed(lst_b);
        if (!is_a_softminmax_a(*lst_a))
            insert_target_in_b(lst_a, lst_b, (*lst_a)->rank);
        while ((*lst_a)->rank <= get_softmin_in_a(*lst_a))
            apply_instr(ra, lst_a, lst_b, PRINT);
    }

}


int is_a_softminmax_b(t_lnk *lst)
{
    return (lst->rank <= get_softmin_in_b(lst) || lst->rank >= get_softmax_in_b(lst));
}


int is_a_softminmax_a(t_lnk *lst)
{
    return (lst->rank <= get_softmin_in_a(lst) || lst->rank >= get_softmax_in_a(lst));
}

void sort_from_min_to_max(t_lnk **lst_a, t_lnk **lst_b)
{
//    t_lnk	*ind;
    int softmax;

//    ind = *lst_a;
    softmax = get_softmax_in_a(*lst_a);
    if (softmax)
    {
        if_next_softmin_in_b_insert_it(lst_a, lst_b);
        print_lst(*lst_a, "lst_a");
        print_lst(*lst_b, "lst_b");
        apply_instr(ra, lst_a, lst_b, PRINT);
        while (!is_a_softminmax_a(*lst_a))
            if_not_sorted_push_in_b(lst_a, lst_b);
        while (is_a_softminmax_a(*lst_a) && !is_sorted_a(*lst_a))
            apply_instr(ra, lst_a, lst_b, PRINT);
        if (!is_sorted_a(*lst_a))
            sort_from_min_to_max(lst_a, lst_b);
    }
//    b_dump(lst_a, lst_b);
}