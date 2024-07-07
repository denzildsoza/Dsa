#include <stdio.h>
#include <stdlib.h>
#include "../abstract_data_types/array/array_int.c"

void merge_sorted_array(Array *array, int start, int end, int mid)
{
    printf("start=> %d mid=> %d end=> %d \n", start, mid, end);
    int i = start;
    int end_i = mid;
    int j = mid + 1;
    int end_j = end;
    Array *copy = create_array_int(end + 1);
    for (int ii =start; ii <= end; ii++)
    {
        push_array_int(copy, array->arr[ii]);
    }
    for (int k = 0; k <= copy->top; k++)
    {
        if (j > end_j)
        {
            array->arr[k] = copy->arr[i];
            i++;
            continue;
        }
        if (i > end_i)
        {
            array->arr[k] = copy->arr[j];
            j++;
            continue;
        }
        if (copy->arr[i] <= copy->arr[j])
        {
            array->arr[k] = copy->arr[i];
            i++;
        }
        else
        {
            array->arr[k] = copy->arr[j];
            j++;
        }
    }
}

void merge_sort(Array *array, int start, int end)
{

    if (start < end)
    {
        int mid = (start + end) / 2;
        merge_sort(array, start, mid);
        merge_sort(array, mid + 1, end);
        merge_sorted_array(array, start, end, mid);
    }
}

int main(int argc, char const *argv[])
{

    Array *array = create_array_int(50);

    push_array_int(array, 27);
    push_array_int(array, 7);
    push_array_int(array, 12);
    push_array_int(array, 2);
    push_array_int(array, 78);
    push_array_int(array, 41);
    push_array_int(array, 12);
    push_array_int(array, 8);
    push_array_int(array, 100);
    push_array_int(array, 12);

    // merge_sorted_array(array, 0, array->top, (0 + array->top) / 2);
    merge_sort(array, 0, array->top);

    traverse_array_int(array);

    free(array->arr);
    free(array);
    return 0;
}


// {
//     printf("start=> %d mid=> %d end=> %d \n", start, mid, end);
//     int i = start;
//     int end_i = mid;
//     int j = mid + 1;
//     int end_j = end;
//     Array *copy = create_array_int(end + 1);
//     for (int ii = 0; ii <= array->top; ii++)
//     {
//         push_array_int(copy, array->arr[ii]);
//     }
//     for (int k = 0; k <= copy->top; k++)
//     {
//         if (j > end_j)
//         {
//             array->arr[k] = copy->arr[i];
//             i++;
//             continue;
//         }
//         if (i > end_i)
//         {
//             array->arr[k] = copy->arr[j];
//             j++;
//             continue;
//         }
//         if (copy->arr[i] <= copy->arr[j])
//         {
//             array->arr[k] = copy->arr[i];
//             i++;
//         }
//         else
//         {
//             array->arr[k] = copy->arr[j];
//             j++;
//         }
//     }
// }