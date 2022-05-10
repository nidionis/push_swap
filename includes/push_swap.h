/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/10 18:34:09 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <libft.h>
# include <libftprintf.h>

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

int		get_args(int argc, char *argv[]);

#endif
