

static struct Stack_arr_ptr_struct_node
{
    int size;
    int top;
    struct Node **arr;
};

static struct Node
{
    char key;
    int value;
};

static bool is_empty_arr_ptr_struct(struct Stack_arr_ptr_struct_node *stack){
    if(stack->top==-1){
        printf("nothing to print\n");
        return true;
    }
    return false;
}

static bool is_full_arr_ptr_struct(struct Stack_arr_ptr_struct_node *stack){  
    if(stack->top==stack->size){
        return true;
    }
    return false;
}

int stack_array_pointer_struct_stack_traverse(struct Stack_arr_ptr_struct_node *stack){
    if(is_empty_arr_ptr_struct(stack)){
        return -1;
    }
    for (int i=stack->top;i>-1;i--){
        printf("%c :",(stack->arr)[i]->key);
        printf(" %d ,\n",(stack->arr)[i]->value);
    }
}

int stack_array_pointer_struct_push(struct Stack_arr_ptr_struct_node *stack,struct Node * element){
    // if(is_full_arr_ptr_struct(stack)){
    //     printf("Stack_arr_ptr_struct_node is overflowing");
    //     return -1;
    // }
    stack->top++;
    (stack->arr)[stack->top] = element; 
}

int stack_array_pointer_struct_pop(struct Stack_arr_ptr_struct_node *stack){
    if(is_empty_arr_ptr_struct(stack)){
        printf("Stack_arr_ptr_struct_node is empty");
        return -1;
    }
    stack->top--; 
}

struct Node * stack_array_pointer_struct_peek(struct Stack_arr_ptr_struct_node *stack){
    if(is_empty_arr_ptr_struct(stack)){
        printf("Stack_arr_ptr_struct_node is empty");
    }
    return (stack->arr)[stack->top]; 
}

struct Stack_arr_ptr_struct_node * create_stack_array_pointer_struct(int size)
{
    struct Stack_arr_ptr_struct_node * stack = (struct Stack_arr_ptr_struct_node *)malloc(sizeof(stack));
    stack->size = size;
    stack->top = -1;
    stack->arr = (struct Node **)malloc(stack->size * sizeof(stack->arr));
    return stack;
}

struct Node * create_Node(char key,int value)
{
    struct Node * node = (struct Node *)malloc(sizeof(node));
    node->key=key;
    node->value=value;
    return node;
}