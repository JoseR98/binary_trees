#include "binary_trees.h"
/**
 * find_root - finds the root a binary tree
 * @node: pointer to a node in the tree.
 * Return: pointer to the root of the tree.
 */
binary_tree_t *find_root(const binary_tree_t *node)
{
	while (node->parent != NULL)
		node = node->parent;
	return ((binary_tree_t *) node);
}
/**
 * ifNodeExists - Check if the given node exists in the binary tree
 * @node: pointer to node.
 * @key: value of the node.
 * Return: 1 if exist, otherwise 0.
 */
int ifNodeExists(const binary_tree_t *node, int key)
{
	int res1, res2;

	if (node == NULL)
		return (0);

	if (node->n == key)
		return (1);

	/* then recur on left sutree */
	res1 = ifNodeExists(node->left, key);

	/* now recur on right subtree */
	res2 = ifNodeExists(node->right, key);

	return (res1 || res2);
}
/**
 * samesubtree - check if two given nodes are in the same subtree
 * @root: pointer to root of the tree
 * @node1: first node value
 * @node2: second node value
 * Return: 1 if nodes are in the same subtree, otherwise 0.
 */
int samesubtree(binary_tree_t *root, int node1, int node2)
{
	if (root == NULL)
		return (0);

	/* CASE 1: If both nodes are in left subtree*/
	if (ifNodeExists(root->left, node1) && ifNodeExists(root->left, node2))
		return (1);
	/* CASE 2: If both nodes are in right subtree*/
	else if (ifNodeExists(root->right, node1) && ifNodeExists(root->right, node2))
		return (1);
	/* CASE 3 and 4: Nodes are in different subtrees*/
	else
		return (0);
}
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
	binary_tree_t *ancestor = NULL, *root;
	int base_case = 0;

	depth_first = binary_tree_depth(first);
	depth_second = binary_tree_depth(second);

	if (first == NULL && second == NULL)
		return (NULL);

	root = find_root(first);
	if ((root->left->n == first->n) && (root->right->n == second->n))
		base_case = 1;
	if ((root->left->n == second->n) && (root->right->n == first->n))
		base_case = 1;
	if (samesubtree(root, first->n, second->n) == 1 || base_case == 1)
	{
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
	}
	return (ancestor);
}
