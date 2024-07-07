#include <stdio.h>
#include <stdlib.h>

int find_sum(int num)
{
    if (num == 0)
    {
        return num;
    }
    return num + find_sum(num - 1);
}

int main(int argc, char const *argv[])
{
    int sum = find_sum(50);
    printf("\nthe sum is =%d\n", sum);
    return 0;
}
