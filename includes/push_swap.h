/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/04/28 16:28:13 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdio.h>
# include "libftprintf.h"
# include "get_next_line.h"

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

void	bubble_loop_nb(t_lst *lst, t_lst *dest_lst);
t_lst	*bubble_sort_decr_nb(t_lst *lst, t_lst *dest_lst);
void	swap_loc(t_lnk *lnk);
t_lst	*inplace_sort_incr(t_lst *lst);
void	bubble_loop_ind(t_lst *lst, t_lst *dest_lst);
t_lst	*bubble_sort_decr_ind(t_lst *lst, t_lst *dest_lst);
void	bubble_loop_indinlst(t_lst *lst, t_lst *dest_lst);
t_lst	*bubble_sort_decr_indinlist(t_lst *lst, t_lst *dest_lst);
void	print_lst(t_lst *lst_a, t_lst *lst_b);
void	do_stuff(int *list1, int lst_size);
int	error_msg(char *msg);
int	ft_atoi(char *str_nb);
t_lst	*get_args(int argc, char *argv[]);
int	get_ind_from_rank(t_lst *lst, int rank);
int	get_ind_from_rank_inlist(t_lst *lst, int rank_inlst);
char	*get_next_line(char *line);
void	apply_instruction(char *instr, t_lst *lst_a, t_lst *lst_b);
int	verif(t_lst *lst_a);
void	push(char *instr, t_lst *lst_a, t_lst *lst_b);
void	swap(char *instr, t_lst *lst_a, t_lst *lst_b);
void	print_rotate_instr(char *instr);
void	rotate(char *instr, t_lst *lst_a, t_lst *lst_b);
t_lnk	*lnk_init(t_lnk *lnk);
t_lnk	*new_lnk(int nb, int ind, int rank);
t_lst	*new_lst(void);
void	lst_init(t_lst *lst);
void	del_list(t_lst *lst);
t_lnk	*pop(t_lst	*lst);
t_lnk	*push_item(t_lnk *lnk, t_lst *lst);
void	swap_lst(t_lst *lst);
void	rotate_lst(t_lst *lst, int reverse);
void	rev_lst(t_lst *lst);
void	lst_init_size(t_lst *lst);
void	lst_init_indinlist(t_lst *lst);
void	lst_init_rankinlist(t_lst *lst);
void	lst_init_ranks(t_lst *lst_ini);
void	reset_max(t_lst *lst);
void	reset_min(t_lst *lst);
void	refresh_lnks_pop(t_lst *lst);
void	refresh_lnks_push(t_lnk *lnk, t_lst *lst);
t_lst	*reachsorting_rev_decr(t_lst *lst, int rank_inlst);
t_lst	*reachsorting_rev_incr(t_lst *lst, int rank_inlst);
t_lst	*reachsorting_incr(t_lst *lst, int rank_inlst);
t_lst	*reachsorting_decr(t_lst *lst, int rank_inlst);
void	reachandsort(t_lst *lst, int rank_inlst, int ordre_croissant);
t_lst *bubbleReachandsort(t_lst *lst, int rank_inlst, int ordre_croissant);
void	refresh_indinlist_poped(t_lst *lst, t_lnk *moved_item);
void	refresh_indinlist_pushed(t_lst *lst, t_lnk *moved_item);
void	refresh_rankinlist_poped(t_lst *lst, t_lnk *moved_item);
void	refresh_rankinlist_pushed(t_lst *lst, t_lnk *moved_item);
void	refresh_afterpush_inlist(t_lst *lst, t_lnk *moved_item);
void	refresh_afterpop_inlist(t_lst *lst, t_lnk *moved_item);
#endif
