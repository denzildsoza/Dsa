#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

struct Stack
{
    int size;
    int top;
    int *arr;
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
}

int push(struct Stack *stack,int element){
    // if(is_full(stack)){
    //     printf("Stack is overflowing");
    //     return -1;
    // }
    stack->top++;
    (stack->arr)[stack->top] = element; 
}

int pop(struct Stack *stack){
    if(is_empty(stack)){
        printf("Stack is empty");
        return -1;
    }
    stack->top--; 
}

int main (){
    struct Stack *stack;
    stack->size=5;
    stack->top=-1;
    stack->arr = (int*)malloc(stack->size*sizeof(int));
    push(stack,10);
    push(stack,20);
    push(stack,30);
    push(stack,40);
    push(stack,50);
    push(stack,60);
    push(stack,70);
    push(stack,80);
    stack_traverse(stack);
    return 0;
}