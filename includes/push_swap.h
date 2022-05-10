/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/10 21:19:05 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <libft.h>
# include <libftprintf.h>

typedef struct s_lnk
{
	void			*items;
	struct s_lnk	*next;
	struct s_lnk	*prev;
}	t_lnk;

typedef struct s_lnk_items
{
	int				nb;
	int				ind;
	int				indinlist;
	int				rank;
	int				rankinlist;
}	t_lnk_items;

typedef struct s_lst
{
	void	*items;
	t_lnk	*first;
	t_lnk	*last;
}	t_lst;

typedef struct s_lst_items
{
	size_t	size;
	int		min_val;
	int		max_val;
}	t_lst_items;

#endif
