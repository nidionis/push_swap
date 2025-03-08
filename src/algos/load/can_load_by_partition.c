/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_load_by_partition.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 23:20:00 by nidionis          #+#    #+#             */
/*   Updated: 2025/03/07 23:20:00 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/**
 * @brief Version originale de can_first_load gardée pour compatibilité
 * Vérifie si l'élément peut être chargé dans B avec la logique initiale
 * 
 * @param data Structure contenant les données
 * @return int TRUE si l'élément peut être chargé, FALSE sinon
 */
int	can_load_legacy(t_data *data)
{
	t_lnk *a;
	t_lnk *b;

	a = data->lst_a;
	b = data->lst_b;
	if (ft_dlstsize(b) > 2)
		if (a->rank == data->rank_max && b->prev->rank == data->min_b)
			return (TRUE);
	if (a->rank > data->rank_max / 2)
		return (FALSE);
	return (cool_push_b(data));
}

/**
 * @brief Vérifie si un élément peut être chargé dans B en suivant une partition
 * (par exemple bas/haut, pair/impair) pour minimiser le coût total
 * 
 * @param data Structure contenant les données
 * @param partition_type Type de partition (LOW/HIGH, ou autre code défini dans push_swap.h)
 * @return int TRUE si l'élément peut être chargé, FALSE sinon
 */
int	can_load_by_partition(t_data *data, int partition_type)
{
	t_lnk *a;
	t_lnk *b;

	a = data->lst_a;
	b = data->lst_b;
	
	// Vérification essentielle: toujours permettre le cas où B est vide
	if (!b)
		return (TRUE);
	
	// Cas particulier: si B contient déjà > 2 éléments et que nous avons le maximum de A 
	// avec le minimum de B en dessous, nous permettons cette insertion stratégique
	if (ft_dlstsize(b) > 2)
		if (a->rank == data->rank_max && b->prev->rank == data->min_b)
			return (TRUE);
	
	// Partition par moitié (pour les petites et grandes valeurs)
	if (partition_type == LOW)
	{
		if (a->rank > data->rank_max / 2)
			return (FALSE);
	}
	else if (partition_type == HIGH)
	{
		if (a->rank <= data->rank_max / 2)
			return (FALSE);
	}
	// Extension possible: ajouter d'autres types de partition ici
	// Par exemple, pair/impair:
	// else if (partition_type == EVEN_ODD) { ... }
	
	// Vérification finale: l'élément peut-il être inséré dans B ?
	return (cool_push_b(data));
}

/**
 * @brief Fonction wrapper pour utiliser can_load_by_partition avec la partition LOW
 * Cette fonction permet d'utiliser can_load_by_partition avec optimized_algo
 * 
 * @param data Structure contenant les données
 * @return int TRUE si l'élément peut être chargé, FALSE sinon
 */
int	can_load_low(t_data *data)
{
	return (can_load_by_partition(data, LOW));
}


