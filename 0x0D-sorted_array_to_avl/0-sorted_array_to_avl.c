#include "binary_trees.h"

/**
 * *sorted_array_to_avl - Function that builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size:  number of element in the array
 * Return: pointer to the root node of the AVL tree or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *h = NULL;
	avl_t *tree = NULL;

	if (array == NULL)
		return (NULL);
	tree = create_tree(array, 0, (int)size - 1, &h);

	if (tree == NULL)
		return (NULL);
	return (h);
}

/**
 * *create_tree - Function that builds the binary tree
 * @array: pointer to the first element of the array to be converted
 * @value_a:  number of element in the array
 * @value_b:  number of element in the array
 * @h:  node created
 * Return: pointer to the new node created
 */
avl_t *create_tree(int *array, int value_a, int value_b, avl_t **h)
{
	avl_t *left = NULL;
	avl_t *right = NULL;
	avl_t *node = NULL;
	int media_value;

	if (value_a > value_b)
		return (NULL);
	media_value = (value_a + value_b) / 2;
	create_tree(array, media_value + 1, value_b, &right);
	create_tree(array, value_a, media_value - 1, &left);
	node = malloc(sizeof(avl_t));

	if (node == NULL)
		return (NULL);
	node->n = array[media_value];
	node->parent = NULL;
	node->right = right;
	node->left = left;
	if (right != NULL)
		right->parent = node;
	if (left != NULL)
		left->parent = node;
	*h = node;
	return (node);
}
