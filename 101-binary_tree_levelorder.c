#include "binary_trees.h"
/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: if tree is NULL return 0 else return the height of a binary tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left = 0;
	size_t right = 0;

	if (tree == NULL)
		return (0);

	left = 1 + binary_tree_height(tree->left);
	right = 1 + binary_tree_height(tree->right);

	if (left >= right)
		return (left);
	else
		return (right);
}
/**
* currentlevel - print each level
* @tree: tree to print
* @level: level to print
* @func: print function
*/
void level_line(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (!tree)
		return;

	if (level == 1)
	{
		func(tree->n);
	}
	else if (level > 1)
	{
		level_line(tree->left, level - 1, func);
		level_line(tree->right, level - 1, func);
	}
}
/**
 * binary_tree_levelorder - function that goes through a binary tree using level-order traversal
 * @tree: tree is a pointer to the root node of the tree to traverse
 * @func: func is a pointer to a function to call for each node.
 * Return: nothing.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{

	int height, i;

	if (!tree || !func)
		return;
	height = binary_tree_height(tree);

	for (i = 1; i <= height; i++)
	{
		level_line(tree, i, func);
	}
}
