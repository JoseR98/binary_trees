#include "binary_trees.h"
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
		if (tree->left != NULL)
			lHeight = 1 + binary_tree_balance(tree->left);
		if (tree->right != NULL)
			rHeight = 1 + binary_tree_balance(tree->right);
		return (lHeight - rHeight);
	}
}
