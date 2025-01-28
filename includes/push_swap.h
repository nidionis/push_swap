/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/01/29 00:37:36 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <libft.h>
# include <libftprintf.h>
# define TRUE 1
# define FALSE 0
# define UNSET -1
# define PRINT 1
# define QUIET 0
# define INSTR 0
# define NB_INSTR 1
# define FIRST_INSTR 0
# define NB_FIRST_INSTR 1
# define SECOND_INSTR 2
# define NB_SECOND_INSTR 3
# define INT_MAX 2147483647
# define LOOP_END 2147483647
# define CANT_INSERT 2147483647

typedef struct s_lnk t_lnk;

typedef struct s_data
{
	int	max_a;
	int	min_a;
	int	max_b;
	int	min_b;
	int	softmax_a;
	int	softmin_a;
	int	softmax_b;
	int	softmin_b;
	int rotate_instr[2][4];
	t_lnk *lst_a;
	t_lnk *lst_b;
	int	best_inst_step[2];
}	t_data;

typedef struct s_lnk
{
	int				nb;
	int				ind;
	int				rank;
	struct s_lnk	*next;
	struct s_lnk	*prev;
}	t_lnk;

enum	e_instr {
	INSTR_MIN = 1,
	sa = INSTR_MIN,
	sb,
	pa,
	pb,
	ra,
	rb,
	rra,
	rrb,
	rr,
	rrr,
	ss,
	ROTATE = rr,
	RROTATE = rrr,
	INSTR_MAX = ss
};

extern struct s_data d;


int             can_push_b();
int             can_push_a();
void             insert_target(t_lnk *target, int way);
void	apply_instr(t_lnk **lst_a, t_lnk **lst_b, int instr, int to_print);
int             fucking_normi_2(char *str);
int             instr_to_i(char *str);
void    i_to_instr(int i);
t_lnk     *get_max(t_lnk *lst);
t_lnk *get_min(t_lnk *lst);
t_lnk *get_softmax(t_lnk *lst);
t_lnk *get_softmin(t_lnk *lst);
void set_softmax();
void set_softmin();
void    data_update();
void set_data();
void print_data(t_data *d);
t_lnk   *get_args_allinone(char *str);
t_lnk   *get_args(int argc, char *argv[]);
t_lnk   *lst_cpy(t_lnk *lst);
char    *ft_realloc_cat(char *line, char c, int *len);
char    *get_next_line(int fd);
t_lnk   *lnk_init(t_lnk *lnk);
t_lnk   *ft_new_lnk(int nb, int ind, int rank);
void    del_lst(t_lnk **lst);
void    loop(t_lnk *lnk, t_lnk *l_i, int *max);
int             lst_init_ranks(t_lnk **lst);
void    select_algo(int ind_max);
void    print_lst(t_lnk *lst, char *header);
void    print_lst_byrank(t_lnk *lst, char *header);
void    push(t_lnk **from_lst, t_lnk **to_lst);
void    push_item(t_lnk *lnk, t_lnk **lst);
t_lnk   *pop_item(t_lnk **lst);
void    reach_rank(t_lnk **lst, int rank, int direction);
int             get_shortestway(int rank, t_lnk *lst);
void    rotate_lst(t_lnk **lst);
void    rrotate_lst(t_lnk **lst);
int             is_median(int max);
void    sort_2_nb();
void    sort_3_nb(int max);
void    sort_4_nb();
void    sort_5_nb();
void    swap_lst(t_lnk **lst);
int             is_sorted(t_lnk *lst);
int             ft_no_duplicate(t_lnk *lst);
//void	insert_target_to_b(t_lnk *target, int way);
int	*insert_target_to_list_steps(t_lnk *target, t_lnk *lst, int lst_instr[], int (*can_push)(t_lnk *lst_a, t_lnk *lst_b));
void	fucking_norminette(t_lnk **lst_a, t_lnk **lst_b, int instr);
int ft_lstsize(t_lnk *lst);


#endif