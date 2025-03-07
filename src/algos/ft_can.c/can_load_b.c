/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:41:34 by nidionis          #+#    #+#             */
/*   Updated: 2025/02/03 00:10:14 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>


/**
 * @brief Vérifie si l'élément du haut de la pile A peut être chargé dans B (haute valeur)
 * 
 * @param data Structure contenant les données
 * @return int TRUE si l'élément peut être chargé, FALSE sinon
 */
int	can_load_high(t_data *data)
{
	t_lnk *a;

	a = data->lst_a;
	if (a->rank < data->mediane_a)
		return (FALSE);
	if (a->rank >= data->softmax_a)
		return (FALSE);
	return (can_load_b(data));
}

/**
 * @brief Vérifie si l'élément est soit plus grand que le max, soit plus petit que le min de B
 */
int	can_insert_at_extremes(t_data *data)
{
	t_lnk *a;

	a = data->lst_a;
	return (a->rank > data->max_b || a->rank < data->min_b);
}

/**
 * @brief Vérifie si la pile B a ses valeurs extremes au sommet et en-dessous
 * (max au sommet avec min en-dessous, ou min au sommet avec max en-dessous)
 */
int	is_extreme_b(t_data *data)
{
	t_lnk *b;

	b = data->lst_b;
	if (!b || ft_dlstsize(b) < 2)
		return (FALSE);
	return ((b->rank == data->max_b && b->prev->rank == data->min_b) || 
		(b->rank == data->min_b && b->prev->rank == data->max_b));
}

/**
 * @brief Vérifie si l'élément a une valeur entre le haut et le bas de B
 */
int	can_insert_to_b_between(t_data *data)
{
	t_lnk *a;
	t_lnk *b;

	a = data->lst_a;
	b = data->lst_b;
	return (a->rank > b->rank && a->rank < b->prev->rank);
}



/**
 * @brief Vérifie si l'élément du haut de la pile A peut être inséré dans B
 * tout en maintenant B triée en ordre inverse
 * 
 * @param data Structure contenant les données
 * @return int TRUE si l'insertion est possible, FALSE sinon
 */
int	can_load_b(t_data *data)
{
	t_lnk *a;
	t_lnk *b;
	int size_b;

	a = data->lst_a;
	b = data->lst_b;
	if (!a)
		return (FALSE);
	if (!b)
		return (TRUE);
	size_b = ft_dlstsize(b);
	if (size_b == 1)
		return (TRUE);
	// Si B a ses extremes au sommet et en-dessous, vérifions si A peut être inséré
	if (is_extreme_b(data))
		return (can_insert_at_extremes(data));
	// Cas où l'élément serait un nouveau min ou max de B
	if (can_insert_at_extremes(data))
		return (TRUE);
	// Cas où l'élément s'insèrerait entre deux éléments de B
	if (can_insert_to_b_between(data))
		return (TRUE);
	return (FALSE);
}

int	can_dump_b(t_data *data)
{
    t_lnk *a;
    t_lnk *b;

    a = data->lst_a;
    b = data->lst_b;
	if (!a)
		return (TRUE);
	if (!b)
		return (FALSE);
	if (a->rank == data->softmax_a && b->rank == data->softmax_a - 1)
		return (TRUE);
	if (a->prev->rank == data->softmin_a && b->rank == data->softmin_a + 1)
		return (TRUE);
	return (FALSE);
}