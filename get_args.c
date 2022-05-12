/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/12 14:25:12 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_lnk	*get_args(int argc, char *argv[])
{
	t_lnk	*lst_a;
	t_lnk	*lnk;

	if (argc < 2)
		error_msg(NULL);
	argc -= 2;
	argv = &argv[1];
	lnk = new_lnk(ft_atoi_err(argv[argc]), argc, 0);
	lst_a = lnk;	
	while (argc--)
	{
		lnk = new_lnk(ft_atoi_err(argv[argc]), argc, 0);
		push_item(lnk, &lst_a);
	}
//	lst_init_ranks(lst_a);
	return (lst_a);
}

#include <stdio.h>
int main(int argc, char **argv)
{
	t_lnk	*lst_a = NULL;
	t_lnk	*lst_b = NULL;
	t_lnk	*tmp = NULL;

	lst_a = get_args(argc, argv);
	print_lst(lst_a, "lst a");
	while (lst_a)
	{
		tmp = pop_item(&lst_a);
		ft_printf("tmp = %d\n", tmp->items->nb);
		push_item(tmp, &lst_b);
		print_lst(lst_b, "lst b");
	}
	print_lst(lst_a, "lst b");
	del_lst(&lst_b);
	print_lst(lst_a, "is empty ?");
}
