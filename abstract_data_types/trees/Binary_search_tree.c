#include <stdio.h>
#include <stdlib.h>
#include "./Linked_Binary_Tree_Int.c"

linked_binary_tree_node_int *prev = NULL;

int is_tree_binary_search_tree(linked_binary_tree_node_int *node)
{
    if (node != NULL)
    {
        if (!is_tree_binary_search_tree(node->left))
        {
            return 0;
        }
        if (prev != NULL && prev->value > node->value)
        {
            return 0;
        }
        prev = node;
        return is_tree_binary_search_tree(node->right);
    }
    else
    {
        return 1;
    }
}

int main(int argc, char const *argv[])
{
    linked_binary_tree_node_int *R = create_linked_binary_node_int(100);

    R->left = create_linked_binary_node_int(50);
    R->right = create_linked_binary_node_int(150);

    R->left->left = create_linked_binary_node_int(30);
    R->left->right = create_linked_binary_node_int(60);

    // R->right->left = create_linked_binary_node_int(130);
    R->right->left = create_linked_binary_node_int(1890);
    R->right->right = create_linked_binary_node_int(170);

    printf("Pre Ordered Traversal=> ");
    pre_order_linked_binary_tree_traversal(R);
    printf("\n");

    printf("Post Ordered Traversal=> ");
    post_order_linked_binary_tree_traversal(R);
    printf("\n");

    printf("In Ordered Traversal=> ");
    in_order_linked_binary_tree_traversal(R);
    printf("\n");

    printf("Is given tree a binary tree=> ");
    if (is_tree_binary_search_tree(R))
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
    printf("\n");

    return 0;
}
