/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/02/09 16:30:59 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int should_swap_b_unsafe(t_lnk *lst)
{
    t_lst temp;
    
    temp.lst = lst;
    return (head(&temp) < next(&temp) && head(&temp) != get_max(lst)->rank);
}

int should_swap_b(t_lnk *lst, int mediane)
{
    int nb;
    int n;
    (void)mediane;

    t_lst temp;
    
    temp.lst = lst;
    nb = head(&temp);
    n = next(&temp);
    if (!lst || ft_dlstsize(lst) == 1)
        return (FALSE);
    //if (nb < mediane && n > mediane)
    //    return (FALSE);
    if (nb > n)
        if (nb != get_max(lst)->rank || n != get_min(lst)->rank)
        return (TRUE);
    return (FALSE);
}

//int should_swap_b_(t_data *data, int instr)
//{
//    (void)instr;
//    return (should_swap_b(data->lst_b));
//}