/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/04/04 15:53:16 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lnk	*get_args(t_data *d, int argc, char *argv[])
{
	t_lnk		*lnk;
	long int	nbr;

	argc -= 2;
	argv = &argv[1];
	nbr = ft_atoi_err(argv[argc]);
	if (nbr > 2147483647)
	{
		return (NULL);
	}
	lnk = ft_new_lnk(nbr, argc, 0);
	d->a.lst = lnk;
	while (argc--)
	{
		nbr = ft_atoi_err(argv[argc]);
		if (nbr > 2147483647)
		{
			del_lst(&d->a.lst);
			return (NULL);
		}
		lnk = ft_new_lnk(nbr, argc, 0);
		push_item(lnk, &d->a.lst);
	}
	return (d->a.lst);
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
