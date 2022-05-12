/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/12 18:05:41 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <libft.h>
# include <libftprintf.h>
# include <linked_lst.h>

typedef struct s_lnk_items
{
	int	nb;
	int	ind;
	int	rank;
}	t_lnk_items;

typedef struct s_lnk
{
	t_lnk_items		*items;
	struct s_lnk	*next;
	struct s_lnk	*prev;
}	t_lnk;

void	print_lst(t_lnk *lst, char *header);
t_lnk	*lnk_init(t_lnk *lnk);
t_lnk	*new_lnk(int nb, int ind, int rank);
void	push_item(t_lnk *lnk, t_lnk **lst);
t_lnk	*get_args(int argc, char *argv[]);
void	del_lst(t_lnk **lst);
t_lnk	*pop_item(t_lnk **lst);
void    rotate_lst(t_lnk **lst);
void    rrotate_lst(t_lnk **lst);

#endif