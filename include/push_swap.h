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
# define CANT_INSERT 2147483646
# define SIZE_MAX 500
# define BREAK_BEST_COMB -1
# define BREAK 1
# define IGNORE 0
# define EXE_CMD_ERROR 666
# define NO_MOVE 13531

# define LOW 432
# define HIGH 433

# define NOT_FOUND -41
# define NO_INSTR -42
# define ERR_INSTR -43
# define ERR_IS_LOW_OR_HIGH -44
# define ERR_CAN_ACCEPT -45
# define ERR_BUTT -46

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
	t_lnk *lst_a;
	t_lnk *lst_b;
	int min_to_load;
	int max_to_load;
	int *r_instr;
	t_instr_map *instr_map;
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

int	optimized_push_to_b(t_data *data, int (*can_do)(t_data *data), int verbose);
int	main_algo(t_data *data, int verbose);
int	is_on_min_or_max(t_data *data, t_lnk *lst);
int can_push_b_dec(t_data *data);
int can_push_b_optimized(t_data *data);
int should_swap_b(t_lnk *lst, int mediane);
int should_swap_b_(t_data *data, int instr);
int    get_kinda_mediane(t_data *data, t_lnk *lst);

int is_rank_in_lst_forward(int target_rank, t_lnk *list);
int mirror_instr(const int instr);
void	search_target_rank(t_lnk *list, int target_rank, int *steps_forward, int *list_length, int *found);
int set_minmax_breaking(t_data *data, int verbose);
int set_minmax_load_low(t_data *data, int verbose);

void print_instr_ls(t_list *ls);
void print_instr_step(t_instr_step *instr_step);
int ft_nb_instr(t_list *instr_step_node);

