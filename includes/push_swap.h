/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndionis <ndionis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2024/11/17 22:19:33 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <libft.h>
# include <libftprintf.h>

typedef struct s_lnk
{
	int				nb;
	int				ind;
	int				rank;
	struct s_lnk	*next;
	struct s_lnk	*prev;
}	t_lnk;

enum	e_instr
{
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
	INSTR_MAX = ss
};

char	*ft_realloc_cat(char *line, char c, int *len);
char	*get_next_line(int fd);
int		*best_insert(t_lnk *lst_a, t_lnk *lst_b);
int		*itm_insert(t_lnk *lst_a, t_lnk *lst_b);
int		can_push(t_lnk *lst_a, t_lnk *lst_b);
int		ft_no_duplicate(t_lnk *lst);
int		fucking_normi_2(char *str);
int		get_shortestway(int rank, t_lnk *lst);
int		instr_to_i(char *str);
int		is_median(t_lnk *lst_a, int max);
int		is_sorted(t_lnk *lst);
int		lst_init_ranks(t_lnk **lst);
int		special_item(t_lnk *lst_a, int max);
t_lnk	*ft_new_lnk(long int n, int i, int rank);
t_lnk	*get_args(int argc, char *argv[]);
t_lnk	*get_args_allinone(char *str);
t_lnk	*lnk_init(t_lnk *lnk);
t_lnk	*lst_cpy(t_lnk *lst);
t_lnk	*pop_item(t_lnk **lst);
void	apply_instr(int instr, t_lnk **lst_a, t_lnk **lst_b, int to_print);
void	b_dump(t_lnk **lst_a, t_lnk **lst_b);
void	del_lst(t_lnk **lst);
void	finishing(t_lnk *lst_a, t_lnk *lst_b, char *instruction);
void	fucking_norminette(int instr, t_lnk **lst_a, t_lnk **lst_b);
void	i_to_instr(int i);
void	itm_insert_loop(t_lnk *lst_a, t_lnk *lst_b, int instr, \
	int *best_result);
void	load_b(t_lnk **lst_a, t_lnk **lst_b, int max);
void	loop(t_lnk *lnk, t_lnk *l_i, int *max);
void	print_lst(t_lnk *lst, char *header);
void	print_lst_byrank(t_lnk *lst, char *header);
void	push(t_lnk **from_lst, t_lnk **to_lst);
void	push_item(t_lnk *lnk, t_lnk **lst);
void	reach_rank(t_lnk **lst, int rank, int direction);
void	rotate_lst(t_lnk **lst);
void	rrotate_lst(t_lnk **lst);
int		refresh_best_inst_steps(int *best_inst_step, int instr, int steps, \
	int	*instr_steps_itm);
void	refresh_in_dir(t_lnk *lst_a, t_lnk *lst_b, int instr, \
	int *best_inst_step);
void	select_algo(t_lnk *lst_a, t_lnk *lst_b, int ind_max);
void	sort_2_nb(t_lnk **lst_a);
void	sort_3_nb(t_lnk **lst_a, int max);
void	sort_4_nb(t_lnk **lst_a, t_lnk **lst_b);
void	sort_5_nb(t_lnk **lst_a, t_lnk **lst_b);
void	swap_lst(t_lnk **lst);

#endif
