#include <stdio.h>
int main()
{
    int n, i;
    int a = 0, b = 1, next;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci Series using Iterative Method:\n");

    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            next = 0;
        }
        else if (i == 1)
        {
            next = 1;
        }
        else
        {
            next = a + b;
            a = b;
            b = next;
        }
        printf("%d ", next);
    }

    return 0;
}

