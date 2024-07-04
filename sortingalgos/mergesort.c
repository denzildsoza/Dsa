#include <stdio.h>
#include <stdlib.h>
#include "../abstract_data_types/array/array_int.c"

int main(int argc, char const *argv[])
{
    int i, j = 0;

    Array *array1 = create_array_int(50);
    Array *array2 = create_array_int(50);

    push_array_int(array1, 2);
    push_array_int(array1, 7);
    push_array_int(array1, 12);
    push_array_int(array1, 27);
    push_array_int(array1, 41);
    push_array_int(array1, 78);

    push_array_int(array2, 5);
    push_array_int(array2, 8);
    push_array_int(array2, 12);
    push_array_int(array2, 12);

    int resultant_array_size = array1->top + array2->top;
    Array *array3 = create_array_int(resultant_array_size);

    // printf("before sorting=> ");
    // traverse_array_int(array);

    /*logic_start*/
    for (int k = 0; k <= resultant_array_size; k++)
    {
        printf("k=> %d", k);
        if ((array1->arr)[i] <= (array2->arr)[j])
        {
            push_array_int(array3, (array1->arr)[i]);
            i++;
            if (i > array1->top)
            {
                for (int a = j; a <= array2->top; a++)
                {
                    push_array_int(array3, (array2->arr)[a]);
                }
                break;
            }
        }
        else if ((array1->arr)[i] > (array2->arr)[j])
        {
            push_array_int(array3, (array2->arr)[j]);
            j++;
            if (j > array2->top)
            {
                for (int b = i; b <= array1->top; b++)
                {
                    push_array_int(array3, (array1->arr)[b]);
                }
                break;
            }
        }
    }
    /*logic_end_*/

    printf("\nafter sorting=> ");
    traverse_array_int(array3);
    free(array1->arr);
    free(array1);
    free(array2->arr);
    free(array2);
    free(array3->arr);
    free(array3);
    return 0;
}
