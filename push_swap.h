/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/04/09 21:00:58 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct  s_lnk
{
    int             nb;
    int             ind;
    int             indinlist;
    int             rank;
    int             rankinlist;
    struct s_lnk    *next;
    struct s_lnk    *prev;
}   t_lnk;

typedef struct s_lst
{
    t_lnk   *first;
    t_lnk   *last;
    size_t	size;
	int		min_val;
	int		max_val;
}   t_lst;

int		error_msg(char *msg);
t_lst   *get_args(int argc, char *argv[]);
int		ft_atoi(char *str_nb);

t_lnk	*new_lnk(int nb, int ind, int rank);
t_lnk	*lnk_init(t_lnk *lnk);
t_lst   *new_lst(void);
void    lst_init(t_lst *lst);
void	lst_init_rank(t_lst *lst_ini);
void	lst_init_size(t_lst *lst);
void	reset_max(t_lst *lst);
void	reset_min(t_lst *lst);
void    rev_lst(t_lst *lst);
void    *del_list(t_lst *lst);
void	lst_init_rankinlist(t_lst *lst);
void	lst_init_indinlist(t_lst *lst);
void	refreshRankinlist(t_lst *lst, t_lnk *rank_new_item, char *push_or_pop);
void	refreshIndinlist(t_lst *lst, t_lnk *moved_item, char *action);

t_lst	*reachSorting_rev_decr(t_lst *lst, int rank_nb);
t_lst	*reachSorting_rev_incr(t_lst *lst, int rank_nb);
t_lst	*reachSorting_decr(t_lst *lst, int rank_nb);
t_lst	*reachSorting_incr(t_lst *lst, int rank_nb);
t_lst	*reachSorting_rev_decr(t_lst *lst, int rank_nb);
t_lst	*reachSorting_rev_incr(t_lst *lst, int rank_nb);
t_lst	*reachSorting_incr(t_lst *lst, int rank_nb);
t_lst	*reachSorting_decr(t_lst *lst, int rank_nb);
t_lst	*bubble_sort_decr(t_lst *dest_lst, t_lst *lst);
t_lst	*bubble_sort_decr_indinlist(t_lst *lst, t_lst *dest_lst);
t_lst	*bubble_sort_decr_nb(t_lst *dest_lst, t_lst *lst);
t_lst	*bubble_sort_decr_ind(t_lst *lst, t_lst *dest_lst);
void    do_stuff(int *list, int lst_size);
char	*get_next_line(char *line);
void    print_lst(t_lst *lst_a , t_lst *lst_b);
int		verif(t_lst *lst_a);

t_lnk	*pop(t_lst	*lst);
t_lnk	*push_item(t_lnk *lnk, t_lst *lst);
void    swap_lst(t_lst *lst);
void	rotate_lst(t_lst *lst, int reverse);
void	rotate(char *instr, t_lst *lst_a, t_lst *lst_b);
void	push(char *instr, t_lst *lst_a, t_lst *lst_b);
void	swap(char *instr, t_lst *lst_a, t_lst *lst_b); 
void	apply_instruction(char *instr, t_lst *lst_a, t_lst *lst_b);
