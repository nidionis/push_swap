/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/09 19:40:48 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <libftprintf.h>
# include <libft.h>
# include <linked_lst.h>

typedef struct s_lnk
{
	int				nb;
	int				ind;
	int				indinlist;
	int				rank;
	int				rankinlist;
	struct s_lnk	*next;
	struct s_lnk	*prev;
}	t_lnk;

typedef struct s_lst
{
	t_lnk	*first;
	t_lnk	*last;
	size_t	size;
	int		min_val;
	int		max_val;
}	t_lst;

int	get_args(int argc, char *argv[]);

#endif
