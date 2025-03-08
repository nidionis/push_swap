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

int dec_is_set_for(int (*is_low_or_high)(const t_data *data, const int nb), t_data *data, const t_lnk *lst)
{
    if (data->max_to_load == UNSET)
        data->max_to_load = data->rank_max;
    if (data->min_to_load == UNSET)
        data->min_to_load = 0;
    if (!lst)
        return (TRUE);
    return (is_low_or_high(data, lst->rank));
}

int inc_is_set_for(int (*is_low_or_high)(const t_data *data, const int nb), t_data *data, const t_lnk *lst)
{
    if (data->max_to_load == UNSET)
        data->max_to_load = data->rank_max;
    if (data->min_to_load == UNSET)
        data->min_to_load = 0;
    if (!lst)
        return (TRUE);
    return (is_low_or_high(data, lst->rank));
}

/**
 * @brief Détermine si un élément peut être poussé dans la pile B selon la stratégie d'insertion optimisée
 * 
 * Cette fonction vérifie si l'élément au sommet de la pile A peut être inséré dans la pile B
 * en respectant un certain ordre optimisé.
 * 
 * @param data Structure de données contenant les piles
 * @return int TRUE si l'élément peut être poussé, FALSE sinon
 */
int can_push_b_optimized(t_data *data)
{
    t_lnk   *lst_b;
    t_lnk   *lst_a;
    int     nb;

    lst_b = data->lst_b;
    lst_a = data->lst_a;
    
    if (!lst_b || ft_dlstsize(lst_b) < 2)
        return (can_push_b(data));
    if (!lst_a)
        return (FALSE);
        
    nb = lst_a->rank;
    
    /* Gérer les cas spéciaux: quand l'élément est supérieur au maximum dans B */
    if (lst_a->rank > data->max_b)
    {
        /* Accepter seulement si B est positionné sur son minimum */
        return (lst_b->rank == data->min_b);
    }
    
    /* Gérer les cas spéciaux: quand l'élément est inférieur au minimum dans B */
    if (lst_a->rank < data->min_b)
    {
        /* Accepter seulement si B est positionné sur son minimum */
        return (lst_b->rank == data->min_b);
    }
    
    /* Utiliser la stratégie de partitionnement pour décider */
    if (inc_is_set_for(is_low, data, lst_b))
        return (is_low(data, nb));
    else if (inc_is_set_for(is_high, data, lst_b))
        return (is_high(data, nb));
        
    return (ERR_CAN_ACCEPT);
}