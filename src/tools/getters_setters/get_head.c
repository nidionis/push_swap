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

// head(a or b) breplace a(or b)->lst->rank
int	head(t_lst *x)
{
	if (!x)
		printf("[head] you are doing shit somehow\n");
	if (!x->lst)
		return (EMPTY_LST);
	return (x->lst->rank);
}

// replace a(or b)->lst->prev->rank
int	prev(t_lst *x)
{
	if (!x)
		printf("[prev] you are doing shit somehow\n");
	if (!x->lst)
		return (EMPTY_LST);
	return (x->lst->prev->rank);
}

// replace a(or b)->lst->next->rank
int	next(t_lst *x)
{
	if (!x)
		printf("[next] you are doing shit somehow\n");
	if (!x->lst)
		return (EMPTY_LST);
	return (x->lst->next->rank);
}
