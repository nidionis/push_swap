/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:47:40 by supersko          #+#    #+#             */
/*   Updated: 2022/04/08 13:48:06 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 
#include "push_swap.h"

int *bubble_sort(int *tab, int lst_size)
{
	int	lstsize;
	int ind;
	int tmp;

	ind = 0;
	lstsize = lst_size;
	while (lstsize > 2)
	{
		while (ind < lstsize - 2)
		{
			if (tab[ind] > tab[ind + 1])
			{
				tab[ind] = tmp;
				tab[ind] = tab[ind + 1];
				tab[ind + 1] = tmp;
			}
			ind++;
		}
		lstsize--;
		ind = 0;
	}
	return (tab);
}

#include <stdio.h>
int main(int argc, char *argv[])
{
	int *tab;
	int lst_size = 5;

	tab = malloc(4 * (argc -1));
	tab = bubble_sort(get_args(argv, argc - 1), argc - 1);
	while (lst_size-- > 1)
	{
		printf("%c\n", tab[lst_size]);
	}
}
