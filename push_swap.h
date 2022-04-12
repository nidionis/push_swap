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
#include <stdlib.h>

typedef struct  s_lnk
{
    int             nb;
    int             ind;
    int             rank;
    struct s_lnk    *next;
    struct s_lnk    *prev;
}   t_lnk;

typedef struct s_lst
{
    t_lnk   *first;
    t_lnk   *last;
    size_t     size;
}   t_lst;

int	error_msg(char *msg);
t_lst   *get_args(int argc, char *argv[]);
int	ft_atoi(char *str_nb);

t_lnk	*new_lnk(int nb, int ind, int rank);
t_lnk	*lnk_init(t_lnk *lnk);
t_lst   *new_lst(void);
void    lst_init(t_lst *lst);
t_lnk	*pop(t_lst	*lst);
t_lnk	*push_item(t_lnk *lnk, t_lst *lst);
void    rev_lst(t_lst *lst);
void    *del_list(t_lst *lst);

void    do_stuff(int *list, int lst_size);
int     *bubble_sort(int *tab, int lst_size);
char	*get_next_line(int fd);

void print_lst(t_lst *lst);
