#include "binary_trees.h"

/**
 * binary_tree_node - Extracts the root node of a max binary heap
 * @parent: parent node of the node to create
 * @value: value to put in the new node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *node = malloc(sizeof(binary_tree_t));

    if (node == NULL)
        return (NULL);

    node->parent = parent;
    node->n = value;
    node->left = NULL;
    node->right = NULL;

    return (node);
}
