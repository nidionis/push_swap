/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/01/19 04:19:07 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	clean_exit(t_lnk *lst_a, t_lnk *lst_b, char **splited)
{
	if (lst_a)
		del_lst(&lst_a);
	if (lst_b)
		del_lst(&lst_b);
	if (splited)
		ft_free_split(&splited);
	ft_errmsg("error\n");
	return (1);
}

// t_lnk	*get_args_allinone(char *str)
// {
// 	t_lnk		*lst_a;
// 	t_lnk		*lnk;
// 	char		**splited;
// 	int			argc;
// 	long int	nb;

// 	argc = ft_wd_count(str, ' ') - 1;
// 	if (argc < 0)
// 		ft_errmsg("error\n");
// 	splited = ft_split(str, ' ');
// 	nb = ft_atoi_err(splited[argc]);
// 	lnk = ft_new_lnk(nb, argc, 0);
// 	if (nb > 2147483647 || nb < -2147483648)
// 		clean_exit(lnk, splited);
// 	lst_a = lnk;
// 	while (argc--)
// 	{
// 		nb = ft_atoi_err(splited[argc]);
// 		lnk = ft_new_lnk(nb, argc, 0);
// 		push_item(lnk, &lst_a);
// 		if (nb > 2147483647 || nb < -2147483648)
// 			clean_exit(lst_a, splited);
// 	}
// 	ft_free_split(&splited);
// 	return (lst_a);
// }

t_lnk	*get_args(int argc, char *argv[])
{
	t_lnk		*lst_a;
	t_lnk		*lnk;
	long int	nb;

	argc -= 2;
	argv = &argv[1];
	lnk = NULL;
	nb = ft_atoi_err(argv[argc]);
	if (nb > 2147483647 || nb < -2147483648)
		return (clean_exit(lnk, NULL, NULL), NULL);
	lnk = ft_new_lnk(nb, argc, 0);
	lst_a = lnk;
	while (argc--)
	{
		nb = ft_atoi_err(argv[argc]);
		if (nb > 2147483647 || nb < -2147483648)
			return (clean_exit(lst_a, NULL, NULL), NULL);
		lnk = ft_new_lnk(nb, argc, 0);
		push_item(lnk, &lst_a);
	}
	return (lst_a);
}
