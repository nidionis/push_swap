/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:00:20 by supersko          #+#    #+#             */
/*   Updated: 2022/04/08 22:51:14 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	error_msg(void)
{
	write(1, "Error\n", 6);
	exit (0);
}

#include <stdio.h>
int	main(int argc, char *argv[])
{
	int	*args_tab;

	if (argc < 2)
		error_msg();
	argv = &argv[1];
	args_tab = get_args(argv, argc - 1);
	if !(args_tab)
		error_msg();
	do_stuff(argc - 1, args_tab);
}
