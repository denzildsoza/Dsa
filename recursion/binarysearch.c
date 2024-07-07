#include <stdio.h>
#include <stdlib.h>
#include "../abstract_data_types/array/array_int.c"

int mid;
int binary_search(int *array, int top, int bottom, int ele)
{
    if (top > bottom)
    {
        return -1;
    }
    mid = (top + bottom) / 2;
    if (array[mid] == ele)
    {
        return mid + 1;
    }
    if (array[mid]< ele)
    {
        return binary_search(array, mid + 1, bottom, ele);
    }
    return binary_search(array, top, mid - 1, ele);
}

int binary_search_recursion(Array *array, int element)
{
    int top = 0;
    int bottom = array->top;
    int pos = binary_search(array->arr, top, bottom, element);

    return pos;
}

int main(int argc, char const *argv[])
{
    Array *array = create_array_int(50);

    push_array_int(array, 2);
    push_array_int(array, 5);
    push_array_int(array, 8);
    push_array_int(array, 17);
    push_array_int(array, 37);
    push_array_int(array, 41);

    int pos = binary_search_recursion(array, 5);
    printf("\n=> %d", pos);
    printf("\n");

    traverse_array_int(array);
    free(array->arr);
    free(array);
    return 0;
}
