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
linked_binary_tree_node_int *prev = NULL;

int is_binary_search_tree_int(linked_binary_tree_node_int *node)
{
    if (node != NULL)
    {
        is_binary_search_tree_int(node->left);
        if (prev != NULL && prev->value > node->value)
        {
            return 0;
        }
        else
            return 1;
    }
    else
    {
        return 1;
    }
}

linked_binary_tree_node_int *binary_search_tree_insertion(linked_binary_tree_node_int *root, linked_binary_tree_node_int *new_node)
{
    if (root == NULL)
    {
        return new_node;
    }
    if (root->value > new_node->value)
    {
        root->left = binary_search_tree_insertion(root->left, new_node);
        return root;
    }
    else
    {
        root->right = binary_search_tree_insertion(root->right, new_node);
        return root;
    }
}

linked_binary_tree_node_int *binary_search_tree_deletion(linked_binary_tree_node_int *root, linked_binary_tree_node_int *new_node)
{
    
}

linked_binary_tree_node_int *linked_binary_tree_node_int_print_all_leaf_nodes(linked_binary_tree_node_int *node)
{
    if (node == NULL)
    {
        return node;
    }
    linked_binary_tree_node_int *left = linked_binary_tree_node_int_print_all_leaf_nodes(node->left);
    linked_binary_tree_node_int *right = linked_binary_tree_node_int_print_all_leaf_nodes(node->right);
    if (right == NULL && left == NULL)
    {
        printf("%d ", node->value);
    }
};

int main(int argc, char const *argv[])
{
    linked_binary_tree_node_int *R = create_linked_binary_node_int(100);

    R->left = create_linked_binary_node_int(50);
    R->right = create_linked_binary_node_int(150);

    R->left->left = create_linked_binary_node_int(20);
    R->left->right = create_linked_binary_node_int(70);

    R->right->left = create_linked_binary_node_int(120);
    R->right->right = create_linked_binary_node_int(175);

    printf("Pre Ordered Traversal=> ");
    pre_order_linked_binary_tree_traversal(R);
    printf("\n");

    printf("Post Ordered Traversal=> ");
    post_order_linked_binary_tree_traversal(R);
    printf("\n");

    printf("In Ordered Traversal=> ");
    in_order_linked_binary_tree_traversal(R);
    printf("\n");

    linked_binary_tree_node_int *new_node = create_linked_binary_node_int(150);

    linked_binary_tree_node_int *new_root = binary_search_tree_deletion(R, new_node);

    // int is_B_S_T = is_binary_search_tree_int(new_root);
    // if (is_B_S_T)
    // {
    //     printf("its a binary tree");
    // }
    // else
    // {
    //     printf("its not a binary tree");
    // }
    printf("In Ordered Traversal=> ");
    in_order_linked_binary_tree_traversal(new_root);
    printf("\n");

    // linked_binary_tree_node_int_print_all_leaf_nodes(R);
    return 0;
}
