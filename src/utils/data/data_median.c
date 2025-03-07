/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 21:16:34 by supersko          #+#    #+#             */
/*   Updated: 2025/03/07 21:17:40 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/**
 * @brief Calcule la médiane des rangs d'une pile
 * 
 * @param lst Pointeur vers la pile à analyser
 * @return int Valeur médiane des rangs de la pile
 */
int	set_mediane(t_lnk **lst)
{
	int		*tab;
	int		i;
	int		len;
	t_lnk	*tmp;
	int		mediane;

	if (!lst || !*lst)
		return (0);
	len = lnk_lstlen(*lst);
	tab = malloc(sizeof(int) * len);
	if (!tab)
		return (0);
	tmp = *lst;
	i = 0;
	while (i < len)
	{
		tab[i] = tmp->rank;
		tmp = tmp->next;
		i++;
	}
	ft_sort_int_tab(tab, len);
	mediane = tab[len / 2];
	free(tab);
	return (mediane);
}
