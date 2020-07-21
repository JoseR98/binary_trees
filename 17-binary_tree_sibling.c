#include "binary_trees.h"
/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: pointer to the node to find the sibling
 * Return: pointer to the sibling node.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *sibling = NULL;

	if (node == NULL || node->parent == NULL)
		return (NULL);

    if (node->parent->left != NULL)
    {
        if (node->n == node->parent->left->n)
            sibling = node->parent->right;
	}
    if (node->parent->right != NULL)
    {
        if (node->n == node->parent->right->n)
        sibling = node->parent->left;
    }
    return (sibling);
}
