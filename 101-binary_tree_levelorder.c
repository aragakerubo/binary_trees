#include "binary_trees.h"

/**
 * binary_tree_levelorder - goes through a binary tree using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_t *queue[100];
	int front = 0, rear = 0;

	queue[rear] = (binary_tree_t *)tree;
	rear++;

	while (front < rear)
	{
		binary_tree_t *current = queue[front];
		front++;

		func(current->n);

		if (current->left)
		{
			queue[rear] = current->left;
			rear++;
		}
		if (current->right)
		{
			queue[rear] = current->right;
			rear++;
		}
	}
}
