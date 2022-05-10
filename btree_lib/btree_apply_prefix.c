#include <btree.h>
#include <push_swap.h>

t_btree	*rec_apply_prefix(t_btree *node, void (*applyf)(void *))
{
	if (node)
		(*applyf)(node->item);
}

void	btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	return (0);
}
