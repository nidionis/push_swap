/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/04/03 21:05:39 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int is_sorted_a_n_nexts(t_lst x, int n_nexts)
{
    int i;
    t_lnk *first;

    i = 0;
    first = x.lst;
    while (i < n_nexts)
    {
        if (head(&x) == x.max)
        {
            if (next(&x) != x.min)
                return (FALSE);
        }
        else if (head(&x) > next(&x))
            return (FALSE);
        rotate_a(&x.lst, NULL);
        i++;
    }
    return (TRUE);
}

int sort_3_nb(t_data *d)
{
    int nb_instr;

    nb_instr = 0;
    if (!is_sorted_a_n_nexts(d->a, 3))
        nb_instr = apply_instr(d, sa, PRINT);
    reach_rank_a(d, 0, PRINT);
    return (nb_instr);
}
