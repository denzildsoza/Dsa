#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

struct Stack
{
    int size;
    int top;
    char *arr;
};



bool is_empty(struct Stack *stack){
    if(stack->top==-1){
        printf("nothing to print\n");
        return true;
    }
    return false;
}

bool is_full(struct Stack *stack){
    if(stack->top==stack->size){
        return true;
    }
    return false;
}

int stack_traverse(struct Stack *stack){
    if(is_empty(stack)){
        return -1;
    }
    for (int i=stack->top;i>-1;i--){
        printf("%d\n",(stack->arr)[i]);

    }
    return 0;
}

int push(struct Stack *stack,int element){
    // if(is_full(stack)){
    //     printf("Stack is overflowing");
    //     return -1;
    // }
    stack->top++;
    (stack->arr)[stack->top] = element; 
    return 0;
}

int pop(struct Stack *stack,char ch){
    if(is_empty(stack)){
        printf("Stack is empty");
        return -1;
    }
    printf("%c %c",(stack->arr)[stack->top],ch);
    printf("\n");
    if ((stack->arr)[stack->top]!= ch)
    {
        return -1;
    }
    stack->top--; 
    return 0;
}

int main(int argc, char const *argv[])
{
    struct Stack * stack;
    stack->size=50;
    stack->top=-1;
    stack->arr=(char *)malloc(stack->size*sizeof(char));
    char expression[100];
    printf("Enter an expression: ");
    scanf("%s",&expression);
    for(int i=0;expression[i]!='\0';i++){
        switch (expression[i])
        {
        case '(':
            push(stack,')');
            break;
        case '{':
            push(stack,'}');
            break;
        case '[':
            push(stack,']');
            break;
        case ')':
            if(pop(stack,')')==-1){
                goto invalid;
            }
            break;
        case '}':
            if(pop(stack,'}')==-1){
               goto invalid;
            }
            break;
        case ']':
            if(pop(stack,']')==-1){
               goto invalid;
            }
            break;    
        default:
            break;
        }
    }    
    
    if(stack->top>=0){
        goto invalid;
    }
    goto valid;
    invalid:    
        printf("given expression is in valid");
        return 0;
    valid:
        printf("given expression is valid");
        return 0;
    return 0;
}
