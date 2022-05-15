/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/15 22:48:35 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void    find_solution(t_lnk **lst_a, t_lnk **lst_b)
{
	t_pstree    *root;

	root = malloc(sizeof(t_pstree));
	if (!root)
		error_msg("[find_solution] malloc error")
	root->parent = NULL;
	root->instr_node = INSTR_MIN;
	rec_parsing(root);
}

t_pstree    *make_new_bro(t_pstree *grandbro)
{
	t_pstree    *new_bro;

	new_bro = malloc(sizeof(t_pstree));
	if (!new_bro)
		error_msg("[new_bro] malloc error");
	new_bro->parent = grandbro->parent;
	new_bro->instr_node = grandbro->instr_node + 1;
	return (new_bro);
}

t_pstree    *make_new_child(t_pstree *parent)
{
	t_pstree    *new_child;

	new_child = malloc(sizeof(t_pstree));
	if (!new_child)
		error_msg("[make_new_child] malloc error");
	new_child->parent = parent;
	new_child->instr_node = INSTR_MIN;
	return (new_child);
}

t_pstree    *rec_parsing(t_pstree   *parent_node)
{
	t_pstree    *new_child;
	t_pstree    *new_bro;

	if (parent_node->instr_node == INSTR_MAX)
		parent_node->littlebro = NULL;
	else
	{
		new_bro = make_new_bro(parent_node);
		// verif list
	}
	new_child = malloc(sizeof(t_pstree));
	if (!new_child)
		error_msg("[rec_parsing] malloc error")
	parent_node->child = new_node;
	new_child->parent = parent_node;
}