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

int is_minmax_to_load_set(const t_data *data)
{
    if (!data->min_to_load && !data->max_to_load)
    {
        ft_errmsg("[is_minmax_to_load_set] min_to_load and max_to_load == 0\n");
        return (FALSE);
    }
    if (data->min_to_load == UNSET)
    {
        ft_errmsg("[is_minmax_to_load_set] min_to_load ==  UNSET\n");
        return (FALSE);
    }
    if (data->max_to_load == UNSET)
    {
        ft_errmsg("[is_minmax_to_load_set] max_to_load ==  UNSET\n");
        return (FALSE);
    }
    return (TRUE);
}

int is_low(const t_data *data, const int nb)
{
    int mediane;
    int min;
    int max;

    if (!is_minmax_to_load_set(data))
        ft_errmsg("[is_low] min_to_load and max_to_load should be set\n");
    min = data->min_to_load;
    max = data->max_to_load;
    mediane = (max - min) / 2 + min;
    //printf("[is_low] min: %i, max: %i, mediane: %i\n", min, max, mediane);
    if (nb <= mediane)
        return (TRUE);
   return (FALSE);
}

int is_high(const t_data *data, const int nb)
{
    if (!is_minmax_to_load_set(data))
        ft_errmsg("[is_high] min_to_load and max_to_load should be set\n");
    return (!is_low(data, nb));
}

/*
int is_to_load(const t_data *data, const int nb, const t_lnk *lst)
{
    int min;
    int max;
    t_lnk *other_lst;

    min = data->min_to_load;
    max = data->max_to_load;
    other_lst = data->lst_a;
    if (lst == other_lst)
        other_lst = data->lst_b;
    if (!min && !max)
    {
        min = get_softmin(other_lst)->rank + 1;
        max = get_softmax(other_lst)->rank - 1;
    }
    if (nb >= min || nb <= max)
        return (TRUE);
    return (FALSE);
}
*/

int is_set_for(int (*is_low_or_high)(const t_data *data, const int nb), t_data *data, const t_lnk *lst)
{
    if (data->max_to_load == UNSET)
        data->max_to_load = data->rank_max;
    if (data->min_to_load == UNSET)
        data->min_to_load = 0;
    if (!lst)
        return (TRUE);
    return (is_low_or_high(data, lst->rank));
}

int can_butterfly(t_data *data)
{
    t_lnk   *lst_b;
    t_lnk   *lst_a;
    int     nb;

    lst_b = data->lst_b;
    lst_a = data->lst_a;
    //if (!lst_b) || ft_dlstsize(lst_b) < 5)
    //    return (TRUE);
    if (!lst_b || ft_dlstsize(lst_b) < 2)
        return (can_load_b(data));
    if (!lst_a)
        return (FALSE);
    nb = lst_a->rank;
    //data->max_to_load = data->softmax_a;
    //data->min_to_load = data->softmin_a;
    //printf("[can_butterfly] is_set_for(is_low...) = %i\n", is_set_for(is_low, data, lst_b));
	//print_lst(data);
    if (lst_a->rank > data->max_b)
    {
        if (lst_b->rank == data->min_b)
            return (TRUE);
        else
            return (FALSE);
    }
    if (lst_a->rank < data->min_b)
    {
        if (lst_b->rank == data->min_b)
            return (TRUE);
        else
            return (FALSE);
    }
    if (is_set_for(is_low, data, lst_b))
        return (is_low(data, nb));
    else if (is_set_for(is_high, data, lst_b))
        return (is_high(data, nb));
    return (ERR_CAN_ACCEPT);
}

//int load_butterfly(t_data *data, int verbose)
//{
//    int nb_instr;
//    int was_set_on_lowest;
//
//    nb_instr = 0;
//    was_set_on_lowest = 1;
//    if (data->lst_b)
//        if (get_min(data->lst_b)->rank != data->lst_b->rank)
//            was_set_on_lowest = 0;
//    if (can_butterfly(data))
//		nb_instr = apply_instr(data, pb, verbose);
//    if (was_set_on_lowest)
//    {
//        //printf("[load_butterfly] was set on lowest\n");
//        if (should_swap_b(data->lst_b))
//            nb_instr = apply_instr(data, sb, verbose);
//        nb_instr = apply_instr(data, rb, verbose);
//    }
//    else //was set on highest
//    {
//        if (is_set_for(is_high, data, data->lst_b))
//        {
//            if (should_swap_b(data->lst_b))
//                nb_instr = apply_instr(data, sb, verbose);
//        }
//        else if (data->lst_b->prev->rank == data->min_b)
//        {
//            nb_instr = apply_instr(data, rrb, verbose);
//            //while (data->lst_a->rank < data->lst_b->rank)
//            //    nb_instr = apply_instr(data, pb, verbose);
//            nb_instr = apply_instr(data, sb, verbose);
//            nb_instr = apply_instr(data, rb, verbose);
//        }
//    }
//    return (nb_instr);
//}

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