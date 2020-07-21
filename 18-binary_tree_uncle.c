#include "binary_trees.h"
/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to the node to find the sibling
 * Return: pointer to the sibling node.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *uncle = NULL;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent->parent != NULL)
	{
		if (node->parent->parent->left != NULL)
		{
			if (node->parent->n == node->parent->parent->left->n)
				uncle = node->parent->parent->right;
		}
		if (node->parent->parent->right != NULL)
		{
			if (node->parent->n == node->parent->parent->right->n)
				uncle = node->parent->parent->left;
		}
	}
	return (uncle);
}
