#include "binary_trees.h"
/**
 * binary_tree_preorder - goes through a binary tree using pre-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 * Return: void
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != NULL && func != NULL)
	{
	 /* print data of parent node */
		func(tree->n);
	 /* then recur on left subtree */
		binary_tree_preorder(tree->left, func);
	/* now recur on right subtree */
		binary_tree_preorder(tree->right, func);
	}
}
