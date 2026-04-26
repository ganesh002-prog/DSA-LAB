#include <stdio.h>

#define V 5

int minKey(int key[], int visited[])
{
    int min = 9999, index = 0, i;

    for(i = 0; i < V; i++)
    {
        if(visited[i] == 0 && key[i] < min)
        {
            min = key[i];
            index = i;
        }
    }
    return index;
}

void primMST(int graph[V][V])
{
    int parent[V];
    int key[V];
    int visited[V];
    int i, count, v, total = 0;

    for(i = 0; i < V; i++)
    {
        key[i] = 9999;
        visited[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for(count = 0; count < V - 1; count++)
    {
        int u = minKey(key, visited);
        visited[u] = 1;

        for(v = 0; v < V; v++)
        {
            if(graph[u][v] && visited[v] == 0 && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printf("Edges in MST:\n");

    for(i = 1; i < V; i++)
    {
        printf("%d - %d = %d\n", parent[i], i, graph[i][parent[i]]);
        total = total + graph[i][parent[i]];
    }

    printf("Total cost = %d\n", total);
}

int main()
{
    int graph[V][V] = {
        {0,2,3,0,0},
        {2,0,5,3,0},
        {3,5,0,0,4},
        {0,3,0,0,2},
        {0,0,4,2,0}
    };

    primMST(graph);

    return 0;
}






output:
Edges in MST:
0 - 1 = 2
0 - 2 = 3
1 - 3 = 3
3 - 4 = 2
Total cost = 10
