#include <stdio.h>
#include <stdlib.h>

typedef struct Linked_Binary_Tree_Node_Int
{
    int value;
    struct Linked_Binary_Tree_Node_Int *left;
    struct Linked_Binary_Tree_Node_Int *right;
} linked_binary_tree_node_int;

linked_binary_tree_node_int *create_linked_binary_node_int(int value)
{
    linked_binary_tree_node_int *node = (linked_binary_tree_node_int *)malloc(sizeof(node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void pre_order_linked_binary_tree_traversal(linked_binary_tree_node_int *node)
{
    if (!node)
    {
        return;
    }
    printf("%d ", node->value);
    pre_order_linked_binary_tree_traversal(node->left);
    pre_order_linked_binary_tree_traversal(node->right);
}

void post_order_linked_binary_tree_traversal(linked_binary_tree_node_int *node)
{
    if (node == NULL)
    {
        return;
    }
    post_order_linked_binary_tree_traversal(node->left);
    post_order_linked_binary_tree_traversal(node->right);
    printf("%d ", node->value);
}

void in_order_linked_binary_tree_traversal(linked_binary_tree_node_int *node)
{
    if (node == NULL)
    {
        return;
    }
    in_order_linked_binary_tree_traversal(node->left);
    printf("%d ", node->value);
    in_order_linked_binary_tree_traversal(node->right);
}

int main(int argc, char const *argv[])
{
    linked_binary_tree_node_int *R = create_linked_binary_node_int(100);

    R->left = create_linked_binary_node_int(50);
    R->right = create_linked_binary_node_int(150);

    R->left->left = create_linked_binary_node_int(25);
    R->left->right = create_linked_binary_node_int(25);

    R->right->left = create_linked_binary_node_int(200);
    R->right->right = create_linked_binary_node_int(250);

    printf("Pre Ordered Traversal=> ");
    pre_order_linked_binary_tree_traversal(R);
    printf("\n");

    printf("Post Ordered Traversal=> ");
    post_order_linked_binary_tree_traversal(R);
    printf("\n");

    printf("In Ordered Traversal=> ");
    in_order_linked_binary_tree_traversal(R);
    printf("\n");

    return 0;
}
