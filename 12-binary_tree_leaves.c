#include "binary_trees.h"
/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree:  pointer to the root node of the tree to measure the size.
 * Return: size of the tree.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t tree_leaves;

	tree_leaves = 0;
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (tree->left != NULL)
		tree_leaves += binary_tree_leaves(tree->left);
	if (tree->right != NULL)
		tree_leaves += binary_tree_leaves(tree->right);
	return (tree_leaves);
}
