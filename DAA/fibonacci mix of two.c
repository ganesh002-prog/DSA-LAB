
#include <stdio.h>
int fib(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n, i;
    int a = 0, b = 1, next;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    printf("\nFibonacci using Iterative method:\n");
    for (i = 0; i < n; i++)
    {
        if (i <= 1)
            next = i;
        else
        {
            next = a + b;
            a = b;
            b = next;
        }
        printf("%d ", next);
    }

    printf("\n\nFibonacci using Recursive method:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", fib(i));
    }

    return 0;
} 
