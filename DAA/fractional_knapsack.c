#include <stdio.h>

struct item
{
    int weight;
    int profit;
    float ratio;
};

int main()
{
    struct item a[50], temp;
    int n, i, j;
    float cap, total = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter weight and profit of item %d: ", i + 1);
        scanf("%d%d", &a[i].weight, &a[i].profit);
        a[i].ratio = (float)a[i].profit / a[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%f", &cap);

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(a[j].ratio < a[j + 1].ratio)
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    for(i = 0; i < n; i++)
    {
        if(cap >= a[i].weight)
        {
            total = total + a[i].profit;
            cap = cap - a[i].weight;
        }
        else
        {
            total = total + (a[i].ratio * cap);
            break;
        }
    }

    printf("Maximum profit = %.2f\n", total);

    return 0;
}






output:
Enter number of items: 3
Enter weight and profit of item 1: 10 60
Enter weight and profit of item 2: 20 100
Enter weight and profit of item 3: 30 120
Enter knapsack capacity: 50
Maximum profit = 240.00
