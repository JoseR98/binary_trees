#include "binary_trees.h"
/**
 * binary_tree_delete - function that deletes an entire binary tree
 * @tree: pointer to the root node of the tree to delete
 * Return: void
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree)
	{
		deleteTree(tree);
		free(tree);
	}
}
/**
 * deleteTree - makes recursion to delete all nodes of the tree
 * @node: Reference to the node.
 * Return: nothing
 */
void deleteTree(binary_tree_t *node)
{
	if (node->left)
	{
		deleteTree(node->left);
		free(node->left);
	}
	if (node->right)
	{
		deleteTree(node->right);
		free(node->right);
	}
}
