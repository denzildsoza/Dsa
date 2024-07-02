#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue_Stack_Node
{
    int value;
    struct Queue_Stack_Node *ptr;
} queue_stack_node;

typedef struct Queue_Stack_Int
{
    queue_stack_node *front;
    queue_stack_node *rear;

} queue_stack_int;

queue_stack_node *create_queue_node(int value)
{
    queue_stack_node *node = (queue_stack_node *)malloc(sizeof(node));
    if (!node)
    {
        printf("could not allocate memory for node");
        exit(0);
    }
    node->ptr = NULL;
    node->value = value;
    return node;
}

queue_stack_int *create_queue_stack_int()
{
    queue_stack_int *queue = (queue_stack_int *)malloc(sizeof(queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue_queue_stack_int(queue_stack_int *queue, int value)
{
    queue_stack_node *node = create_queue_node(value);
    if (queue->front == NULL)
    {
        queue->front = node;
        queue->rear = node;
    }
    else
    {
        queue->rear->ptr = node;
        queue->rear = node;
    }
}

int dequeue_queue_stack_int(queue_stack_int *queue)
{
    if (queue->front == NULL)
    {
        printf("Queue is empty");
        return 0;
    }
    queue_stack_node *front = queue->front;
    int value = front->value;
    queue->front = front->ptr;
    free(front);
    return value;
}

int traverse_queue_stack_int(queue_stack_int *queue)
{
    if (queue->front == NULL)
    {
        printf("queue is empty");
        return 0;
    }
    queue_stack_node *front = queue->front;
    printf("%d ", front->value);
    while (front->ptr != NULL)
    {
        front = front->ptr;
        printf("%d ", front->value);
    }

    printf("\n");
    return 1;
}

int main(int argc, char const *argv[])
{
    queue_stack_int *queue = create_queue_stack_int();
    enqueue_queue_stack_int(queue, 10);
    traverse_queue_stack_int(queue);
    return 0;
}