//int	count_instr(t_data *data, int instr, int (*can_push)(t_data *data));
void	update_best_comb(int (*b_c)[4], int *instr_steps_itm1, int *instr_steps_itm2);
void    apply_instr_step_itm(int **instr_steps_itm_addr);
int	apply_instr(t_data *data, int instr, int to_print);
int apply_ninstr(t_data *data, int *best_comb, int instr_idx, int nb_instr_idx);
int apply_first_set(t_data *data, int *best_comb);
int apply_second_set(t_data *data, int *best_comb);
int apply_best_comb_and(int (*f_do)(t_data *d, int instr), t_data *data, t_list *best_comb, int verbose);
int             apply_best_comb(t_data *data, int *best_comb);
t_instr_map		*init_instr_map(void);
void    print_instr(t_data *data, int instr);
void	execute_command(t_lnk **lst_a, t_lnk **lst_b, int instr, t_instr_map instr_map[]);
void    explore_insert_paths(t_data *d, int lst_instr[], int first_instr_steps[], int (*can_push)(t_data *));
int             can_load_legacy(t_data *data);
int             can_load_by_partition(t_data *data, int partition_type);
int             can_load_high(t_data *data);
int             can_insert_at_extremes(t_data *data);
int             is_extreme_b(t_data *data);
int             cool_push_b(t_data *data);
int             can_push_b(t_data *data);
int             can_dump(t_data *data);
int             ft_cost(t_list *best_comb);
//int             count_instr(t_data *data, int instr, int (*can_push)(t_data *data));
int	count_instr(t_data *data, int instr, int (*can_push)(t_data *data), int max);
t_lnk     *get_max(t_lnk *lst);
t_lnk *get_min(t_lnk *lst);
t_lnk *get_softmax(t_lnk *lst);
t_lnk *get_softmin(t_lnk *lst);
void    set_softmax(t_data *data, t_lnk *lst_a, t_lnk *lst_b);
void    set_softmin(t_data *data, t_lnk*lst_a, t_lnk *lst_b);
void    data_update(t_data *data, t_lnk **lst_a, t_lnk **lst_b);
void init_data(t_data *data, t_lnk **lst_a, t_lnk **lst_b);
void print_data(t_data *d);
void    print_instr_steps(int instr_steps_itm[2]);
int             swap_if_high_to_dump(t_data *data, int instr);
int             swap_if_softmax(t_data *data, int instr);
int             swap_if_low(t_data *data, int instr);
int             swap_if_high(t_data *data, int instr);
//t_lnk   *get_args_allinone(char *str);
//t_lnk   *get_args(int argc, char *argv[]);
t_lnk	*get_args(t_data *d, int argc, char *argv[]);
t_lnk   *lst_cpy(t_lnk *lst);
char    *ft_realloc_cat(char *line, char c, int *len);
char    *get_next_line(int fd);
void    initialize_search(int *steps_forward, int *list_length, int *found, t_lnk *list, int target_rank);
void    search_target_rank(t_lnk *list, int target_rank, int *steps_forward, int *list_length, int *found);
int             get_shortestway(int target_rank, t_lnk *list);
int             set_mediane(t_lnk **lst);
int             get_kinda_mediane(t_data *data, t_lnk *lst_a);
void    set_best_comb(int *best_comb);
void    update_best_instr(t_data *data, int instr_steps_itm[2]);
void    set_instr_step_itm(int instr, int nb_instr, int *instr_steps_itm);
t_lnk   *lnk_init(t_lnk *lnk);
t_lnk   *ft_new_lnk(int nb, int ind, int rank);
void    del_lst(t_lnk **lst);
void    loop(t_lnk *lnk, t_lnk *l_i, int *max);
int             lst_init_ranks(t_lnk **lst);
int ft_dlstsize(t_lnk *lst);
int lnk_lstlen(t_lnk *lst);
void ft_sort_int_tab(int *tab, int size);
int             *malloc_instr_steps_itm(t_data *data);
int             *malloc_best_insert(t_data *data);
void    print_lst(t_data *d);
void    print_lst_byrank(t_lnk *lst, char *header);
void    print_lst_inline(t_lnk *lst);
void    push(t_lnk **from_lst, t_lnk **to_lst);
void    push_item(t_lnk *lnk, t_lnk **lst);
t_lnk   *pop_item(t_lnk **lst);
void    push_a(t_lnk **lst_a, t_lnk **lst_b);
void    push_b(t_lnk **lst_a, t_lnk **lst_b);
void	reach_rank_dir(t_lnk **lst, int rank, int instr, int verbose);
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
void    swap_lst(t_lnk **lst);
void    swap_a(t_lnk **lst_a, t_lnk **lst_b);
void    swap_b(t_lnk **lst_a, t_lnk **lst_b);
void    swap_both(t_lnk **lst_a, t_lnk **lst_b);
int             ft_rev_instr(int instr);
int             is_sorted(t_lnk *lst);
int             ft_no_duplicate(t_lnk *lst);
int *insert_target_to_list_steps(t_data *data, int lst_instr[],
    int (*can_push)(t_data *data), int cost);
int try_initial_push(t_data *d, int instr,
    int (*can_push)(t_data *data), int instr_steps_itm[2]);
void iterate_instructions(t_data *d, int lst_instr[],
    int (*can_push)(t_data *data));
void	reach_rank_ls_quiet(t_lnk **lst, int rank);
t_list	*best_insert(t_data *d, int lst_instr[], int (*can_push)(t_data *), int max_cost);
t_list	*best_insert_dir(t_data *d, int instr, int (*can_push)(t_data *), int max_cost);

t_list *init_instr_step_node(int instr, int nb_instr_init);
int get_steps(t_list *instr_step_node);
t_list *ft_best_comb(t_data *d, int *instr_ls, int (*can_push)(t_data *), int max_cost);
int reach_rank(t_data *data, int rank, int verbose);
void print_instr_from_int_heavy(int i);
int get_ntil(t_lnk *lst, int min, int max);

/* Liste chainée double fonctions */
void	ft_dlstclear(t_lnk **lst);
t_lnk	*ft_dlstnewdup(t_lnk *node);
t_lnk	*ft_dlstdup(t_lnk *lst);

#endif