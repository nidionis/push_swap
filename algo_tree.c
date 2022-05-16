/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/16 15:10:41 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void    find_solution(t_lnk *lst_a, t_lnk *lst_b)
{
	t_pstree    *root;

	root = malloc(sizeof(t_pstree));
	if (!root)
		error_msg("[find_solution] malloc error");
	root->parent = NULL;
	root->instr_node = INSTR_MIN;
	familly_parsing(root, lst_a, lst_b);
}

/*
void    make_new_bro(t_pstree *grandbro)
{
	t_pstree    *new_bro;

	new_bro = malloc(sizeof(t_pstree));
	if (!new_bro)
		error_msg("[new_bro] malloc error");
	new_bro->parent = grandbro->parent;
	new_bro->instr_node = grandbro->instr_node + 1;
	new_bro->child = NULL;
	new_bro->littlebro = NULL;
	grandbro->littlebro = new_bro;
}
*/

void    make_new_node(t_pstree *parent, int instr)
{
	t_pstree    *new_child;

	new_child = malloc(sizeof(t_pstree));
	if (!new_child)
		error_msg("[make_new_node] malloc error");
	new_child->parent = parent;
	new_child->instr_node = instr;
	(parent->childs)[instr] = new_child;
}

int	check_instr(t_pstree *node, t_lnk *lst_a, t_lnk *lst_b)
{
	int		good_seq;
	t_lnk	*lst_a_init;

	lst_a_init = lst_a;
	good_seq = 0;
	while (node)
	{
		apply_instr(node->instr_node, &lst_a, &lst_b, NULL);
		node = node->parent;
	}
	if (!(lst_b) && ft_is_sorted(lst_a) == 1)
		good_seq = 1;
	reset_initial_pointers(&lst_a_init);
	return (good_seq);
}

void	print_seq(t_pstree *node)
{
	while (node)
	{
		i_to_instr(node->instr_node);
		node = node->parent;
	}
}

void	rec_familly_parsing(t_pstree *parent_node, t_lnk *lst_a, t_lnk *lst_b)
{
	int i_instr;

	i_instr = INSTR_MIN;
	while(i_instr <= INSTR_MAX)
		familly_parsing((parent_node->childs)[i_instr++], lst_a, lst_b);
}

void    familly_parsing(t_pstree *parent_node, t_lnk *lst_a, t_lnk *lst_b)
{
	int i_instr;

	i_instr = INSTR_MIN;
	while(i_instr <= INSTR_MAX)
	{
		make_new_node(parent_node, i_instr);
		if (check_instr((parent_node->childs)[i_instr], lst_a, lst_b))
		{
			print_seq((parent_node->childs)[i_instr]);
			exit(1);
		}
		rec_familly_parsing()
		i_instr++;
	}

}