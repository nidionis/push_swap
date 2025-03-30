/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifications.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/03/30 20:44:50 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	is_on_min_or_max(t_data *data, t_lnk *lst)
{
    if (lst == data->a.lst)
    {
        if (data->a.max == lst->rank || data->a.min == lst->rank)
            return (TRUE);
    }
    else if (lst == data->b.lst)
    {
        if (data->b.max == lst->rank || data->b.min == lst->rank)
            return (TRUE);
    }
    return (FALSE);
}

int	is_sorted(t_lnk *lst)
{
	t_lnk	*lst_orig;

	reach_rank_ls_quiet(&lst, 0);
	lst_orig = lst;
	while (lst != lst_orig->prev)
	{
		t_lst temp;
		
		temp.lst = lst;
		if (head(&temp) == next(&temp) - 1)
			lst = lst->next;
		else
			return (FALSE);
	}
	return (TRUE);
}

int	ft_no_duplicate(t_lnk *lst)
{
	t_lnk	*lnk_ind1;
	t_lnk	*lnk_ind2;

	lnk_ind1 = lst;
	lnk_ind2 = lnk_ind1->next;
	while (lnk_ind1 != lnk_ind2)
	{
		if (lnk_ind1->nb == lnk_ind2->nb)
			return (0);
		lnk_ind2 = lnk_ind2->next;
	}
	lnk_ind1 = lnk_ind1->next;
	while (lnk_ind1 != lst)
	{
		lnk_ind2 = lnk_ind1->next;
		while (lnk_ind1 != lnk_ind2)
		{
			if (lnk_ind1->nb == lnk_ind2->nb)
				return (0);
			lnk_ind2 = lnk_ind2->next;
		}
		lnk_ind1 = lnk_ind1->next;
	}
	return (1);
}
