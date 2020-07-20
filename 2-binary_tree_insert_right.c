#include "binary_trees.h"
/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: pointer to the node to insert the right-child in
 * @value: value to store in the new node
 * Return: pointer to the node to insert the right-child in
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_child_right, *child_rifht_exist;

	if (parent == NULL)
		return (NULL);
	/* when left child doesn't exists*/
	new_child_right = binary_tree_node(parent, value);
	if (parent->right == NULL)
		parent->right = new_child_right;
	else
	{
		child_rifht_exist = parent->right;
		parent->right = new_child_right;
		new_child_right->right = child_rifht_exist;
		child_rifht_exist->parent = new_child_right;
	}
	return (new_child_right);
}
