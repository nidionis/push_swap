/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/13 16:21:30 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_lnk	*get_args_allinone(char *str)
{
	t_lnk	*lst_a;
	t_lnk	*lnk;
	char	**splited;
	int		argc;

	argc = ft_wd_count(str, ' ') - 1;
	if (argc < 0)
		error_msg(NULL);
	splited = ft_split(str, ' ');
	lnk = ft_new_lnk(ft_atoi_err(splited[argc]), argc, 0);
	lst_a = lnk;	
	while (argc--)
	{
		lnk = ft_new_lnk(ft_atoi_err(splited[argc]), argc, 0);
		push_item(lnk, &lst_a);
	}
	ft_free_split(splited);
	return (lst_a);
}

t_lnk	*get_args(int argc, char *argv[])
{
	t_lnk	*lst_a;
	t_lnk	*lnk;

	argc -= 2;
	argv = &argv[1];
	lnk = ft_new_lnk(ft_atoi_err(argv[argc]), argc, 0);
	lst_a = lnk;	
	while (argc--)
	{
		lnk = ft_new_lnk(ft_atoi_err(argv[argc]), argc, 0);
		push_item(lnk, &lst_a);
	}
	return (lst_a);
}

#include <stdio.h>
int main(int argc, char **argv)
{
	t_lnk	*lst_a = NULL;
	t_lnk	*lst_b = NULL;

	if (argc < 2)
		error_msg(NULL);
	else if (argc == 2)
		lst_a = get_args_allinone(argv[1]);
	else
		lst_a = get_args(argc, argv);
	lst_init_ranks(&lst_a);
	print_lst(lst_a, "lst a");
	print_lst_byrank(lst_a, "lst a");
	while (lst_a)
	{
		push(&lst_a, &lst_b);
	}
	print_lst(lst_b, "lst b");
	print_lst_byrank(lst_b, "lst b");
	del_lst(&lst_b);
}
