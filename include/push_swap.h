/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/04/01 19:11:57 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <libft.h>
# include <stdio.h>
# define TRUE 1
# define FALSE 0
# define UNSET -3
# define PRINT_DISPLAY 1
# define QUIET 0
# define INSTR 0
# define NB_INSTR 1
# define FIRST_INSTR 0
# define NB_FIRST_INSTR 1
# define SECOND_INSTR 2
# define NB_SECOND_INSTR 3
# define INT_MAX 2147483647
# define LOOP_END 123456789
# define CANT_INSERT 2147483646
# define EMPTY_LST -2
# define SIZE_MAX 500
# define BREAK_BEST_COMB -3
# define BREAK 1
# define IGNORE 0
# define EXE_CMD_ERROR 666
# define NO_MOVE 13531

# define LOW 432
# define HIGH 433
# define COEF_TURK 7

# define NOT_FOUND -41
# define NO_INSTR -42
# define ERR_INSTR -43
# define ERR_IS_LOW_OR_HIGH -44
# define ERR_CAN_ACCEPT -45
# define ERR_BUTT -46
# define ERR_NO_BEST_COMB -47
# define UNSET_NB_INSTR -48

typedef struct s_lnk t_lnk;

typedef struct s_best_comb
{
	t_list *best_comb;
	int max_cost;
} t_best_comb;

typedef struct s_instr_map
{
    char    *name;
    int     code;
    void    (*func)(t_lnk **, t_lnk **);
}   t_instr_map;

typedef struct s_instr_step
{
	int		instr;
	int		nb_instr;
}	t_instr_step;

typedef struct s_lst
{
	t_lnk *lst;
	int size;
	int max;
	int min;
	int softmax;
	int softmin;
	int sorting_range;
}	t_lst;

