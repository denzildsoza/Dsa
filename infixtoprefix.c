#include "headers.h"
#include "abstract_data_types/stack_array_char.c"
#include "abstract_data_types/stack_array_int.c"
#include "abstract_data_types/stack_array_pointer_struct.c"

struct Stack_arr_ptr_struct_node *get_precedence_table()
{
    struct Stack_arr_ptr_struct_node *Stack_arr_ptr_struct = create_stack_array_pointer_struct(50);
    struct Node *add = create_Node('+', 1);
    struct Node *min = create_Node('-', 1);
    struct Node *mul = create_Node('*', 2);
    struct Node *divi = create_Node('/', 2);
    stack_array_pointer_struct_push(Stack_arr_ptr_struct, add);
    stack_array_pointer_struct_push(Stack_arr_ptr_struct, min);
    stack_array_pointer_struct_push(Stack_arr_ptr_struct, mul);
    stack_array_pointer_struct_push(Stack_arr_ptr_struct, divi);
    return Stack_arr_ptr_struct;
}

int get_precedence(struct Stack_arr_ptr_struct_node *precedence_table, char operator)
{

    // printf("\ntop=>  %d ",precedence_table->top);
    // printf("\n");
    // stack_array_pointer_struct_stack_traverse(precedence_table);
    for (int i = 0; i < precedence_table->top; i++)
    {
        if ((precedence_table->arr)[i]->key == operator)
        {
            return (precedence_table->arr)[i]->value;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    char expression[50];
    struct Stack_char *postfix_expression = create_stack_array_char(50);
    struct Stack_arr_ptr_struct_node *operatorsstack = create_stack_array_pointer_struct(20);

    struct Stack_arr_ptr_struct_node *precedence_table = get_precedence_table();
    printf("Enter an expression: ");
    scanf("%s", &expression);

    for (int i = 0; expression[i] != '\0'; i++)
    {
        int precedence = get_precedence(precedence_table, expression[i]);
        if (precedence == -1)
        {
            stack_array_char_push(postfix_expression, expression[i]);
        }
        else
        {
            if (operatorsstack->top == -1)
            {
                struct Node *node = create_Node(expression[i], precedence);
                stack_array_pointer_struct_push(operatorsstack, node);
            }
            else
            {
                struct Node *top = stack_array_pointer_struct_peek(operatorsstack);

                if (top->value < precedence)
                {
                    struct Node *node = create_Node(expression[i], precedence);
                    stack_array_pointer_struct_push(operatorsstack, node);
                }
                else
                {
                    for (int i = operatorsstack->top; i > -1; i--)
                    {
                        stack_array_char_push(postfix_expression, (operatorsstack->arr)[i]->key);
                        stack_array_pointer_struct_pop(operatorsstack);
                    }
                    struct Node *node = create_Node(expression[i], precedence);
                    stack_array_pointer_struct_push(operatorsstack, node);
                                }
            }
        }
    }
    if (operatorsstack->top != -1)
    {
        for (int i = operatorsstack->top; i > -1; i--)
        {
            stack_array_char_push(postfix_expression, (operatorsstack->arr)[i]->key);
            stack_array_pointer_struct_pop(operatorsstack);
        }
    }
    printf("\n");
    stack_array_char_stack_traverse(postfix_expression);
    return 0;
}