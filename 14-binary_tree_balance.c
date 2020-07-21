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
		lHeight = 1 + binary_tree_height(tree->left);
		rHeight = 1 + binary_tree_height(tree->right);

		/* use the larger one */
		if (lHeight >= rHeight)
			return (lHeight);
		return (rHeight);
	}
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance.
 * Return: balance factor of the tree.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int lHeight, rHeight;

	lHeight = 0;
	rHeight = 0;
	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		/* compute the height of each subtree */
			lHeight = binary_tree_height(tree->left);
			rHeight = binary_tree_height(tree->right);
			return (lHeight - rHeight);
	}
}
