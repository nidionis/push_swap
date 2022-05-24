/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/24 19:34:37 by supersko         ###   ########.fr       */
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

t_lnk	*lst_cpy(t_lnk *lst)
{
	t_lnk	*lnk_ind;
	t_lnk	*new_lnk;
	t_lnk	*first_lnk;
	t_lnk	*last_lnk;

	lnk_ind = lst;
	first_lnk = ft_new_lnk(lnk_ind->nb, lnk_ind->ind, lnk_ind->rank);
	last_lnk = first_lnk;
	lnk_ind = lnk_ind->next;
	while (lnk_ind != lst)
	{
		new_lnk = ft_new_lnk(lnk_ind->nb, lnk_ind->ind, lnk_ind->rank);
		new_lnk->next = first_lnk;
		new_lnk->prev = last_lnk;
		last_lnk->next = new_lnk;
		last_lnk = new_lnk;
	}
	return (first_lnk);
}
