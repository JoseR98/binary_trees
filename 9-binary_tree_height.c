#include "binary_trees.h"
/**
 * binary_tree_height -  measures the height of a binary tree
 * @tree: pointer to the root node of the tree to traverse
 * Return: 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lHeight, rHeight;

	lHeight = 0;
	rHeight = 0;
	if (tree == NULL)
	{
		return (0);
	}
	else
	{
	   /* compute the height of each subtree */
		if (tree->left != NULL)
			lHeight = 1 + binary_tree_height(tree->left);
		if (tree->right != NULL)
			rHeight = 1 + binary_tree_height(tree->right);

		/* use the larger one */
		if (lHeight >= rHeight)
			return (lHeight);
		return (rHeight);
	}
}
