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
# define SIZE_MAX 1000
# define BREAK_BEST_COMB 1
# define BREAK 1
# define IGNORE 0
# define EXE_CMD_ERROR 666

# define NO_INSTR -42
# define ERR_INSTR -43

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

void    apply_instr_step_itm(int **instr_steps_itm_addr);
void	apply_instr(t_data *data, int instr, int to_print);
int apply_ninstr(t_data *data, int *best_comb, int instr_idx, int nb_instr_idx);
int apply_first_set(t_data *data, int *best_comb);
int apply_second_set(t_data *data, int *best_comb);
int apply_best_comb_and(int (*f_do)(t_data *d, int instr), t_data *data, int *best_comb);
int             apply_best_comb(t_data *data, int *best_comb);
void    init_instr_map(t_instr_map *instr_map);
void    print_instr(int instr);
void    execute_command(t_lnk **lst_a, t_lnk **lst_b, int instr);
void    explore_insert_paths(t_data *d, int lst_instr[], int first_instr_steps[], int (*can_push)(t_data *));
int             can_firt_load(t_data *data);
int             can_load_high(t_data *data);
int             can_insert_at_max_b(t_lnk *a, t_data *data);
int             can_insert_between(t_lnk *a, t_lnk *b);
int             can_insert_at_min_b(t_lnk *a, t_data *data, t_lnk *b);
int             can_load_b(t_data *data);
int             can_dump(t_data *data);
int             ft_cost(int *best_comb);
int             count_instr(t_data *data, int instr, int (*can_push)(t_data *data, t_lnk *lst_a, t_lnk *lst_b));
t_lnk     *get_max(t_lnk *lst);
t_lnk *get_min(t_lnk *lst);
t_lnk *get_softmax(t_lnk *lst);
t_lnk *get_softmin(t_lnk *lst);
void    set_softmax(t_data *data, t_lnk *lst_a, t_lnk *lst_b);
void    set_softmin(t_data *data, t_lnk*lst_a, t_lnk *lst_b);
void    data_update(t_data *data, t_lnk **lst_a, t_lnk **lst_b);
void set_data(t_data *data, t_lnk **lst_a, t_lnk **lst_b);
void print_data(t_data *d);
void    print_instr_steps(int instr_steps_itm[2]);
int             swap_if_high_to_dump(t_data *data, int instr);
int             swap_if_softmax(t_data *data, int instr);
int             swap_if_low(t_data *data, int instr);
int             swap_if_high(t_data *data, int instr);
t_lnk   *get_args_allinone(char *str);
t_lnk   *get_args(int argc, char *argv[]);
t_lnk   *lst_cpy(t_lnk *lst);
char    *ft_realloc_cat(char *line, char c, int *len);
char    *get_next_line(int fd);
void    initialize_search(int *steps_forward, int *list_length, int *found, t_lnk *list, int target_rank);
void    search_target_rank(t_lnk *list, int target_rank, int *steps_forward, int *list_length, int *found);
int             get_shortestway(int target_rank, t_lnk *list);
void    set_best_comb(int *best_comb);
void    update_best_instr(t_data *data, int instr_steps_itm[2]);
void    set_instr_step_itm(int instr, int nb_instr, int *instr_steps_itm);
t_lnk   *lnk_init(t_lnk *lnk);
t_lnk   *ft_new_lnk(int nb, int ind, int rank);
void    del_lst(t_lnk **lst);
void    loop(t_lnk *lnk, t_lnk *l_i, int *max);
int             lst_init_ranks(t_lnk **lst);
int ft_dlstsize(t_lnk *lst);
int             *malloc_instr_steps_itm(t_data *data);
int             *malloc_best_insert(t_data *data);
void    print_lst(t_lnk *lst, char *header);
void    print_lst_byrank(t_lnk *lst, char *header);
void    push(t_lnk **from_lst, t_lnk **to_lst);
void    push_item(t_lnk *lnk, t_lnk **lst);
t_lnk   *pop_item(t_lnk **lst);
void    push_a(t_lnk **lst_a, t_lnk **lst_b);
void    push_b(t_lnk **lst_a, t_lnk **lst_b);
void	reach_rank(t_lnk **lst, int rank, int instr, int verbose);
void    rotate_lst(t_lnk **lst);
void    rrotate_lst(t_lnk **lst);
void    rotate_both(t_lnk **lst_a, t_lnk **lst_b);
void    rrotate_both(t_lnk **lst_a, t_lnk **lst_b);
void    rotate_a(t_lnk **lst_a, t_lnk **lst_b);
void    rotate_b(t_lnk **lst_a, t_lnk **lst_b);
void    rrotate_a(t_lnk **lst_a, t_lnk **lst_b);
void    rrotate_b(t_lnk **lst_a, t_lnk **lst_b);
void    sort_2_nb();
void    sort_3_nb(int max);
void    sort_4_nb();
void    sort_5_nb();
int             is_median(int max);
void    swap_lst(t_lnk **lst);
void    swap_a(t_lnk **lst_a, t_lnk **lst_b);
void    swap_b(t_lnk **lst_a, t_lnk **lst_b);
void    swap_both(t_lnk **lst_a, t_lnk **lst_b);
int             opposite_instr(int instr);
int             is_sorted(t_lnk *lst);
int             ft_no_duplicate(t_lnk *lst);
int *insert_target_to_list_steps(t_data *data, int lst_instr[],
    int (*can_push)(t_data *data), int cost);
int try_initial_push(t_data *d, int instr,
    int (*can_push)(t_data *data), int instr_steps_itm[2]);

#endif