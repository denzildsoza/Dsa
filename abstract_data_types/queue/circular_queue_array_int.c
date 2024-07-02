#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Circular_Queue_Array_Int
{
    int size;
    int top;
    int bottom;
    int *arr;
} circular_queue_array_int;

circular_queue_array_int *create_circular_queue_array_int(int size)
{
    circular_queue_array_int *queue = (circular_queue_array_int *)malloc(sizeof(queue));
    queue->size = size;
    queue->top = -1;
    queue->bottom = -1;
    queue->arr = (int *)malloc(sizeof(queue->arr));
    return queue;
}

int circular_queue_array_int_is_empty(circular_queue_array_int *queue)
{
    if (queue->bottom == queue->top)
    {
        printf("the queue is full");
        return 1;
    }
    return 0;
}

int circular_queue_array_int_is_full(circular_queue_array_int *queue)
{
    if ((queue->bottom + 1) % queue->size == queue->top)
    {
        printf("the queue is full");
        return 1;
    }
    return 0;
}

int enqueue_circular_queue_array_int(circular_queue_array_int *queue, int element)
{
    if (circular_queue_array_int_is_full(queue))
    {
        return 0;
    }
    queue->bottom = (queue->bottom + 1) % queue->size;
    (queue->arr)[queue->bottom] = element;
}

int dequeue_circular_queue_array_int(circular_queue_array_int *queue)
{
    if (circular_queue_array_int_is_empty(queue))
    {
        return 0;
    }
    queue->top = (queue->top + 1) % queue->size;
    int element = (queue->arr)[queue->top];
    return element;
}

int traverse_push_circular_queue_array_int(circular_queue_array_int *queue)
{
    if (circular_queue_array_int_is_empty(queue))
    {
        return 0;
    }
    for (int i = queue->top + 1; i != queue->bottom + 1; i = ((i + 1) % queue->size))
    {
        printf("%d ", (queue->arr)[i]);
    }
    return 1;
}

// int main(int argc, char const *argv[])
// {
//     circular_queue_array_int *queue = create_circular_queue_array_int(50);
//     enqueue_circular_queue_array_int(queue, 10);
//     enqueue_circular_queue_array_int(queue, 20);
//     enqueue_circular_queue_array_int(queue, 30);
//     enqueue_circular_queue_array_int(queue, 40);
//     dequeue_circular_queue_array_int(queue);
//     dequeue_circular_queue_array_int(queue);
//     dequeue_circular_queue_array_int(queue);
//     enqueue_circular_queue_array_int(queue, 10);
//     enqueue_circular_queue_array_int(queue, 20);
//     traverse_push_circular_queue_array_int(queue);
//     return 0;
// }
