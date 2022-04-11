/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:00:20 by supersko          #+#    #+#             */
/*   Updated: 2022/04/09 20:35:19 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

#include <stdio.h>
int	main(int argc, char *argv[])
{
	int	*args_tab;

	if (argc < 2)
		error_msg(NULL);
	argv = &argv[1];
	args_tab = get_args(argv, argc - 1);
	if !(args_tab)
		error_msg(NULL);
	do_stuff(argc - 1, args_tab);
}
