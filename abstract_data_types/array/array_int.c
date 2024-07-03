typedef struct array
{
    int size;
    int top;
    int *arr;
} Array;

Array *create_array_int(int size)
{
    Array *array = (Array *)malloc(sizeof(array));
    array->size = size;
    array->top = -1;
    array->arr = (int *)malloc(sizeof(size));
    return array;
}

void push_array_int(Array *array, int element)
{
    array->top++;
    (array->arr)[array->top] = element;
}

int traverse_array_int(Array *array)
{
    for (int i = 0; i <= array->top; i++)
    {
        printf("%d ", array->arr[i]);
    }
    printf("\n");
}