/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/02/03 01:10:22 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <libft.h>
# include <stdio.h>
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
# define LOOP_END 123456789
# define CANT_INSERT 101
# define NO_INSTR -42
# define SIZE_MAX 1000
# define BREAK_BEST_COMB 1
# define BREAK 1
# define IGNORE 0
# define EXE_CMD_ERROR 666

typedef struct s_lnk t_lnk;

typedef struct s_instr_map
{
    char    *name;
    int     code;
    void    (*func)(t_lnk **, t_lnk **);
}   t_instr_map;

typedef struct s_data
{
	int rank_max;
	int	max_a;
	int	min_a;
	int	max_b;
	int	min_b;
	int	softmax_a;
	int	softmin_a;
	int	softmax_b;
	int	softmin_b;
	int mediane_a;
	int mediane_b;
	int rotate_instr[2][4];
	t_lnk *lst_a;
	t_lnk *lst_b;
	int	best_inst_step[2];
	int	best_comb[4];
	//int	best_cost_instr;
	int	best_cost_comb;
	int r_instr[7];
	t_instr_map instr_map[12];
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


int ft_dlstsize(t_lnk *lst);
t_lnk	*reach_rank(t_lnk *lst, int rank);
void	reach_rank_lst_a(t_lnk **lst, int rank, int direction, int verbose);
int	can_load_high(t_data *data);
int swap_if_low(t_data *data, int instr);
int	can_dump(t_data *data);
int	can_load_b(t_data *data);
void             insert_target(t_lnk *target, int way);
void	apply_instr(t_data *d, t_lnk **lst_a, t_lnk **lst_b, int instr, int to_print);
int             fucking_normi_2(char *str);
int             instr_to_i(char *str);
void    i_to_instr(int i);
t_lnk     *get_max(t_lnk *lst);
t_lnk *get_min(t_lnk *lst);
t_lnk *get_softmax(t_lnk *lst);
t_lnk *get_softmin(t_lnk *lst);
void	set_softmax(t_data *data, t_lnk *lst_a, t_lnk *lst_b);
void	set_softmin(t_data *data, t_lnk *lst_a, t_lnk *lst_b);
void	data_update(t_data *data, t_lnk **lst_a, t_lnk **lst_b);
void print_data(t_data *d);
void set_data(t_data *data, t_lnk **lst_a, t_lnk **lst_b);
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
int	*insert_target_to_list_steps(t_lnk *target, t_lnk *lst, int lst_instr[], int (*can_push)(t_data *data, t_lnk *lst_a, t_lnk *lst_b), int cost);
void	fucking_norminette(t_lnk **lst_a, t_lnk **lst_b, int instr);
void print_instr_steps(int instr_steps_itm[2]);
void apply_instr_step_itm(int **instr_steps_itm_addr);
int apply_best_comb(t_data *data, int *best_comb);
int *best_insert(t_lnk *lst_a, t_lnk *lst_b, int lst_instr[], int (*can_push)(t_data *data, t_lnk *lst_a, t_lnk *lst_b));
int ft_cost(int *best_comb);
void	reach_rank_lst_b(t_lnk **lst, int rank, int direction);
int	load_b_but_softmins_and_low(t_data *data, t_lnk *a, t_lnk *b);
int	load_b_but_softmax_and_hight(t_data *data, t_lnk *a, t_lnk *b);
void apply_best_comb_until_softmin(t_data *data, int *best_comb);
int can_firt_load(t_data *data);
int swap_if_high(t_data *data, int instr);
int apply_best_comb_and(int (*f_do)(t_data *d, int instr), t_data *data, int *best_comb);
int swap_if_high_to_dump(t_data *data, int instr);

void print_instr_steps(int instr_steps_itm[2]);
void load_minmax(t_data *data, int *best_comb);

void	swap_a(t_lnk **lst_a, t_lnk **lst_b);
void	swap_b(t_lnk **lst_a, t_lnk **lst_b);
void	swap_both(t_lnk **lst_a, t_lnk **lst_b);
void	push_a(t_lnk **lst_a, t_lnk **lst_b);
void	push_b(t_lnk **lst_a, t_lnk **lst_b);
void	rotate_a(t_lnk **lst_a, t_lnk **lst_b);
void	rotate_b(t_lnk **lst_a, t_lnk **lst_b);
void	rrotate_a(t_lnk **lst_a, t_lnk **lst_b);
void	rrotate_b(t_lnk **lst_a, t_lnk **lst_b);
void	rotate_both(t_lnk **lst_a, t_lnk **lst_b);
void	rrotate_both(t_lnk **lst_a, t_lnk **lst_b);
void	init_instr_map(t_instr_map *instr_map);

#endif