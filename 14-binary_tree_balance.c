#include "binary_trees.h"

int binary_tree_height_2(const binary_tree_t *tree);

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: balance factor of the tree, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (!tree)
		return (0);
	left_height = binary_tree_height_2(tree->left);
	right_height = binary_tree_height_2(tree->right);
	return (left_height - right_height);
}

/**
 * binary_tree_height_2 - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of the tree, or 0 if tree is NULL
 */
int binary_tree_height_2(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (!tree)
		return (0);
	left_height = binary_tree_height_2(tree->left);
	right_height = binary_tree_height_2(tree->right);
	if (left_height > right_height)
		return (left_height + 1);
	return (right_height + 1);
}
