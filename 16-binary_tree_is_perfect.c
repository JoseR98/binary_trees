#include "binary_trees.h"
/**
 * binary_tree_height - measures the height of a binary tree
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
		/* return the number of nodes of each subtree */
		return (lHeight + rHeight);
	}
}
/**
 * binary_tree_is_perfect - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if is full, otherwise 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left, right;

	if (!tree)
		return (0);

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	if (left != right)
		return (0);
	return (1);
}
