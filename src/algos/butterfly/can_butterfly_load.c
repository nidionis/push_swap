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

#include <push_swap.h>

/*
    la comparaison absolue ( '<' au lieu de '<=' )
    compense le fait que la mediane n'est pas
    forcement "rank_max / 2" comme definit par mes fonction
    d'initialisation (ou d'update) du push swap
*/
int is_low(const t_data *data, const int nb, const t_lnk *lst)
{
    int mediane;

    mediane = data->mediane_b;
    if (lst == data->lst_a)
        mediane = data->mediane_a;
    if (!(nb < mediane))
        return (TRUE);
   return (FALSE);
}

int is_high(const t_data *data, const int nb, const t_lnk *lst)
{
    int mediane;

    mediane = data->mediane_b;
    if (lst == data->lst_a)
        mediane = data->mediane_a;
    if (nb >= mediane)
        return (TRUE);
   return (FALSE);
}

int set_for(int (*is_low_or_high)(const t_data *data, const int nb, const t_lnk *lst), const t_data *data, const t_lnk *lst)
{
    if (is_low_or_high == is_low)
        return (is_low(data, lst->rank, lst));
    if (is_low_or_high == is_high)
        return (is_high(data, lst->rank, lst));
    ft_errmsg("[set_for] the function passed sucks\n");
    return (ERR_IS_LOW_OR_HIGH);
}

int can_butterfly(const t_data *data)
{
    t_lnk   *lst_b;
    int     nb;

    lst_b = data->lst_b;
    if (!lst_b || ft_dlstsize(lst_b) < 5)
        return (TRUE);
    nb = lst_b->rank;
    if (set_for(is_low, data, lst_b))
        return (is_low(data, nb, lst_b));
    else if (set_for(is_high, data, lst_b))
        return (is_high(data, nb, lst_b));
    return (ERR_CAN_ACCEPT);
}

/*
    the vars min_to_load, max_to_load should be set
*/
//int	can_butterfly_load(t_data *data)
//{
//    int mediane;
//    t_lnk *a;
//    t_lnk *b;
//
//    a = data->lst_a;
//    b = data->lst_b;
//    if (!data->min_to_load && !data->max_to_load)
//    {
//        data->min_to_load = data->softmin_a;
//        data->max_to_load = data->softmax_a;
//    }
//	if (a->rank <= data->min_to_load || a->rank >= data->max_to_load)
//		return (FALSE);
//    if (ft_dlstsize(b) < 5)
//        return (can_load_b(data));
//    mediane = (data->max_to_load - data->min_to_load) / 2 + data->min_to_load;
//    return (can_butterfly(data, a->rank, a));
//}