#include "binary_trees.h"
/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: pointer to the node to insert the left-child in
 * @value: value to store in the new node
 * Return: pointer to the node to insert the left-child in
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_child_left, *child_left_exist;

	if (parent == NULL)
		return (NULL);
	/* when left child doesn't exists*/
	new_child_left = binary_tree_node(parent, value);
	if (parent->left == NULL)
		parent->left = new_child_left;
	else
	{
		child_left_exist = parent->left;
		parent->left = new_child_left;
		new_child_left->left = child_left_exist;
		child_left_exist->parent = new_child_left;
	}
	return (new_child_left);
}
