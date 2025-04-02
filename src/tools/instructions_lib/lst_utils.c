/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_load_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:41:34 by nidionis          #+#    #+#             */
/*   Updated: 2025/04/02 23:44:08 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lnk *list_deep_cpy(t_lnk *lst)
{
    t_lnk *tmp;
    t_lnk *ret;
    t_lnk *last;

    ret = NULL;
    if (!lst)
        return (NULL);
    lst = lst->prev;
    last = lst;
    while (!ret || lst != last)
    {
        tmp = malloc(sizeof(t_lnk));
        if (!tmp)
        {
            del_lst(&ret);
            return (NULL);
        }
        ft_memcpy(tmp, lst, sizeof(t_lnk));
        push_item(tmp, &ret);
        lst = lst->prev;
    }
    return (ret);
}

void reset_lst(t_data *d, t_lnk *back_up)
{
    del_lst(&d->a.lst);
    del_lst(&d->b.lst);
    d->a.lst = list_deep_cpy(back_up);
    d->b.lst = NULL;
}
