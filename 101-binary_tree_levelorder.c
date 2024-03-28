#include "binary_trees.h"

int binary_tree_height(const binary_tree_t *tree);
void printGivenLevel(const binary_tree_t *tree, int level, void (*func)(int));

/**
 * binary_tree_levelorder - goes through a binary tree
 * using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *temp;
	int i, h;

	if (!tree || !func)
		return;
	h = binary_tree_height(tree);
	for (i = 1; i <= h; i++)
	{
		temp = tree;
		printGivenLevel(temp, i, func);
	}
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of the tree
 */
int binary_tree_height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (!tree)
		return (0);
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}

/**
 * printGivenLevel - prints nodes at a given level
 * @tree: pointer to the root node of the tree to traverse
 * @level: level to print
 * @func: pointer to a function to call for each node
 * Return: void
 */
void printGivenLevel(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (!tree)
		return;
	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		printGivenLevel(tree->left, level - 1, func);
		printGivenLevel(tree->right, level - 1, func);
	}
}
