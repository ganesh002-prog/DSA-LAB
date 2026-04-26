#include <stdio.h>

void firstFit(int items[], int n, int cap)
{
    int bin[50];
    int bins = 0;
    int i, j;

    for(i = 0; i < 50; i++)
    {
        bin[i] = cap;
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < bins; j++)
        {
            if(items[i] <= bin[j])
            {
                bin[j] = bin[j] - items[i];
                break;
            }
        }

        if(j == bins)
        {
            bin[bins] = cap - items[i];
            bins++;
        }
    }

    printf("Total bins used = %d\n", bins);
}

int main()
{
    int n, cap, i;
    int items[50];

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter capacity of bin: ");
    scanf("%d", &cap);

    printf("Enter item sizes:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &items[i]);
    }

    firstFit(items, n, cap);

    return 0;
}



output:
Enter number of items: 6
Enter capacity of bin: 10
Enter item sizes:
2
5
4
7
1
3
Total bins used = 3
