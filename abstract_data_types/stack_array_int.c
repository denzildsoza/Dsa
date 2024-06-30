

static struct Stack_arr
{
    int size;
    int top;
    int *arr;
};

static bool is_empty(struct Stack_arr *stack)
{
    if (stack->top == -1)
    {
        printf("nothing to print\n");
        return true;
    }
    return false;
}

static bool is_full(struct Stack_arr *stack)
{
    if (stack->top == stack->size)
    {
        return true;
    }
    return false;
}

int stack_array_int_stack_traverse(struct Stack_arr *stack)
{
    if (is_empty(stack))
    {
        return -1;
    }
    for (int i = stack->top; i > -1; i--)
    {
        printf("%d\n", (stack->arr)[i]);
    }
}

int stack_array_int_push(struct Stack_arr *stack, int element)
{
    // if(is_full(stack)){
    //     printf("Stack_arr is overflowing");
    //     return -1;
    // }
    stack->top++;
    (stack->arr)[stack->top] = element;
}

int pop(struct Stack_arr *stack)
{
    if (is_empty(stack))
    {
        printf("Stack_arr is empty");
        return -1;
    }
    stack->top--;
}

struct Stack_arr * create_stack_array_int(int size)
{
    struct Stack_arr *stack = (struct Stack_arr *)malloc(sizeof(stack));
    stack->size = size;
    stack->top = -1;
    stack->arr = (int *)malloc(stack->size * sizeof(int));
    return stack;
}