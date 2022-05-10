/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:28:11 by supersko          #+#    #+#             */
/*   Updated: 2022/05/10 16:44:54 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTREE_H
# define BTREE_H
# include <libft.h>

typedef struct	s_btree
{
	void			*item;
	struct s_btree	*right;
	struct s_btree	*left;
	struct s_btree	*parent;
}	t_btree;

t_btree	*btree_create_node(void *item);

#endif
