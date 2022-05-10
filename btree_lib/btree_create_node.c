#include <btree.h>
#include <push_swap.h>

t_btree	*btree_create_node(void *item)
{
	t_btree	*new_node;

	new_node = malloc(sizeof(t_btree));
	if (!new_node)
		error_msg("error creating a new node");
	new_node->item = item;
	new_node->right = NULL;
	new_node->left = NULL;
	new_node->parent = NULL;
	return (new_node);
}
