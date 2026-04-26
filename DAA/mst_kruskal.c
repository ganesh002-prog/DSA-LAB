#include <stdio.h>

#define V 5
#define E 6

int parent[V];

int find(int x)
{
    while(parent[x] != x)
        x = parent[x];
    return x;
}

void unionSet(int a, int b)
{
    int x = find(a);
    int y = find(b);
    parent[x] = y;
}

void sort(int edge[E][3])
{
    int i, j, k, temp;

    for(i = 0; i < E - 1; i++)
    {
        for(j = 0; j < E - i - 1; j++)
        {
            if(edge[j][2] > edge[j + 1][2])
            {
                for(k = 0; k < 3; k++)
                {
                    temp = edge[j][k];
                    edge[j][k] = edge[j + 1][k];
                    edge[j + 1][k] = temp;
                }
            }
        }
    }
}

int main()
{
    int edge[E][3] = {
        {0,1,2},
        {0,2,3},
        {1,2,5},
        {1,3,3},
        {2,4,4},
        {3,4,2}
    };

    int i, count = 0, cost = 0;

    for(i = 0; i < V; i++)
        parent[i] = i;

    sort(edge);

    printf("Edges in MST:\n");

    for(i = 0; i < E; i++)
    {
        int u = edge[i][0];
        int v = edge[i][1];
        int w = edge[i][2];

        if(find(u) != find(v))
        {
            printf("%d - %d = %d\n", u, v, w);
            unionSet(u, v);
            cost = cost + w;
            count++;
        }

        if(count == V - 1)
            break;
    }

    printf("Total cost = %d\n", cost);

    return 0;
}


output:
Edges in MST:
0 - 1 = 2
3 - 4 = 2
0 - 2 = 3
1 - 3 = 3
Total cost = 10
