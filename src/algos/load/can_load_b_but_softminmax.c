/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_load_b_but_softminmax.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:37:52 by nidionis          #+#    #+#             */
/*   Updated: 2025/03/09 15:37:52 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/**
 * @brief Checks if an element can be loaded to B, excluding softmin/softmax values
 * 
 * This function extends the can_load_b behavior by adding the constraint that
 * the value must not be greater than or equal to softmax or less than or equal 
 * to softmin. Otherwise, it uses the can_load_low function behavior.
 * 
 * @param data Structure containing stacks and state
 * @return int TRUE if element can be loaded to B, FALSE otherwise
 */
int	can_load_b_but_softminmax(t_data *data)
{
	t_lnk *a;

	a = data->lst_a;
	if (!a)
		return (FALSE);
	
	/* Check if value is outside the acceptable range */
	if (a->rank >= data->softmax_a || a->rank <= data->softmin_a)
		return (FALSE);
	
	/* Use existing can_load_low behavior for other checks */
	return (can_load_low(data));
}
