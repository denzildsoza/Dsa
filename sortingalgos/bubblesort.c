#include <stdio.h>
#include <stdlib.h>
#include "../abstract_data_types/array/array_int.c"

int main(int argc, char const *argv[])
{
    Array *array = create_array_int(50);

    push_array_int(array, 12);
    push_array_int(array, 27);
    push_array_int(array, 2);
    push_array_int(array, 7);
    push_array_int(array, 78);
    push_array_int(array, 41);
    printf("before sorting=> ");
    traverse_array_int(array);
    for (int i = array->top; i >= 0; i--)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            if ((array->arr)[j] > (array->arr)[j + 1])
            {
                int temp = (array->arr)[j];
                (array->arr)[j] = (array->arr)[j + 1];
                (array->arr)[j + 1] = temp;
            }
        }
    }
    printf("\nafter sorting=> ");
    traverse_array_int(array);
    free(array->arr);
    free(array);
    return 0;
}
