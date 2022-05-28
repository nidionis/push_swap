/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/28 15:09:08 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	clean_exit(t_lnk *lst_a, char **splited)
{
	if (lst_a)
		del_lst(&lst_a);
	if (splited)
		ft_free_split(splited);
	error_msg(NULL);
}

t_lnk	*get_args_allinone(char *str)
{
	t_lnk		*lst_a;
	t_lnk		*lnk;
	char		**splited;
	int			argc;
	long int	nb;

	argc = ft_wd_count(str, ' ') - 1;
	if (argc < 0)
		error_msg(NULL);
	splited = ft_split(str, ' ');
	nb = ft_atoi_err(splited[argc]);
	lnk = ft_new_lnk(nb, argc, 0);
	if (nb > 2147483647 || nb < -2147483648)
		clean_exit(lnk, splited);
	lst_a = lnk;
	while (argc--)
	{
		nb = ft_atoi_err(splited[argc]);
		lnk = ft_new_lnk(nb, argc, 0);
		push_item(lnk, &lst_a);
		if (nb > 2147483647 || nb < -2147483648)
			clean_exit(lst_a, splited);
	}
	ft_free_split(splited);
	return (lst_a);
}

t_lnk	*get_args(int argc, char *argv[])
{
	t_lnk		*lst_a;
	t_lnk		*lnk;
	long int	nb;

	argc -= 2;
	argv = &argv[1];
	nb = ft_atoi_err(argv[argc]);
	lnk = ft_new_lnk(nb, argc, 0);
	if (nb > 2147483647 || nb < -2147483648)
		clean_exit(lnk, NULL);
	lst_a = lnk;
	while (argc--)
	{
		nb = ft_atoi_err(argv[argc]);
		lnk = ft_new_lnk(nb, argc, 0);
		push_item(lnk, &lst_a);
		if (nb > 2147483647 || nb < -2147483648)
			clean_exit(lst_a, NULL);
	}
	return (lst_a);
}
