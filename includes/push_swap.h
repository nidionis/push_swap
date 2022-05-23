/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/23 13:40:25 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <libft.h>
# include <libftprintf.h>

typedef struct s_lnk
{
	int	nb;
	int	ind;
	int	rank;
	struct s_lnk	*next;
	struct s_lnk	*init_next;
	struct s_lnk	*prev;
	struct s_lnk	*init_prev;
}	t_lnk;

enum	e_instr { INSTR_MIN = 1, sa = INSTR_MIN, sb, pa, pb, ra, rb, rra, rrb, rr, rrr, ss, INSTR_MAX = ss };

typedef struct s_pstree
{
	int				instr_node;
	struct s_pstree	*parent;
	struct s_pstree *childs[INSTR_MAX];
}	t_pstree;

void	print_lst(t_lnk *lst, char *header);
t_lnk	*lnk_init(t_lnk *lnk);
t_lnk	*ft_new_lnk(int nb, int ind, int rank);
void	push_item(t_lnk *lnk, t_lnk **lst);
t_lnk	*get_args(int argc, char *argv[]);
void	del_lst(t_lnk **lst);
t_lnk	*pop_item(t_lnk **lst);
void	rotate_lst(t_lnk **lst);
void	rrotate_lst(t_lnk **lst);
t_lnk	*new_instr_lnk(char *instr);
void	push(t_lnk **from_lst, t_lnk **to_lst);
int		lst_init_ranks(t_lnk **lst);
void	print_lst_byrank(t_lnk *lst, char *header);
t_lnk	*get_args_allinone(char *str);
int 	ft_is_sorted(t_lnk *lst);
int 	is_sorted(t_lnk *lst);
void	swap_lst(t_lnk **lst);
void	apply_instr(int instr, t_lnk **lst_a, t_lnk **lst_b, int to_print);
char	*get_next_line(int fd);
int		instr_to_i(char *str);
int		ft_no_duplicate(t_lnk *lst);
void	i_to_instr(int i);
void	reach_rank(t_lnk **lst, int rank, int direction);
//void	sort_push(t_lnk	**lst_a, t_lnk **lst_b, int ind_max);
//void	set_initial_pointers(t_lnk **lst);
//void	reset_initial_pointers(t_lnk **lst_a);
//void	reachsort_step(t_lnk **lst, int ascend, int way, char lst_name);
int	get_shortestway(int rank, t_lnk *lst);
t_lnk	**reach_push(t_lnk **lst_a, t_lnk **lst_b, int rank, int instr_way, t_lnk *relMinMax[2]);
t_lnk	**parse_down(t_lnk **lst_a, t_lnk **lst_b, t_lnk	*relMinMax[2]);
//void	first_parse(t_lnk	**lst_a, t_lnk	**lst_b, int ind_max);
//int		push_return_rank(t_lnk **lst_a, t_lnk **lst_b);
//void	first_dump_relMax(t_lnk **lst_a, t_lnk **lst_b, int rank_max);
//t_lnk	**first_parse(t_lnk	**lst_a, t_lnk	**lst_b, int ind_maxi, t_lnk *relMinMax[2]);
//t_lnk	*get_RelMax(t_lnk *lst, int rankMax);
//t_lnk	*get_RelMin(t_lnk *lst);
//t_lnk	*refresh_RelMax(t_lnk *relMax);
//t_lnk	*refresh_RelMin(t_lnk *relMin);
//t_lnk	**refresh_RelMinMax(t_lnk **relMinMax);
//void	dump_relMax(t_lnk **lst_a, t_lnk **lst_b, t_lnk **relMinMax);
//void	dump_relMin(t_lnk **lst_a, t_lnk **lst_b);
//int contains_only_higher(t_lnk *lst, int rank);
//int	step_counter(int rank, t_lnk *lst, int rev_rotate);
void	push_reachwise_relMin(t_lnk **lst_a, t_lnk **lst_b, int *relMin);
t_lnk **recentrer(t_lnk **lst_a, t_lnk **relMinMax);

int	can_insert(t_lnk *lst_a, t_lnk *lst_b, t_lnk *brelMax);
int	b_insert(t_lnk **lst_a, t_lnk **lst_b, t_lnk *brelMax, int print);
//t_lnk	*smart_load_loop(t_lnk **lst_a, t_lnk **lst_b, int way_instr, int nb_raMax, t_lnk *brelMax);
//void rec_median_split(t_lnk **lst, t_lnk **lst_loaded, int *relMinMax, int is_lst_b);
//int median_split(t_lnk **lst, t_lnk **lst_loaded, int *relMinMax, int is_lst_b);
//void first_load(t_lnk **lst_a, t_lnk **lst_b, int ind_max);
void first_load(t_lnk **lst_a, t_lnk **lst_b, int max);
void    b_dump(t_lnk **lst_a, t_lnk **lst_b);
void	reach_rank(t_lnk **lst, int rank, int direction);
int	get_shortestway(int rank, t_lnk *lst);


//
//void    find_solution(t_lnk *lst_a, t_lnk *lst_b);
//void    make_new_bro(t_pstree *grandbro);
//void    make_new_child(t_pstree *parent);
//int		check_instr(t_pstree *node, t_lnk *lst_a, t_lnk *lst_b);
//void	print_seq(t_pstree *node);
//void    familly_parsing(t_pstree *parent_node, t_lnk *lst_a, t_lnk *lst_b);

#endif