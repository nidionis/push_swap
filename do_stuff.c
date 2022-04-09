/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_stuff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:35:12 by supersko          #+#    #+#             */
/*   Updated: 2022/04/08 13:45:19 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa (swap a): Swap the first 2 elements at the top of stack a.  // Do nothing if there is only one or no elements.
// sb (swap b): Swap the first 2 elements at the top of stack b.  // Do nothing if there is only one or no elements.
// ss : sa and sb at the same time.
// pa (push a): Take the first element at the top of b and put it at the top of a.  // Do nothing if b is empty.
// pb (push b): Take the first element at the top of a and put it at the top of b.  // Do nothing if a is empty.
// ra (rotate a): Shift up all elements of stack a by 1.  // The first element becomes the last one.
// rb (rotate b): Shift up all elements of stack b by 1.  // The first element becomes the last one.
// rr : ra and rb at the same time.
// rra (reverse rotate a): Shift down all elements of stack a by 1.  // The last element becomes the first one.
// rrb (reverse rotate b): Shift down all elements of stack b by 1.  // The last element becomes the first one.
// rrr : rra and rrb at the same time.


void do_stuff(int *list1, int lst_size)
{
	int	*list2;	

	list2 = malloc(sizeof(int) * lst_size);
	free(list2);
}
