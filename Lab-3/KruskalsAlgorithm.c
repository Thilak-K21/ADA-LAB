//This is Kruskals Algorithm

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int parent[MAX];

int find(int i)
{
    while (parent[i] != i)
    {
        i = parent[i];
    }
    return i;
}

void union_sets(int i, int j)
{
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int main()
{
    int n, i, j, u, v;
    int a, b, weight;
    int min, mincost = 0;
    int cost[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (0 if no edge):\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 9999;
        }
    }

    for (i = 0; i < n; i++)
        parent[i] = i;

    int ne = 0;
    printf("\nEdge \tWeight\n");

    while (ne < n - 1)
    {
        min = 9999;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (find(i) != find(j) && cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        union_sets(u, v);
        printf("%d - %d\t%d\n", a, b, min);
        mincost += min;
        ne++;
    }

    printf("\nMinimum cost = %d\n", mincost);

    return 0;
}
