#include "binary_trees.h"
/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: common ancestor if finded, otherwise NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	binary_tree_t *temp;
	binary_tree_t *ancestor = NULL;

	if (first == NULL && second == NULL)
		return (NULL);

	while (first != NULL)
	{
		temp = (binary_tree_t *) second;
		while (temp != NULL)
		{
			if (first->n == temp->n)
				ancestor = (binary_tree_t *) first;
			temp = temp->parent;
		}
		if (ancestor != NULL)
			break;
		first = first->parent;
	}
	return (ancestor);
}
