#include "binary_trees.h"
/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 * Return: depth of the node - if tree == NULL 0.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
		return (0);
	tree = tree->parent;
	while (tree)
	{
		depth = depth + 1;
		tree = tree->parent;
	}
	return (depth);
}
/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: common ancestor if finded, otherwise NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	size_t depth_first, depth_second;
	binary_tree_t *ancestor = NULL;

	depth_first = binary_tree_depth(first);
	depth_second = binary_tree_depth(second);

	if (first == NULL && second == NULL)
		return (NULL);

	if (depth_first < depth_second)
	{
		if (second->parent == first)
			ancestor = (binary_tree_t *) first;
		else
			ancestor = (binary_tree_t *) first->parent;
	}
	else if (depth_second < depth_first)
	{
		if (first->parent == second)
			ancestor = (binary_tree_t *) second;
		else
			ancestor = (binary_tree_t *) second->parent;
	}
	else if (depth_first == depth_second)
	{
		if (first->parent == second->parent)
			ancestor = (binary_tree_t *) first->parent;
		else
			ancestor = NULL;
	}
	return (ancestor);
}
