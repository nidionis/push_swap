/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/04/09 00:26:24 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

int	ft_atoi(char *str_nb)
{
	int	nb;
	int sign;
	int	loop_nb;

	sign = 1;
	nb = 0;
	loop_nb = 0;
	if (*str_nb == '-')
	{
		sign = -1;
		str_nb++;
	}
	while (*str_nb == '0')
		str_nb++;
	while (*str_nb && (*str_nb >= '0' && *str_nb <= '9') &&
		   	//!(loop_nb++ > 10 && -1 * loop_nb > 10))
		nb = (*str_nb++ - 48) + 10 * nb;
	nb *= sign;
	if ((loop_nb > 9 && nb * sign < 0 && nb != -2147483648) || *str_nb != 0)
		error_msg();
	return (nb);
}

int *get_args(char *argv[], int arg_nb)

{
	int	*args_tab;

	args_tab = malloc(sizeof(int) * arg_nb);
	if (!args_tab)
		error_msg();
	while (arg_nb--)
		args_tab[arg_nb] = ft_atoi(argv[arg_nb]);
	return (args_tab);
}

// 
// #include <stdio.h>
// int main()
// {
// 	printf("%d\n", ft_atoi("-2147483648"));
// 	printf("%d\n", ft_atoi("2147483655"));
// 	printf("%d\n", ft_atoi("-999999999999999999999"));
// }
