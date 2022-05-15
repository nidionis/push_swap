/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/15 21:02:08 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <libft.h>
# include <libftprintf.h>
# include <linked_lst.h>

typedef struct s_lnk_itm
{
	int	nb;
	int	ind;
	int	rank;
}	t_itm;

typedef struct s_instr
{
	char	instr[4];
}	t_instr;

typedef struct s_lnk
{
	void		*itm;
	struct s_lnk	*next;
	struct s_lnk	*init_next;
	struct s_lnk	*prev;
	struct s_lnk	*init_prev;
}	t_lnk;

typedef struct	s_pstree
{
	int	instr_node;
	struct s_pstree *parent;
	struct s_pstree *right;
	struct s_pstree *left;
}	t_pstree;

enum instr { INSTR_MIN = 1, sa = INSTR_MIN, sb, pa, pb, ra, rb, rra, rrb, rr, rrr, ss, INSTR_MAX };

void	print_lst(t_lnk *lst, char *header);
t_lnk	*lnk_init(t_lnk *lnk);
t_lnk	*ft_new_lnk(int nb, int ind, int rank);
void	push_item(t_lnk *lnk, t_lnk **lst);
t_lnk	*get_args(int argc, char *argv[]);
void	del_lst(t_lnk **lst);
t_lnk	*pop_item(t_lnk **lst);
void    rotate_lst(t_lnk **lst);
void    rrotate_lst(t_lnk **lst);
t_lnk	*new_instr_lnk(char *instr);
void	push(t_lnk **from_lst, t_lnk **to_lst);
int		lst_init_ranks(t_lnk **lst);
void	print_lst_byrank(t_lnk *lst, char *header);
t_lnk	*get_args_allinone(char *str);
int 	ft_is_sorted(t_lnk *lst);
void	swap_lst(t_lnk **lst);
void	apply_instr(int instr, t_lnk **lst_a, t_lnk **lst_b, t_lnk **instr_lst);
char	*get_next_line(int fd);
int		instr_to_i(char *str);
int ft_no_duplicate(t_lnk *lst);
void i_to_instr(int i);
void	set_initial_pointers(t_lnk **lst);
void	reset_initial_pointers(t_lnk **lst_a, t_lnk **lst_b);

#endif