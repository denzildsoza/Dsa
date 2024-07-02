
typedef struct Queue_Array_Int
{
    int size;
    int top;
    int bottom;
    int *arr;
} Queue_array_int;

Queue_array_int *create_Queue_array_int(int size)
{
    Queue_array_int *queue_array_int = (Queue_array_int *)malloc(sizeof(queue_array_int));
    queue_array_int->size = size;
    queue_array_int->top = -1;
    queue_array_int->bottom = -1;
    queue_array_int->arr = (int *)malloc(sizeof(queue_array_int->arr));
}

int Queue_array_int__isempty(Queue_array_int *queue)
{
    if (queue->top == queue->bottom)
    {
        printf("queue is empty\n");
        return 1;
    }
    return 0;
}

int Queue_array_int__isfull(Queue_array_int *queue)
{
    if (queue->top > queue->size - 1)
    {
        printf("queue is full\n");
        return 1;
    }
    return 0;
}

int enqueue_Queue_array_int(Queue_array_int *queue, int element)
{
    if (Queue_array_int__isfull(queue))
    {
        return 0;
    }
    queue->bottom++;
    (queue->arr)[queue->bottom] = element;
    return 1;
}

int dequeue_Queue_array_int(Queue_array_int *queue)
{
    if (Queue_array_int__isempty(queue))
    {
        return 0;
    }
    int a = (queue->arr)[queue->top];
    queue->top++;
    return a;
}

int traverse_Queue_array_int(Queue_array_int *queue)
{
    if (Queue_array_int__isempty(queue))
    {
        return 0;
    }
    for (int i = queue->top + 1; i <= queue->bottom; i++)
    {
        printf("%d ", (queue->arr)[i]);
    }
    return 1;
}

peak_top_Queue_array_int(Queue_array_int *queue){
    return queue->top;
}

peak_bottom_Queue_array_int(Queue_array_int *queue){
    return queue->bottom;
}

// int main(int argc, char const *argv[])
// {
//     Queue_array_int *queue = create_Queue_array_int(50);
//     enqueue_Queue_array_int(queue, 10);
//     enqueue_Queue_array_int(queue, 20);
//     enqueue_Queue_array_int(queue, 30);
//     enqueue_Queue_array_int(queue, 40);
//     enqueue_Queue_array_int(queue, 50);
//     traverse_Queue_array_int(queue);
//     return 0;
// }
