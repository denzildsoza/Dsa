#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stack
{
    int size;
    int top;
    char *arr;
};

struct Node
{
    char key;
    int value;
};

struct Node ** return_precedence_table(){
    struct Node * add = (struct Node *)malloc(sizeof(add));
    add->key='+';
    add->value=2;
    struct Node * sub = (struct Node *)malloc(sizeof(add));
    sub->key='-';
    sub->value=2;
    struct Node * mul = (struct Node *)malloc(sizeof(add));
    mul->key='*';
    mul->value=1;
    struct Node * dev = (struct Node *)malloc(sizeof(dev));
    dev->key='/';
    dev->value=1;
    struct Node ** precedence_hashmap;
    precedence_hashmap = (struct Node **)malloc(4*sizeof(precedence_hashmap));
    precedence_hashmap[0]=add;
    precedence_hashmap[1]=sub;
    precedence_hashmap[2]=mul;
    precedence_hashmap[3]=dev;
    return precedence_hashmap;
}

int return_precedence(char operator){
    struct Node ** precedence=  return_precedence_table();
    for (int i = 0;i<sizeof(precedence); i++)
    {
        if((precedence[i])->key == operator){
            return (precedence[i])->value;
        }
    }
    return -1;
} 

bool is_empty(struct Stack *stack)
{
    if (stack->top == -1)
    {
        printf("nothing to print\n");
        return true;
    }
    return false;
}

bool is_full(struct Stack *stack)
{
    if (stack->top == stack->size)
    {
        return true;
    }
    return false;
}

int stack_traverse(struct Stack *stack)
{
    if (is_empty(stack))
    {
        return -1;
    }
    for (int i = stack->top; i > -1; i--)
    {
        printf("%c", (stack->arr)[i]);
    }
    return 0;
}

int push(struct Stack *stack, int element)
{
    // if(is_full(stack)){
    //     printf("Stack is overflowing");
    //     return -1;
    // }
    stack->top++;
    (stack->arr)[stack->top] = element;
    return 0;
}

int pop(struct Stack *stack, char ch)
{
    if (is_empty(stack))
    {
        printf("Stack is empty");
        return -1;
    }
    printf("%c %c", (stack->arr)[stack->top], ch);
    printf("\n");
    if ((stack->arr)[stack->top] != ch)
    {
        return -1;
    }
    stack->top--;
    return 0;
}

int main(int argc, char const *argv[])
{
    char postfix_expression[50];
    struct Stack * operators = (struct Stack *)malloc(sizeof(operators));
    operators->size = 50;
    operators->top = -1;
    operators->arr = (char *)malloc(operators->size * sizeof(char));
    char expression[100];
    printf("Enter an expression: ");
    scanf("%s", &expression);
    for (int i = 0; expression[i] != '\0'; i++)
    {
        int precedence =  return_precedence(expression[i]);
        if(precedence==-1){
            postfix_expression[i]==expression[i];
        }else{

        }
    }
    
    return 0;
}