typedef struct s_data
{
	int rank_max;
	t_lst a;
	t_lst b;
	int min_to_load;
	int max_to_load;
	int *r_instr;
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

typedef struct s_searching_op
{
	int (*f_can)(t_data *d);
	int (*f_do)(t_data *d, int instr);
	int	*instr_ls;
	int px;
	int verbose;
} t_searching_op;

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

int dump_b(t_data *data, int verbose);
void	sort_2_nb();
void	sort_3_nb(int max);
void	sort_4_nb();
void	sort_5_nb();

int should_swap_b_unsafe(t_lnk *lst);
int should_swap_b(t_lnk *lst, int mediane);
int break_when_minmax_loaded(t_data *d, int instr);

int can_splitload_but_medium(t_data *data);
int can_splitload_but_softs(t_data *data);
int can_quicklad_b(t_data *data);
int can_dirty_load_b(t_data *data);
int can_range_sort(t_data *data);
int can_splitload(t_data *data);
int	can_first_load(t_data *data);
int	can_load_high(t_data *data);
int	can_insert_at_max_b(t_data *data);
int	can_insert_to_b_between(t_data *data);
int	can_insert_at_min_b(t_data *data);
int	can_load_b(t_data *data);
int	can_dump_b(t_data *data);
int	can_insert_at_max_a(t_data *data);
int	can_insert_to_b_between(t_data *data);
int	can_insert_at_min_b(t_data *data);
int	can_load_b(t_data *data);
int can_splitload(t_data *data);
int can_splitload_but_medium(t_data *data);
int can_splitload_but_softs(t_data *data);

int first_load_low_and_minmax(t_data *data, int verbose);
int reach_max_lst_b(t_data *data, int verbose);
int set_minmax_load_low(t_data *data, int verbose);
t_list *ft_best_comb(t_data *d, int *instr_ls, int (*can_push)(t_data *), int max_cost);
t_list	*best_insert(t_data *d, int lst_instr[], int (*can_push)(t_data *), int max_cost);
int get_steps(t_list *instr_step_node);
t_list *init_instr_step_node(int instr, int nb_instr_init);
int	count_instr(t_data *data, int instr, int (*can_push)(t_data *data), int max);
void	initialize_search(int *steps_forward, int *list_length, int *found, t_lnk *list, int target_rank);
int is_rank_in_lst_forward(int target_rank, t_lnk *list);
void	search_target_rank(t_lnk *list, int target_rank, int *steps_forward, int *list_length, int *found);
int	get_shortestway(int target_rank, t_lnk *list);
int	is_sorted(t_lnk *lst);
int	ft_no_duplicate(t_lnk *lst);
int    get_kinda_mediane(t_data *data, t_lnk *lst);
int get_ntil(t_lnk *lst, int min, int max);
void	print_instr_steps(int instr_steps_itm[2]);
t_list *handle_best_comb(t_best_comb *best, t_list *instr_step_node, int instr, int nb_instr);
void handle_else_case(t_data *d_copy, t_instr_step *first_intr_step, int instr, t_list *instr_step_node);
int should_update(t_best_comb *best, t_list *instr_step_node, int nb_first_instr);
t_list *best_insert_dir(t_data *d, int instr, int (*can_push)(t_data *), int max_cost);
void handle_no_best_comb(t_list *first_intr_step_node, t_data *d_copy, int instr);
void best_insert_loop(t_data *d_copy, int instr, int (*can_push)(t_data *), int *max_cost, t_list **best_comb);
t_list *best_insert_dir(t_data *d, int instr, int (*can_push)(t_data *), int max_cost);
int	ft_cost(t_list *best_comb);
void	push(t_lnk **from_lst, t_lnk **to_lst);
void	push_item(t_lnk *lnk, t_lnk **lst);
t_lnk	*pop_item(t_lnk **lst);
void	push_a(t_lnk **lst_a, t_lnk **lst_b);
void	push_b(t_lnk **lst_a, t_lnk **lst_b);
void	swap_lst(t_lnk **lst);
void	swap_a(t_lnk **lst_a, t_lnk **lst_b);
void	swap_b(t_lnk **lst_a, t_lnk **lst_b);
void	swap_both(t_lnk **lst_a, t_lnk **lst_b);
t_lnk	*lnk_init(t_lnk *lnk);
t_lnk	*ft_new_lnk(int nb, int ind, int rank);
void	del_lst(t_lnk **lst);
void	loop(t_lnk *lnk, t_lnk *l_i, int *max);
int	lst_init_ranks(t_lnk **lst);
int ft_dlstsize(t_lnk *lst);
int	ft_rev_instr(int instr);
int mirror_instr(const int instr);
int ft_nb_instr(t_list *instr_step_node);
t_lnk     *get_max(t_lnk *lst);
t_lnk *get_min(t_lnk *lst);
t_lnk *get_softmax(t_lnk *lst);
t_lnk *get_softmin(t_lnk *lst);
void	set_softmax(t_data *data, t_lnk *lst_a, t_lnk *lst_b);
void	set_softmin(t_data *data, t_lnk*lst_a, t_lnk *lst_b);
void	data_update_r(t_data *data, t_lnk **lst_a, t_lnk **lst_b);
void init_data(t_data *data, t_lnk **lst_a, t_lnk **lst_b);
void print_data(t_data *d);
char	*ft_realloc_cat(char *line, char c, int *len);
char	*get_next_line(int fd);
int apply_set_and(int (*f_do)(t_data *d, int instr), t_data *data, t_instr_step *instr_step, int verbose);
int apply_best_comb_and(int (*f_do)(t_data *d, int instr), t_data *data, t_list *best_comb, int verbose);
int	instr_direction(int instr);
void	reach_rank_dir(t_lnk **lst, int rank, int instr, int verbose);
void	reach_rank_ls_quiet(t_lnk **lst, int rank);
int	reached_rank(int rank, t_data *data);
int reach_rank(t_data *data, int rank, int verbose);
void init_instr_map(t_instr_map (*instr_map)[12]);
void	print_instr(t_data *data, int instr);
void	print_instr_from_int_heavy(int instr);
void	execute_command(t_lnk **lst_a, t_lnk **lst_b, int instr, t_instr_map instr_map[]);
int	is_rotating(int instr);
int	apply_instr(t_data *data, int instr, int to_print);
void	rotate_lst(t_lnk **lst);
void	rrotate_lst(t_lnk **lst);
void	rotate_both(t_lnk **lst_a, t_lnk **lst_b);
void	rrotate_both(t_lnk **lst_a, t_lnk **lst_b);
void	rotate_a(t_lnk **lst_a, t_lnk **lst_b);
void	rotate_b(t_lnk **lst_a, t_lnk **lst_b);
void	rrotate_a(t_lnk **lst_a, t_lnk **lst_b);
void	rrotate_b(t_lnk **lst_a, t_lnk **lst_b);
void	print_lst_byrank(t_lnk *lst, char *header);
void	print_lst(t_data *d);
void print_instr_step(t_instr_step *instr_step);
void print_instr_ls(t_list *ls);
t_lnk	*get_args_allinone(char *str);
t_lnk	*get_args(t_data *d, int argc, char *argv[]);
t_lnk	*lst_cpy(t_lnk *lst);
int	head(t_lst *x);
int	next(t_lst *x);
int	prev(t_lst *x);
void	data_update_r(t_data *data, t_lnk **lst_a, t_lnk **lst_b);
void	data_update(t_data *data, t_lnk **lst_a, t_lnk **lst_b);
int	is_on_min_or_max(t_data *data, t_lnk *lst);
int	do_best_insert(t_data *data, t_searching_op *op);
int can_slpitload_but_range_and_softs(t_data *data);
int can_first_splitload(t_data *data);


#endif
