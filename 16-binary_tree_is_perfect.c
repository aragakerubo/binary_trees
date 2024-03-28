#include "binary_trees.h"

int binary_tree_height_2(const binary_tree_t *tree);

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

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if perfect, 0 if not perfect or NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (binary_tree_height_2(tree->left) != binary_tree_height_2(tree->right))
		return (0);
	if (tree->left && tree->right)
		return (
		    binary_tree_is_perfect(tree->left) &&
		    binary_tree_is_perfect(tree->right));
	return (0);
}
