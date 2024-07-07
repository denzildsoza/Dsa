#include <stdio.h>
#include <stdlib.h>

int fibonachi_sequence(int n)
{
    if (n == 1 || n == 0)
    {
        return n;
    }
    else
    {
        return (fibonachi_sequence(n - 1) + fibonachi_sequence(n - 2));
    }
}

int main(int argc, char const *argv[])
{
    int  fib = fibonachi_sequence(1000);
    printf("%d",fib);
    return 0;
}
