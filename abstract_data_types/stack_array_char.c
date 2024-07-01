struct Stack_char
{
    int size;
    int top;
    char *arr;
};

static bool is_empty_char(struct Stack_char *stack){
    if(stack->top==-1){
        printf("nothing to print\n");
        return true;
    }
    return false;
}

static bool is_full_char(struct Stack_char *stack){
    if(stack->top==stack->size){
        return true;
    }
    return false;
}

int stack_array_char_stack_traverse(struct Stack_char *stack){
    if(is_empty_char(stack)){
        return -1;
    }
    for (int i=0;i<=stack->top;i++){
        printf("%c",(stack->arr)[i]);
    }
}

int stack_array_char_push(struct Stack_char *stack,char element){
    // if(is_full_char(stack)){
    //     printf("Stack_char is overflowing");
    //     return -1;
    // }
    stack->top++;
    (stack->arr)[stack->top] = element; 
}

int stack_array_char_pop(struct Stack_char *stack){
    if(is_empty_char(stack)){
        printf("Stack_char is empty");
        return -1;
    }
    stack->top--; 
}

struct Stack_char * create_stack_array_char(int size)
{
    struct Stack_char *stack = (struct Stack_char *)malloc(sizeof(stack));
    stack->size = size;
    stack->top = -1;
    stack->arr = (char *)malloc(stack->size * sizeof(char));
    return stack;
}