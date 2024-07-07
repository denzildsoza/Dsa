#include <stdlib.h>
#include <stdio.h>


typedef struct node_linked_list_int
{
    int value;
    struct node_linked_list_int *next;

} Node_linked_list_int;

Node_linked_list_int *create_node_linked_list_int(int value)
{
    Node_linked_list_int *node = (Node_linked_list_int *)malloc(sizeof(node));
    node->value = value;
    node->next = NULL;
    return node;
}

// int traverse_array_int(Array *array)
// {
//     for (int i = 0; i <= array->top; i++)
//     {
//         printf("%d ", array->arr[i]);
//     }
//     printf("\n");
// }

void reverse_linked_list_int(Node_linked_list_int * node){
    if(node!=NULL){
        reverse_linked_list_int(node->next);
        printf("%d ",node->value);
    }
    
}

int main(int argc, char const *argv[])
{
    Node_linked_list_int *head = create_node_linked_list_int(10);

    Node_linked_list_int *next1 = create_node_linked_list_int(20);
    head->next = next1;

    Node_linked_list_int *next2 = create_node_linked_list_int(30);
    next1->next = next2;

    Node_linked_list_int *next3 = create_node_linked_list_int(40);
    next2->next = next3;

    Node_linked_list_int *next4 = create_node_linked_list_int(50);
    next3->next = next4;

    Node_linked_list_int *next5 = create_node_linked_list_int(60);
    next4->next = next5;

    reverse_linked_list_int(head);

    return 0;
}
