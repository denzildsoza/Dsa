#include <math.h>
#include "../headers.h"

int recursions = -1;
int to_binary(int num)
{
    recursions++;
    if (num == 0)
    {
        return num;
    }

    return (pow(10, recursions) * (num % 2)) + to_binary(num / 2);
}

int main(int argc, char const *argv[])
{
    int number = 69;
    printf("%d", to_binary(number));
    return 0;
}
