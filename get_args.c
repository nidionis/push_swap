/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/10 21:02:55 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*get_args(int argc, char *argv[])
{
	t_lst	*lst_a;
	t_lnk	*lnk;

	if (argc < 2)
		error_msg(NULL);
	lst_a = new_lst();
	argc--;
	argv = &argv[1];
	while (argc--)
	{
		lnk = new_lnk(ft_atoi_err(argv[argc]), argc, 0);
		push_item(lnk, lst_a);
	}
	lst_init_ranks(lst_a);
	return (lst_a);
}

#include <stdio.h>
int main(int argc, char **argv)
{
	t_lst	*lst_a;

	lst_a = get_args(argc, argv);
	print_lst(lst_a, NULL);
}
